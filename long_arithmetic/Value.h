#ifndef VALUE_H
# define VALUE_H

#include <iostream>
#include <vector>


class Value {

public:

	Value();
	Value(std::string digit);
	virtual ~Value() {};

	const char sign;
	const std::vector<int> data;

};

#endif //VALUE_H