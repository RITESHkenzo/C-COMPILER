#ifndef AST_HPP
#define AST_HPP

#include <memory>

enum class BinaryOperator {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

class Expression {
public:
    virtual ~Expression() = default;
};

class IntegerExpression : public Expression {
public:
    int value;

    IntegerExpression(int value)
        : value(value) {
    }
};

class BinaryExpression : public Expression {
public:
    BinaryOperator op;

    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

    BinaryExpression(
        BinaryOperator op,
        std::unique_ptr<Expression> left,
        std::unique_ptr<Expression> right
    )
        : op(op),
          left(std::move(left)),
          right(std::move(right)) {
    }
};

#endif