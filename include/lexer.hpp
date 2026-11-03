#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include "token.hpp"

class Lexer {
private:
    std::string source;
    std::size_t position;

public:
    Lexer(const std::string& sourceCode);

    Token nextToken();
};

#endif