#ifndef Expr_Tree_Builder_Exists
#define Expr_Tree_Builder_Exists

#include "Expr_Builder.h"
#include "Expr_Command.h"
#include "Binary_Expr_Command.h"
#include "Stack.h"
#include "Calculator.h"

class Expr_Tree_Builder : public Expr_Builder {
public:
	Expr_Tree_Builder ();
	~Expr_Tree_Builder ();
	void build_number (int num);
	void build_add_operator ();
	void build_subtract_operator ();
	void build_multiply_operator ();
	void build_divide_operator ();
	void build_modulus_operator ();
	void build_open_parenthesis ();
	void build_close_parenthesis ();
	Expr_Command * get_expression ();
private:
	Stack<Calculator *> expressions;
};

#endif
