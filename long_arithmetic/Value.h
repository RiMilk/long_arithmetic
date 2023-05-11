#ifndef VALUE_H
# define VALUE_H

#include <iostream>
#include <vector>


class Value {

public:

	Value();
	Value(std::string digit);

	virtual ~Value();

	int size;
	char sign;
	std::vector<int> data;

	void print();
private:

	bool chaeckValidData(std::string data);
};

#endif //VALUE_H