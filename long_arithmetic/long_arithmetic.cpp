﻿#include <iostream>

#include "Value.h"
#include "LongArithmeticOperation.h"

int main(int count, char* params[])
{
    Value* data = new Value(params[1]);
    Value* data1 = new Value(params[2]);

    Value* data4 = abs_sum(data, data1);
    std::cout << "SUMM :";
    data4->print();

    //Value* data3 = subb(data, data1);
    //std::cout << "SUBB :";
    //data3->print();

}