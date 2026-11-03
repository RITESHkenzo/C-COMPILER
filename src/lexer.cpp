#include "lexer.hpp"
#include <cctype>

Lexer::Lexer(const std::string& sourceCode)
    : source(sourceCode), position(0) {
}

Token Lexer::nextToken() {

    while (position < source.length() &&
           std::isspace(static_cast<unsigned char>(source[position]))) {
        position++;
    }

    if (position >= source.length()) {
        return {TokenType::END_OF_FILE, ""};
    }

    char current = source[position];

// Identifiers and keywords
if (std::isalpha(static_cast<unsigned char>(current)) || current == '_') {

    std::string word;

    while (position < source.length() &&
           (std::isalnum(static_cast<unsigned char>(source[position])) ||
            source[position] == '_')) {

        word += source[position];
        position++;
    }

    if (word == "int") {
        return {TokenType::INT, word};
    }

    if (word == "return") {
        return {TokenType::RETURN, word};
    }

    return {TokenType::IDENTIFIER, word};
}
// Integer literals
if (std::isdigit(static_cast<unsigned char>(current))) {

    std::string number;

    while (position < source.length() &&
           std::isdigit(static_cast<unsigned char>(source[position]))) {

        number += source[position];
        position++;
    }

    return {TokenType::INTEGER_LITERAL, number};
}
// Symbols
switch (current) {
    case '(':
        position++;
        return {TokenType::LEFT_PAREN, "("};

    case ')':
        position++;
        return {TokenType::RIGHT_PAREN, ")"};

    case '{':
        position++;
        return {TokenType::LEFT_BRACE, "{"};

    case '}':
        position++;
        return {TokenType::RIGHT_BRACE, "}"};

    case ';':
        position++;
        return {TokenType::SEMICOLON, ";"};
}
position++;
return {TokenType::UNKNOWN, std::string(1, current)};
}