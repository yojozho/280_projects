#include "csvstream.h"
#include <iostream>
#include <string>
#include <utility>
#include <set>
#include <map>

class Classifier {
public:
    Classifier(csvstream &csv_in) {
        std::map<std::string, std::string> row;
        while (csv_in >> row) {
            insert_words(row);
        }
    }
    void insert_words(std::map<std::string, std::string> &row) {
        unique = unique_words(row["contents"]);
        std::set<std::string>::iterator it = unique.begin();
        while (it != unique.end()) {
            
        }
    }
    
    // EFFECTS: Returns a set containing the unique "words" in the original
    //          string, delimited by whitespace.
    std::set<std::string> unique_words(const std::string &str) {
     std::istringstream source(str);
     std::set<std::string> words;
     std::string word;

     while (source >> word) {
       words.insert(word);
     }
     return words;
    }
    
    void train_print_posts(csvstream &csv_in) {
        
    }
    
private:
    int train_posts = 0;
    std::set<std::string> unique;
    std::map<std::string, int> map_words;
    std::map<std::string, int> map_labels;
    std::map<std::pair<std::string, std::string>, int> map_both;

};

int main(int argc, char * argv[]) {
    std::cout.precision(3);
    
    //check arguments
    if (argc != 3 && argc != 4) {
        std::cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << std::endl;
        return 1;
    }
    else if (argc == 4) {
        std::string debug = argv[3];
        if (debug != "--debug" ) {
        std::cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << std::endl;
        return 1;
        }
    }
    
    //train
    try {
        csvstream csv_train(argv[1]);
        Classifier training(csv_train);
    } catch (const csvstream_exception &e1) {
        std::cout << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }
    
    //test
    try {
        csvstream csv_test(argv[2]);
        Classifier testing(csv_test);
    } catch (const csvstream_exception &e2) {
        std::cout << "Error opening file: " << argv[2] << std::endl;
        return 1;
    }
    
    
    
}
