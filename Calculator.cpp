#include "Calculator.h"

Calculator::Calculator()
: nodes_ (Stack<Expr_Command *>()),
ops_ (Stack<Binary_Expr_Command *>())
{ }

Calculator::~Calculator () {
   try {
      Expr_Command * n = get_expression();
      delete n;
   } catch (std::exception & e) {
   }
}

void Calculator::addOp (Binary_Expr_Command * op) {
   if (!ops_.is_empty() && ops_.top()->precedence() >= op->precedence()) {
      get_expression();
   }
   ops_.push(op);
}

void Calculator::addCommand (Expr_Command * node) {
   nodes_.push(node);
}

void Calculator::print() {
   std::cout<<"Calculator: "<<std::endl;
   nodes_.top()->printName();
}

Expr_Command * Calculator::get_expression () {
   while (!ops_.is_empty()) {
      ops_.top()->setRight(nodes_.top());
      nodes_.pop();
      ops_.top()->setLeft(nodes_.top());
      nodes_.pop();
      nodes_.push(ops_.top());
      ops_.pop();
   }
   return nodes_.top();
}
