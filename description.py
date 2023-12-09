import csv
import random

def generate_random_description():
    descriptions = [
        "A thrilling journey through a magical world.",
        "An insightful exploration of complex themes.",
        "A heartwarming tale of love and adventure.",
        "A captivating story of intrigue and suspense.",
        "A groundbreaking work of science fiction.",
        "A riveting historical narrative with compelling characters.",
        "An imaginative and beautifully written fantasy.",
        "A thought-provoking exploration of human nature.",
        "A spellbinding mystery with unexpected twists.",
        "An inspiring story of courage and determination."
    ]
    return random.choice(descriptions)



def add_descriptions_to_csv(input_file, output_file):
    with open(input_file, mode='r', newline='', encoding='utf-8') as infile, \
         open(output_file, mode='w', newline='', encoding='utf-8') as outfile:
        reader = csv.reader(infile)
        writer = csv.writer(outfile)

        header = next(reader)  # Assuming first row is header
        header.append('Description')  # Add Description column
        writer.writerow(header)

        for row in reader:
            row.append(generate_random_description())
            writer.writerow(row)




add_descriptions_to_csv('Book Data - Top-100 Trending Books.csv', 'Book Data - Top-100 Trending Books with Descriptions.csv' )
