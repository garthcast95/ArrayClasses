#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Expr_Command_Visitor.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Number_Command.h"
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"

using namespace std;

int create_expression(vector <string> & equStr)
{
   int num;
   Expr_Tree_Builder etb = Expr_Tree_Builder();

   for (string ss : equStr) {
      try {
         num = stoi(ss);
         etb.build_number(num);
      } catch (invalid_argument & e) {
         if (ss == "+") {
            etb.build_add_operator();
         } else if (ss == "-") {
            etb.build_subtract_operator();
         } else if (ss == "*") {
            etb.build_multiply_operator();
         } else if (ss == "/") {
            etb.build_divide_operator();
         } else if (ss == "%") {
            etb.build_modulus_operator();
         } else if (ss == "(") {
            etb.build_open_parenthesis();
         } else if (ss == ")") {
            etb.build_close_parenthesis();
         } else {
            cout << "Invalid Expression" << endl;
            equStr.clear();
            return 0;
         }
      }
   }
   equStr.clear();

   Expr_Command * expr = etb.get_expression();
   Eval_Expr_Tree * eval = new Eval_Expr_Tree();
   expr->accept(eval);
   int res = eval->result();
   delete eval;
   return res;
}

int main()
{
   string s;
   Stack <string> equ = Stack<string>();
   vector<string> equv{};
   string delim = " ";
   int pos;

   while (true) {
      cout << "Enter the expression:" << endl;
      getline(cin, s);
      if (s == "QUIT") break;

      while ((pos = s.find(delim)) != (int) string::npos) {
         equv.push_back(s.substr(0, pos));
         s.erase(0, pos + delim.length());
      }
      equv.push_back(s);

      cout << create_expression(equv) << endl;
   }
}
