import csv
import sys


def main():

    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        print("Error I was expecting 3 arguments")
        sys.exit(1)
    # TODO: Read database file into a variable

    rows = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)
    # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2]) as file:
        dna = file.read()

    # TODO: Find longest match of each STR in DNA sequence

    fieldnames = reader.fieldnames
    STRs = fieldnames[1:]  # apartir do 1 pois não queremos o elemento 0 (nome)
    resultados = {}
    for str_atual in STRs:
        resultados[str_atual] = longest_match(dna, str_atual)

    # TODO: Check database for matching profiles

    encontrado = False
    for row in rows:
        # c comparar resultado [agat] com [agat]
        match = True
        for str_atual in STRs:
            if resultados[str_atual] != int(row[str_atual]):
                match = False
        if match:
            print(row["name"])
            encontrado = True
            break
    if not encontrado:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
