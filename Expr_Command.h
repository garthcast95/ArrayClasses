#ifndef EXPR_COMMAND_H
#define EXPR_COMMAND_H

class Expr_Command {
public:
	virtual ~Expr_Command() = default;
	virtual bool execute() = 0;
	virtual int getPrecedence() const;
};

#endif // EXPR_COMMAND_H
