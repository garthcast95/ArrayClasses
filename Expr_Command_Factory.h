#ifndef EXPR_COMMAND_FACTORY_H
#define EXPR_COMMAND_FACTORY_H

#include "Num_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"

class Expr_Command_Factory {
public:
	virtual Num_Command* create_num_command(int num) = 0;
	virtual Add_Command* create_add_command() = 0;
	virtual Subtract_Command* create_subtract_command() = 0;
	virtual Multiply_Command* create_multiply_command() = 0;
	virtual Divide_Command* create_divide_command() = 0;

protected:
	Expr_Command_Factory() {}

private:
	Expr_Command_Factory(const Expr_Command_Factory&);
	const Expr_Command_Factory& operator=(const Expr_Command_Factory&);
};


#endif //EXPR_COMMAND_FACTORY_H
