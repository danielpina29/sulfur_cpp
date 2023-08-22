#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <vector>

#include "tokenizer.hpp"
#include "parser.hpp"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect usage." << std::endl;
        std::cerr << "Correct usage: sulfurc <input.sul>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string contents;
    {
        std::stringstream contents_stream;
        std::ifstream file;
        file.open(argv[1], std::ios::in);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << argv[1] << std::endl;
            return EXIT_FAILURE;
        }
        contents_stream << file.rdbuf();
        contents = contents_stream.str();
    }

    //Tokenizer tokenizer(contents);
    //std::vector<Token> tokens = tokenizer.tokenize();

    int val = 18;
    int *ptr = &val;
    int **final = &ptr;


    std::cout << "Final = " << **final << std::endl;
    std::cout << "ptr = " << ptr << std::endl;
    std::cout << "val -> " << &val << std::endl;

    return EXIT_SUCCESS;
}


