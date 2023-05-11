#include <iostream>

#include "Value.h"
#include "LongArithmeticOperation.h"

int main(int count, char* params[])
{
    if (count == 3)
    {
        Value* data = new Value(params[1]);
        Value* data1 = new Value(params[2]);

        Value* data4 = summ(data, data1);
        std::cout << "SUMM :";
        data4->print();

        Value* data3 = subb(data, data1);
        std::cout << "SUBB :";
        data3->print();

    }
    else
    {
        std::string tmp1;
        std::cin >> tmp1;

        std::string tmp2;
        std::cin >> tmp2;

        Value* data = new Value(tmp1);
        Value* data1 = new Value(tmp2);

        Value* data4 = summ(data, data1);
        std::cout << "SUMM :";
        data4->print();

        Value* data3 = subb(data, data1);
        std::cout << "SUBB :";
        data3->print();
    }
}