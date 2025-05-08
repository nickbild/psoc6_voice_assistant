# Local LLM Voice Assistant

I previous built an offline, LLM-based voice assistant ([details here](https://github.com/nickbild/local_llm_assistant)). It works quite well, but it has one problem — you have to press a button to ask it a question. That is inconvenient and does not go well with the whole concept of a voice assistant.

I do not want to bog the system down with continually looking for a wakeword, so I decided to upgrade my voice assistant with an Infineon PSoC 6 Artificial Intelligence Evaluation Kit. In this way, the PSoC 6 can continually watch for a wakeword, and only trigger the voice assistant to jump into action when I am ready to make a request.

The build of the voice assistant is already [documented here](https://github.com/nickbild/local_llm_assistant), so I won't cover that again. I will just note that the `chatbot.py` script needs to be updated with [this version](https://github.com/nickbild/psoc6_voice_assistant/blob/main/chatbot.py) to interact with the PSoC 6, rather than a push button. That said, I will focus on how I got the PSoC 6 to do wakeword detection for the voice assistant.

