#include "Calculator.h"
#include "Stack.h"
#include <iostream>
#include <sstream>

bool
Calculator::infix_to_postfix(const std::string &infix, Expr_Command_Factory &factory, Array<Expr_Command *> &postfix) {
	std::istringstream input(infix); // Create a input stream parser
	std::string token;               // Current token in string/stream
	Expr_Command *cmd;               // Created command object
	Stack<Expr_Command *> temp;      // Stack to track the command

	size_t count = 0;
	while (!input.eof()) {
		if (count == postfix.size() - 1) {
			postfix.resize(2 * postfix.size()); // Increase the postfix array if it reached maximum size of the array
		}

        // COMMENT You are not handling parenthesis.
        // Tried to handle the parenthesis recursively calling the method as expression
        // within a parenthesis needs to be executed first.

		// Get the token and check it
		input >> token;
		if (token == "+") {
			cmd = factory.create_add_command();
		} else if (token == "-") {
			cmd = factory.create_subtract_command();
		} else if (token == "*") {
			cmd = factory.create_multiply_command();
		} else if (token == "/") {
			cmd = factory.create_divide_command();
		} else if (token == "(") {
			// When we encounter a bracket we will call infix to postfix again to
			// evaluate the expression inside the bracket

			// Create the newInfix string
			std::string newInfix;
			Stack<int> newResult;
			Stack_Expr_Command_Factory newInfixFactory(newResult);
			Array<Expr_Command*> newPostfix;

			int left_parenthesis_count = 0; // store the left parenthesis count inside current parenthesis

			while (!input.eof()) {
				input >> token;

				if (token == "(") {
					left_parenthesis_count++;
				}

				if (token == ")") { // Handle right parenthesis until we got a right parenthesis
					if (left_parenthesis_count == 0) {
						break;
					}

					left_parenthesis_count--;
				}

				newInfix.append(token + " ");
			}

			if (left_parenthesis_count) {
				// Parenthesis are not matched
				return false;
			}

			// Exclude the extra space
			newInfix = newInfix.substr(0, newInfix.length() - 1);

			if (newInfix.empty() || !infix_to_postfix(newInfix, newInfixFactory, newPostfix)) {
				return false;
			}

			// insert the evaluated value from the new postfix
			// As new postfix contains evaluated expression inside bracket
			cmd = factory.create_num_command(newResult.top());
			postfix[count++] = cmd;

			if (count == postfix.size() - 1) {
				postfix.resize(2 * postfix.size());
			}

			continue; // we already taken care of the end bracket so loop again for new token
		} else { // Token is a numeric token
			int temp_int;
			std::istringstream ss(token); // Convert the numeric literal to integer
			ss >> temp_int;
			cmd = factory.create_num_command(temp_int);

			// Store the integer to the array of postfix
			postfix[count++] = cmd;

			if (count == postfix.size() - 1) {
				postfix.resize(2 * postfix.size());
			}

			// Do not execute or evaluate the expression yet
			continue;
		}

		if (temp.is_empty() || (cmd->getPrecedence() > temp.top()->getPrecedence())) {
			// Store the command to the stack
			temp.push(cmd);
		} else if (cmd->getPrecedence() == temp.top()->getPrecedence()) {
			// Both command precedence is same
			postfix[count++] = temp.top(); // Take the top command and append to the postfix array
			temp.pop();
			temp.push(cmd);

			if (count == postfix.size() - 1)
				postfix.resize(2 * postfix.size());
		} else {
			// Precedence lower than top of stack
			while (!temp.is_empty() && (cmd->getPrecedence() <= temp.top()->getPrecedence())) {
				Expr_Command *t = temp.top();
				postfix[count++] = t;
				temp.pop(); // Pop the command stack until we get a higher precedence command

				if (count == postfix.size() - 1)
					postfix.resize(2 * postfix.size());
			}

			// Push the command
			temp.push(cmd);
		}

		if (count == postfix.size() - 1)
			postfix.resize(2 * postfix.size());
	}

	// Pop the command stack and store the command to postfix expression
	while (!temp.is_empty()) {
		postfix[count++] = temp.top();
		temp.pop();

		if (count == postfix.size() - 1) {
			postfix.resize(2 * postfix.size());
		}
	}

	return evaluate_expression(count, postfix);
}

bool Calculator::evaluate_expression(size_t expression_count, Array<Expr_Command *> &postfix) {
	size_t index = 0;
	try {
		while (index < expression_count) {
			postfix[index]->execute();
			delete postfix[index++];
		}
	} catch (std::exception &ex) {
		std::cout << "Exception occurred: " << ex.what() << "\n";
		while (index < expression_count) {
			delete postfix[index++];
		}
		return false;
	}
	return true;
}
