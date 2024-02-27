#ifndef EVAL_EXPR_TREE_H_EXISTS
#define EVAL_EXPR_TREE_H_EXISTS

#include "Expr_Command_Visitor.h"

class Eval_Expr_Tree : public Expr_Command_Visitor {
public:
	Eval_Expr_Tree();
	virtual ~Eval_Expr_Tree();
	void visit_add_operator (Add_Command * add);
	void visit_subtract_operator(Subtract_Command * subtract);
	void visit_multiply_operator (Multiply_Command * mult);
	void visit_divide_operator (Divide_Command * divide);
	void visit_modulus_operator(Modulus_Command * mod);
	void visit_number (Number_Command * num);
	int result (void) const;
private:
	int result_;
};

#endif
