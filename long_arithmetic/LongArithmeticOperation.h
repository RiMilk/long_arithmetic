#ifndef LONGARITHMETICOPERATION_H
# define LONGARITHMETICOPERATION_H

#include "Value.h"

Value*	abs_sum(const Value* digit1, const Value* digit2);
Value*	abs_sub(const Value* digit1, const Value* digit2);

Value*	summ(const Value *digit1, const Value *digit2);
Value*	subb(const Value* digit1, const Value* digit2);
bool	comparison(const Value* digit1, const Value* digit2);

#endif