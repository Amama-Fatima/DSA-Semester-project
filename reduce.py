import csv

input_file = "FinalBooks.csv"
output_file = "ReducedBooks.csv"
num_lines_to_keep = 1000

with open(input_file, "r", encoding="utf-8") as infile, open(output_file, "w", encoding="utf-8", newline='') as outfile:
    reader = csv.reader(infile)
    writer = csv.writer(outfile)

    # Copy header
    header = next(reader)
    writer.writerow(header)

    # Copy first 1000 lines
    for _ in range(num_lines_to_keep):
        try:
            line = next(reader)
            writer.writerow(line)
        except StopIteration:
            break

print(f"Reduced dataset saved to {output_file}")
