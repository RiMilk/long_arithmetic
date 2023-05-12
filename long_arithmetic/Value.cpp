#include "Value.h"

Value::Value()
{

}

Value::Value(char sign, std::vector<int> digits, size_t size)
{
	try
	{
		this->size = size;
		this->data = digits;
		this->sign = sign;
	}
	catch (std::string error_message)
	{
		std::cout << error_message << std::endl;
	}
}

Value::Value(std::string digit)
{
	if (chaeckValidData(digit) == true)
	{
		size_t iter = 0;

		if (digit[0] == '+' || digit[0] == '-')
		{
			iter++;

			if (digit[0] == '+')
				sign = '+';

			if (digit[0] == '-')
				sign = '-';
		}
		else
			sign = '+';

		while (iter < digit.length())
			data.push_back(digit[iter++] - '0');

		size = data.size();
	}
	else 
	{
		std::cout << "NOT VALID DATA!" << std::endl;
	}
}

bool Value::chaeckValidData(std::string data)
{
	if (data != "" && (data[0] == '+' || data[0] == '-' || (data[0] >= '0' && data[0] <= '9')))
	{
		size_t iter = 1;
		while (iter < data.length())
			if (!(data[iter] >= '0' && data[iter++] <= '9'))
				return (false);
		return (true);
	}
	return (false);
}

Value::~Value()
{
	delete &size;
	delete &sign;
	delete &data;
}

void Value::print()
{
	if (sign == '-')
		std::cout << sign;

	size_t iter = 0;
	while (iter < size)
	{
		std::cout << data[iter];
		iter++;
	}

	std::cout << std::endl;
}

std::string Value::convertToString()
{
	std::string result;

	if (sign == '-')
		result += "-";

	for (int i = 0; i < size; i++)
		result += data[i] + '0';

	return (result);
}

