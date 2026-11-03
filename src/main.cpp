#include <iostream>
#include <string>
#include <fstream>
#include "lexer.hpp"

std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::INT:
            return "INT";

        case TokenType::RETURN:
            return "RETURN";

        case TokenType::IDENTIFIER:
            return "IDENTIFIER";

        case TokenType::INTEGER_LITERAL:
            return "INTEGER_LITERAL";

        case TokenType::LEFT_PAREN:
            return "LEFT_PAREN";

        case TokenType::RIGHT_PAREN:
            return "RIGHT_PAREN";

        case TokenType::LEFT_BRACE:
            return "LEFT_BRACE";

        case TokenType::RIGHT_BRACE:
            return "RIGHT_BRACE";

        case TokenType::SEMICOLON:
            return "SEMICOLON";

        case TokenType::END_OF_FILE:
            return "END_OF_FILE";

        case TokenType::UNKNOWN:
            return "UNKNOWN";
        case TokenType::PLUS:
            return "PLUS";

        case TokenType::MINUS:
            return "MINUS";

        case TokenType::STAR:
            return "STAR";

        case TokenType::SLASH:
            return "SLASH";
        case TokenType::ASSIGN:
            return "ASSIGN";

        case TokenType::EQUAL_EQUAL:
            return "EQUAL_EQUAL";

        case TokenType::NOT_EQUAL:
            return "NOT_EQUAL";

        case TokenType::LESS:
            return "LESS";

        case TokenType::LESS_EQUAL:
            return "LESS_EQUAL";

        case TokenType::GREATER:
            return "GREATER";

        case TokenType::GREATER_EQUAL:
            return "GREATER_EQUAL";
        }

    return "UNKNOWN";
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
    std::cerr << "Usage: ccompiler <file.c>\n";
    return 1;
}

std::ifstream file(argv[1]);

if (!file.is_open()) {
    std::cerr << "Error: could not open file: "
              << argv[1] << '\n';
    return 1;
}

std::string source(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
);

    Lexer lexer(source);

    while (true) {

        Token token = lexer.nextToken();

        std::cout
            << tokenTypeToString(token.type)
            << " : "
            << token.value
            << '\n';

        if (token.type == TokenType::END_OF_FILE) {
            break;
        }
    }

    return 0;
}