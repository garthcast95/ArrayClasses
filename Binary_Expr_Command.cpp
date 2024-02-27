#include "Binary_Expr_Command.h"

Binary_Expr_Command::Binary_Expr_Command ()
: left_ (nullptr),
right_ (nullptr) 
{ }

Binary_Expr_Command::Binary_Expr_Command (Expr_Command * left, Expr_Command * right)
: left_ (left),
right_ (right) 
{ }

Binary_Expr_Command::~Binary_Expr_Command () {
	delete this->left_;
	delete this->right_;
}

void Binary_Expr_Command::setLeft (Expr_Command * left) {
	this->left_ = left;
}


void Binary_Expr_Command::setRight (Expr_Command * right) {
	this->right_ = right;
}
Expr_Command * Binary_Expr_Command::getLeft () {
	return this->left_;
}
Expr_Command * Binary_Expr_Command::getRight () {
	return this->right_;
}
