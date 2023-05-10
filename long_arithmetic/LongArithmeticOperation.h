#ifndef LONGARITHMETICOPERATION_H
# define LONGARITHMETICOPERATION_H

#include "Value.h"

Value*	abs_sum(Value* digit1, Value* digit2);
Value*	abs_sub(Value* digit1, Value* digit2);

Value*	sum(Value *digit1, Value *digit2);
Value*	sub(Value* digit1, Value* digit2);
bool	comparison(Value* digit1, Value* digit2);

#endif