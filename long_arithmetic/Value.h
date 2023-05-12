#ifndef VALUE_H
# define VALUE_H

#include <iostream>
#include <vector>

class Value {

public:

	Value();
	Value(std::string digit);
	Value(char sign, std::vector<int> digits, size_t size);

	~Value();

	size_t size; 
	char sign; 
	std::vector<int> data;

	void print();
	std::string convertToString();

private:

	bool chaeckValidData(std::string data);
};

#endif //VALUE_H