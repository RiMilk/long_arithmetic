#include <iostream>

#include "Value.h"
#include "LongArithmeticOperation.h"

int main()
{
    //std::string tmp;
    //std::cin >> tmp;

    Value* data = new Value("111");
    Value* data1 = new Value("9999");
    Value* data3 = abs_sub(data, data1);

    std::copy(data3->data.begin(), data3->data.end(), std::ostream_iterator<int>(std::cout, " "));
}