


def count_letters(text):
    # letters = 0
    # for i in text:
    # if isalpha(text[i]):
    #     letters += 1
    return sum(1 for char in text if char.isalpha()) # conta as letras / isalpha() verifica se é uma letra


def count_words(text):
    return len(text.split()) # conta as palavras / split() divide a string em uma lista de palavras


def count_sentences(text):
    return text.count("!") + text.count(".") + text.count("?") # conta as sentenças / count() conta quantas vezes um caractere aparece na string


def main():
    text = input("Text: ")

    letters = count_letters(text)

    words = count_words(text)

    sentences = count_sentences(text)

    L = (letters / words) * 100

    S = (sentences / words) * 100

    index = 0.0588 * L - 0.296 * S - 15.8

    grade = round(index)

    if (grade >= 1 and grade <= 15):
        print(f"Grade {grade}")

    elif grade >= 16:
        print("Grade 16+")

    elif grade < 1:
        print("Before Grade 1")


main()
