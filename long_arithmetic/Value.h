#ifndef VALUE_H
# define VALUE_H

#include <iostream>
#include <vector>


class Value {

public:

	Value();
	Value(std::string digit);

	virtual ~Value();

	char sign;
	std::vector<int> data;

private:

	bool chaeckValidData(std::string data);
};

#endif //VALUE_H