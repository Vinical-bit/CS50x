words = set()

def check(word):
    return word.lower() in words

def load(dictionary):
    with open(dictionary) as file:
        words.update(file.read().splitlines) # splitlines() divide o arquivo em linhas e adiciona cada linha ao conjunto words
    return True

def size():
    return len(words)

def unload():
    return True