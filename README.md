# Local LLM Voice Assistant

I previous built an offline, LLM-based voice assistant ([details here](https://github.com/nickbild/local_llm_assistant)). It works quite well, but it has one problem — you have to press a button to ask it a question. That is inconvenient and does not go well with the whole concept of a voice assistant.

I do not want to bog the system down with continually looking for a wakeword, so I decided to upgrade my voice assistant with an Infineon PSoC 6 Artificial Intelligence Evaluation Kit. In this way, the PSoC 6 can continually watch for a wakeword, and only trigger the voice assistant to jump into action when I am ready to make a request.

The build of the voice assistant is already [documented here](https://github.com/nickbild/local_llm_assistant), so I won't cover that again. I will just note that the `chatbot.py` script needs to be updated with [this version](https://github.com/nickbild/psoc6_voice_assistant/blob/main/chatbot.py) to interact with the PSoC 6, rather than a push button. That said, I will focus on how I got the PSoC 6 to do wakeword detection for the voice assistant. But first, here is a demo of the project in action:

<a href="https://www.youtube.com/watch?v=sobiO6CeT20">![](https://raw.githubusercontent.com/nickbild/psoc6_voice_assistant/refs/heads/main/media/full_setup.jpg)</a>

## Building a Machine Learning Model for the PSoC 6

First, make sure that your dev board has already been flashed with the streaming firmware. There is additional information about that [here](https://developer.imagimob.com/getting-started/infineon-ai-evaluation-kit). Once that has been sorted out, you will need to install and launch DEEPCRAFT Studio. Create a [new data collection project](https://developer.imagimob.com/data-preparation/data-collection/data-collection-using-new-streaming-firmware), then configure it to collect data from the microphone using the drag-and-drop graphical interface. Here is one of my recording sessions after I lableled the data:

![](https://raw.githubusercontent.com/nickbild/psoc6_voice_assistant/refs/heads/main/media/data_collection.png)

Once you have the data prepared, you create a new classification project, then add the data to it:

![](https://raw.githubusercontent.com/nickbild/psoc6_voice_assistant/refs/heads/main/media/add_data.png)

Be sure to click the `Redistribute Sets...` button to split the data between training, validation, and testing sets.

You will also need to select a model to perform the classifications. I chose a 1D convolutional LSTM network.

![](https://raw.githubusercontent.com/nickbild/psoc6_voice_assistant/refs/heads/main/media/model.png)

When ready, click the `Start New Training Job...` button. This job will run in the cloud, so it will not be eating up resources on your own machine, and you do not need to install any machine learning frameworks.

After the training process finishes, you will be given metrics to help you evaluate which model works best for your application. Once you make your selection, download the `.h5` model file.

![](https://raw.githubusercontent.com/nickbild/psoc6_voice_assistant/refs/heads/main/media/training_results.png)

Now use the `Code Gen` tab to create representations of the model that can be deployed to the hardware.

![](https://raw.githubusercontent.com/nickbild/psoc6_voice_assistant/refs/heads/main/media/code_gen.png)

Finally, pivot over to ModusToolbox. Create a new project based on this [example project](https://bitbucket.org/imagimob/imagimob-deploy-code-example-psoc-edge/src/main/). After that, replace the files in the `models` folder of your new project with the `model.c` and `model.h` files produced by the `Code Gen` step. Now you can click on `Build Project` (you can also make any necessary code edits first in the Eclipse IDE).

![](https://raw.githubusercontent.com/nickbild/psoc6_voice_assistant/refs/heads/main/media/eclipse.png)

The last step is to click the button to deply your project. The predictions will be output via serial over USB, so I read that via my voice assistant Python script to determine when the wakeword was spoken.

That's it! You've got your own offline LLM-based voice assistant, with this little board doing the tough job of continuous wakeword detection:

![](https://raw.githubusercontent.com/nickbild/psoc6_voice_assistant/refs/heads/main/media/dev_board.jpg)

## About the Author

[Nick A. Bild, MS](https://nickbild79.firebaseapp.com/#!/)
