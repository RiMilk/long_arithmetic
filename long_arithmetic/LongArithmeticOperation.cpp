#include "LongArithmeticOperation.h"

Value* abs_sum(Value* digit1, Value* digit2)
{
	std::vector<int> value_res;

	if (digit1->size >= digit2->size)
	{
		for (int i = 0; i < digit1->size; i++)
			value_res.push_back(digit1->data[i]);

		size_t iter = digit1->size - 1;
		for (int i = digit2->size - 1; i >= 0; i--)
		{
			value_res[iter] += digit2->data[i];
			iter--;
		}
	}
	else
	{
		for (int i = 0; i < digit2->size; i++)
			value_res.push_back(digit2->data[i]);

		size_t iter = digit2->size - 1;
		for (int i = digit1->size - 1; i >= 0; i--)
		{
			value_res[iter] += digit1->data[i];
			iter--;
		}
	}

	for (int i = value_res.size() - 1; i >= 0; i--)
		if (value_res[i] >= 10)
		{
			value_res[i] -= 10;
			if (i != 0)
				value_res[i - 1]++;
			else
				value_res.insert(value_res.begin(), 1);
		}

	Value* result = new Value('+', value_res, value_res.size());
	return (result);
}

//TODO del first null
Value* abs_sub(Value* digit1, Value* digit2)
{

	std::vector<int> value_res;

	if ((digit1->size >= digit2->size) && (comparison(digit1, digit2) == true))
	{
		for (int i = 0; i < digit1->size; i++)
			value_res.push_back(digit1->data[i]);

		size_t iter = digit1->size - 1;
		for (int i = digit2->size - 1; i >= 0; i--)
		{
			value_res[iter] -= digit2->data[i];
			iter--;
		}
	}
	else
	{
		for (int i = 0; i < digit2->size; i++)
			value_res.push_back(digit2->data[i]);

		size_t iter = digit2->size - 1;
		for (int i = digit1->size - 1; i >= 0; i--)
		{
			value_res[iter] -= digit1->data[i];
			iter--;
		}
	}

	for (int i = value_res.size() - 1; i >= 0; i--)
		if (value_res[i] < 0)
		{
			if (i != 0)
			{
				value_res[i] = 10 + value_res[i];
				value_res[i - 1]--;
			}
			else
			{
				value_res[0] = 10 + value_res[0];
			}
		}

	Value* result = new Value('+', value_res, value_res.size());
	return (result);
}

bool	comparison(Value* digit1, Value* digit2)
{
	if (digit1->data.size() > digit2->data.size())
		return (true);

	if (digit1->data.size() < digit2->data.size())
		return (false);

	int iter = digit1->data.size() - 1;
	while (iter >= 0)
	{
		if (digit1->data[iter] < digit2->data[iter++])
			return (false);
	}
	return (true);
}

Value* summ(Value* digit1, Value* digit2)
{
	Value* result = new Value();

	if (digit1->sign == '+' && digit2->sign == '+')
		return (abs_sum(digit1, digit2));

	if (digit1->sign == '+' && digit2->sign == '-')
	{
		result = abs_sub(digit1, digit2);
		if (!(comparison(digit1, digit2)))
			result->sign = '-';
	}

	if (digit1->sign == '-' && digit2->sign == '+')
	{
		result = abs_sub(digit1, digit2);
		if (!(comparison(digit2, digit1)))
			result->sign = '-';
	}

	if (digit1->sign == '-' && digit2->sign == '-')
	{
		result = abs_sum(digit1, digit2);
		result->sign = '-';
	}

	return (result);
}

Value* subb(Value* digit1, Value* digit2)
{
	Value* result = new Value();

	if (digit1->sign == '+' && digit2->sign == '+')
	{
		result = abs_sub(digit1, digit2);
		if (!(comparison(digit1, digit2)))
			result->sign = '-';
	}

	if (digit1->sign == '+' && digit2->sign == '-')
		return (abs_sum(digit1, digit2));

	if (digit1->sign == '-' && digit2->sign == '+')
	{
		result = abs_sum(digit1, digit2);
		result->sign = '-';
	}

	if (digit1->sign == '-' && digit2->sign == '-')
	{
		result = abs_sub(digit1, digit2);
		if (!(comparison(digit2, digit1)))
			result->sign = '-';
	}

	return (result);
}