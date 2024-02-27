#include "Eval_Expr_Tree.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Number_Command.h"

Eval_Expr_Tree::Eval_Expr_Tree()
: result_ (0) { }

Eval_Expr_Tree::~Eval_Expr_Tree() { }

void Eval_Expr_Tree::visit_add_operator (Add_Command * add) {
	add->getLeft()->accept(this);
	int temp = result_;
	add->getRight()->accept(this);
	result_ = temp + result_;
}

void Eval_Expr_Tree::visit_subtract_operator (Subtract_Command * subtract) {
	subtract->getLeft()->accept(this);
	int temp = result_;
	subtract->getRight()->accept(this);
	result_ = temp - result_;

}

void Eval_Expr_Tree::visit_multiply_operator (Multiply_Command * mult) {
	mult->getLeft()->accept(this);
	int temp = result_;
	mult->getRight()->accept(this);
	result_ = temp * result_;
}
void Eval_Expr_Tree::visit_divide_operator (Divide_Command * divide) {
	divide->getLeft()->accept(this);
	int temp = result_;
	divide->getRight()->accept(this);
	result_ = temp / result_;
}
void Eval_Expr_Tree::visit_modulus_operator (Modulus_Command * mod) {
	mod->getLeft()->accept(this);
	int temp = result_;
	mod->getRight()->accept(this);
	result_ = temp % result_;
}

void Eval_Expr_Tree::visit_number (Number_Command * num) {
	result_ = num->getVal();
}

int Eval_Expr_Tree::result () const {
	return result_;
}
