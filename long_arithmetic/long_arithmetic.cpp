#include <iostream>

#include "Value.h"
#include "LongArithmeticOperation.h"

int main(int count, char* params[])
{
    try
    {
        std::string val1, val2;

        if (count == 3)
        {
            val1 = params[1];
            val2 = params[2];
        }
        else
            std::cin >> val1 >> val2;

        Value* data = new Value(val1);
        Value* data1 = new Value(val2);

        Value* data4 = summ(data, data1);
        std::cout << "SUMM :" << data4->convertToString() << std::endl;

        Value* data3 = subb(data, data1);
        std::cout << "SUBB :" << data3->convertToString() << std::endl;
    }
    catch (std::string error_message)
    {
        std::cout << error_message << std::endl;
    }
}