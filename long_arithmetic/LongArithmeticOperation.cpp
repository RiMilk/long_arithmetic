#include "LongArithmeticOperation.h"

Value* abs_sum(Value* digit1, Value* digit2)
{
	Value* result = new Value();

	int len1 = digit1->data.size() - 1;
	int len2 = digit2->data.size() - 1;


	if (len1 > len2)
	{
		for (int i = 0; i <= len1; i++)
			result->data.push_back(digit1->data[i]);

		for (int i = len2; i >= 0; i--)
		{
			result->data[len1] += digit2->data[i];
			len1--;
		}
	}
	else
	{
		for (int i = 0; i <= len2; i++)
			result->data.push_back(digit2->data[i]);

		for(int i = len1; i >= 0; i--)
		{
			result->data[len2] += digit1->data[i];
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

	int len1 = digit1->data.size() - 1;
	int len2 = digit2->data.size() - 1;

	if (len1 > len2)
	{
		for (int i = 0; i <= len1; i++)
			result->data.push_back(digit1->data[i]);

		for (int i = len2; i >= 0; i--)
		{
			result->data[len1] -= digit2->data[i];
			len1--;
		}
	}
	else
	{
		for (int i = 0; i <= len2; i++)
			result->data.push_back(digit2->data[i]);

		for (int i = len1; i >= 0; i--)
		{
			result->data[len2] -= digit1->data[i];
			len2 -= 1;
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