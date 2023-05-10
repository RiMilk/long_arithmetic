#include "LongArithmeticOperation.h"

Value* abs_sum(Value* digit1, Value* digit2)
{
	Value* result = new Value();

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

	int len1 = digit1->data.size() - 1;
	int len2 = digit2->data.size() - 1;

	if (len1 > len2)
	{
		result->data = std::move(digit1->data);
		while (len2 > 0)
		{
			result->data[len1] += digit2->data[len2];
			len1--;
			len2--;
		}
	}
	else
	{
		result->data = std::move(digit2->data);
		while (len1 > 0)
		{
			result->data[len2] += digit1->data[len1];
			len1--;
			len2--;
		}
	}

	return (result);
}

Value* sum(Value* digit1, Value* digit2)
{
	Value* result = new Value();


	return (result);
}

Value* sub(Value* digit1, Value* digit2)
{
	Value* result = new Value();

	return (result);
}