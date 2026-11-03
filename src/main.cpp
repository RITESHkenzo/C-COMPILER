#include <iostream>
#include <string>

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
    }

    return "UNKNOWN";
}

int main() {

    std::string source = R"(
        int main() {
            return 42;
        }
    )";

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