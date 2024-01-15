#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Genre {
    int bucket;
    string name;

    Genre(int bucket, string name) {
        this->bucket = bucket;
        this->name = name;
    }
};

class GenreHashTable{
    public:
        static const int bucket_size = 100;
        vector<vector<string>> table;
        
        GenreHashTable(): table(bucket_size) {} // the outer vector (rows) will be of size 100 and the inner vector (columns) will be of size 0 (empty) 
        int hashFunction(string& genre){
            int sum = 0;
            for(char c : genre){
                sum+= static_cast<int>(c);
            }

            return sum % bucket_size;
        }

        bool genreExists(string& genre) {
            int bucket = hashFunction(genre);
            for (const string& existingGenre : table[bucket]) {
                if (existingGenre == genre) {
                    return true; // Genre already exists in the table
                }
            }
            return false; // Genre does not exist in the table
        }

        void insertGenre(string& genre){
            if(!genreExists(genre)){

                int bucket = hashFunction(genre);
                table[bucket].push_back(genre);
            }
        }

        void printTable() {
            for (int i = 0; i < bucket_size; ++i) {
                if (!table[i].empty()) {
                    cout << "Bucket " << i << ": [";
                    for (size_t j = 0; j < table[i].size(); ++j) {
                        cout << table[i][j];
                        if (j < table[i].size() - 1) {
                            cout << ", ";
                        }
                    }
                    cout << "]" << endl;
                }
            }
        }
};