#include<stdio.h>
#include<vector>
#include<iostream>

#include"bigint.h"
#include"constant.h"

#define _TEST_ADDITION_

int main(int argc,char *argv[])
{
    Bigint::arithmetic_type operator_;
    vector<int> first_;
    vector<int> second_;
    try{
        ParseArgs(operator_, first_, second_);
    }
    catch (Bigint::arithmetic_type &value)
    {
        cout << "Something wrong with the line-1 input!" << endl;
    }
    catch (...)
    {
        cout << "Something with no expection!" << endl;
    }
    Bigint::Bigint first(first_);
    Bigint::Bigint second(second_);
    Bigint::Bigint result;
    Bigint::Bigint result_prepare;
    switch (operator_)
    {
    case Bigint::Add:
        result = first + second;
        result.vector_printf();
        break;
    case Bigint::Sub:
        result = first - second;
        result.vector_printf();
        break;
    case Bigint::Mul:
        result = first * second;
        result.vector_printf();
        break;
    case Bigint::Div:
        result = first / second;
        result_prepare = first % second;
        result.vector_printf();
        result_prepare.vector_printf();
        break;
    }
   

#if defined(_TEST_ADDITION_)
    long long first_ll = first.convert_backward();
    long long second_ll = second.convert_backward();
    long long result_ll;
    long long result_prepare_ll;
    switch (operator_)
    {
    case Bigint::Add:
        result_ll = first_ll + second_ll;
        cout << endl;
        cout << "The result from C original operator:" << result_ll << endl;
        break;
    case Bigint::Sub:
        result_ll = first_ll - second_ll;
        cout << endl;
        cout << "The result from C original operator:" << result_ll << endl;
        break;
    case Bigint::Mul:
        result_ll = first_ll * second_ll;
        cout << endl;
        cout << "The result from C original operator:" << result_ll << endl;
        break;
    case Bigint::Div:
        result_ll = first_ll / second_ll;
        result_prepare_ll = first_ll % second_ll;
        cout << "The Quotient from C original operator:" << result_ll << endl;
        cout << "The Reminder from C original operator:" << result_prepare_ll << endl;
        break;
    }
   
#endif
    system("pause");

}
