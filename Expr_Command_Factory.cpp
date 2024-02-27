#include <libpq-fe.h>
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"

Expr_Command_Factory::Expr_Command_Factory(const Expr_Command_Factory&)
{
}

const Expr_Command_Factory& Expr_Command_Factory::operator=(const Expr_Command_Factory&)
{
	return *this;
}