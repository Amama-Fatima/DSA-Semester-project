import pandas as pd 

df = pd.read_csv('FinalBooks.csv')

columns_to_remove = ['numRatings']

df.drop(columns_to_remove, inplace=True, axis=1)

df.to_csv('FinalBooks.csv', index=False)

# import pandas as pd

# def print_line_from_csv_pandas(file_path, line_number):
#     try:
#         # Read the specific line
#         df = pd.read_csv(file_path, skiprows=line_number - 1, nrows=1, header=None)
#         for i, field in enumerate(df.iloc[0]):
#             print(f"Field {i + 1}: {field}")
#     except Exception as e:
#         print(f"Error reading line {line_number}: {e}")

# csv_file_path = 'books_1.Best_Books_Ever copy.csv'
# line_to_inspect = 1592

# print_line_from_csv_pandas(csv_file_path, line_to_inspect)
