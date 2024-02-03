#include <iostream>
#include <fstream>
#include <string>

#include "./lexer/lexer.hpp"

int main(int argc, char* argv[]) {

    std::string fileTxt = "";

    if(argc != 2) {
        std::cerr << "Incorrect usage. Correct useage: " << std::endl;
        std::cerr << "language <file.lan>" << std::endl;
        return -1;
    }

    std::ifstream inputFile(argv[1]);
    getline(inputFile, fileTxt, '\0');

    std::cout << fileTxt << std::endl;


    std::vector<token> tokens = tokenize(fileTxt);

    for(token t : tokens) {
        std::cout << t.toStr() << std::endl;
    }

}