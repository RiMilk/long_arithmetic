#include "LongArithmeticOperation.h"

Value* abs_sum(Value* digit1, Value* digit2)
{
	Value* result = new Value();

	result->sign = '+';

	int len1 = digit1->data.size() - 1;
	int len2 = digit2->data.size() - 1;

	if (len1 > len2)
	{
		result->data = std::move(digit1->data);
		while (len2 >= 0)
		{
			result->data[len1] += digit2->data[len2];
			len1--;
			len2--;
		}
	}
	else
	{
		result->data = std::move(digit2->data);
		while (len1 >= 0)
		{
			result->data[len2] += digit1->data[len1];
			len1--;
			len2--;
		}
	}

	for (int i = result->data.size() - 1; i > 0; i--)
		if (result->data[i] >= 10)
		{
			result->data[i] -= 10;
			result->data[i - 1]++;
		}

	if (result->data[0] >= 10)
	{
		result->data[0] -= 10;
		result->data.insert(result->data.begin(), 1);
	}

	return (result);
}

Value* abs_sub(Value* digit1, Value* digit2)
{
	Value* result = new Value();

	result->sign = '+';

	int len1 = digit1->data.size() - 1;
	int len2 = digit2->data.size() - 1;

	if (len1 > len2)
	{
		result->data = std::move(digit1->data);
		while (len2 >= 0)
		{
			result->data[len1] -= digit2->data[len2];
			len1--;
			len2--;
		}
	}
	else
	{
		result->data = std::move(digit2->data);
		while (len1 >= 0)
		{
			result->data[len2] -= digit1->data[len1];
			len1--;
			len2--;
		}
	}

	for (int i = result->data.size() - 1; i > 0; i--)
		if (result->data[i] >= 10)
		{
			result->data[i] -= 10;
			result->data[i - 1]--;
		}

	if (result->data[0] >= 10)
	{
		result->data[0] -= 10;
		result->data.insert(result->data.begin(), 1);
	}

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

Value* sum(Value* digit1, Value* digit2)
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

Value* sub(Value* digit1, Value* digit2)
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