#include "Add_Command.h"
#include "Expr_Command_Visitor.h"

Add_Command::Add_Command ()
{ }

int Add_Command::eval (){
   return this->left_->eval()+this->right_->eval ();
}

int Add_Command::precedence() {
   return 0;
}

void Add_Command::printName() {
   std::cout<<"Add Command"<<std::endl;
   std::cout<<"Left: "<<std::endl;
   left_->printName();
   std::cout<<"Right: "<<std::endl;
   right_->printName();
}

void Add_Command::accept(Expr_Command_Visitor * visitor) {
   visitor->visit_add_operator(this);
}
