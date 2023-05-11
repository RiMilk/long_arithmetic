#include "Value.h"

Value::Value()
{

}

Value::Value(std::string digit)
{
	if (chaeckValidData(digit) == true)
	{
		int iter = 0;
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

}

bool Value::chaeckValidData(std::string data)
{
	if (data != "" && (data[0] == '+' || data[0] == '-' || (data[0] >= '0' && data[0] <= '9')))
	{
		int iter = 1;
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

	int iter = 0;
	while (iter < data.size())
	{
		std::cout << data[iter];
		iter++;
	}

	std::cout << std::endl;
}