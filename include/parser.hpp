#ifndef PARSER_HPP
#define PARSER_HPP

#include <memory>

#include "lexer.hpp"
#include "ast.hpp"

class Parser {
private:
    Lexer& lexer;
    Token currentToken;

    void advance();

    std::unique_ptr<Expression> parsePrimary();
    std::unique_ptr<Expression> parseMultiplicative();
    std::unique_ptr<Expression> parseAdditive();

public:
    Parser(Lexer& lexer);

    std::unique_ptr<Expression> parseExpression();
};

#endif