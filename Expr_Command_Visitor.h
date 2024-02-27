#ifndef EXPR_COMMAND_VISITOR_H
#define EXPR_COMMAND_VISITOR_H

class Binary_Expr_Command;
class Add_Command;
class Subtract_Command;
class Multiply_Command;
class Divide_Command;
class Modulus_Command;
class Number_Command;

class Expr_Command_Visitor {
public:
	~Expr_Command_Visitor();
	virtual void visit_add_operator (Add_Command * add) = 0;
	virtual void visit_subtract_operator (Subtract_Command * subtract) = 0;
	virtual void visit_multiply_operator (Multiply_Command * mult) = 0;
	virtual void visit_divide_operator (Divide_Command * divide) = 0;
	virtual void visit_modulus_operator(Modulus_Command * mod) = 0;
	virtual void visit_number (Number_Command * num) = 0;
};

#endif
