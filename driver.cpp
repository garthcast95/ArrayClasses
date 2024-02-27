#include <iostream>

#include "Array.h"
#include "Stack.h"

#include "Expr_Command.h"

#include "Stack_Expr_Command_Factory.h"
#include "Calculator.h"

int main()
{
	std::string infix;

	Calculator calc;

	while (true) {
		std::cout << "Enter expression: ";
		getline(std::cin, infix);

		if (infix == "QUIT" || infix == "quit") {
			break;
		} else {
            // COMMENT I think you have some memory leaks since you are not deleting
            // the created commands between expressions.
            // commands are getting deleted in the calculator.cpp inside evaluate_expression function

			Stack<int> result;
			Stack_Expr_Command_Factory factory(result);
			Array<Expr_Command *> postfix;

			if (calc.infix_to_postfix(infix, factory, postfix)) {
				std::cout << result.top() << "\n"; // Result top contains the evaluated result for the given expression
			} else {
				std::cout << "Something went wrong!!!\n";
			}
		}
	}
	return 0;
}
