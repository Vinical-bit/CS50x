from openai import OpenAI

client = OpenAI()

response = client.reponses.create(
    input="In one sentence, what is CS50?"
    model="gpt-4o"
)

print( responses.output_text)

