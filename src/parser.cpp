#include "parser.hpp"

#include <stdexcept>
#include <string>

Parser::Parser(Lexer& lexer)
    : lexer(lexer) {
    advance();
}

void Parser::advance() {
    currentToken = lexer.nextToken();
}

std::unique_ptr<Expression> Parser::parsePrimary() {

    if (currentToken.type == TokenType::INTEGER_LITERAL) {

        int value = std::stoi(currentToken.value);

        advance();

        return std::make_unique<IntegerExpression>(value);
    }

    throw std::runtime_error(
        "Expected an expression, found: " + currentToken.value
    );
}

std::unique_ptr<Expression> Parser::parseMultiplicative() {
    return parsePrimary();
}

std::unique_ptr<Expression> Parser::parseAdditive() {
    return parseMultiplicative();
}

std::unique_ptr<Expression> Parser::parseExpression() {
    return parseAdditive();
}