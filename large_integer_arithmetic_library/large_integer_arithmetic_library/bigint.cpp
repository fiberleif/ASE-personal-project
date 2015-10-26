#include"bigint.h"

using namespace std;

namespace Bigint
{
    Bigint::Bigint()
    {
        sign = true;
    }

    Bigint::Bigint(int first_digit)
    {
        sign = true;
        bigint_vector_.clear();
        bigint_vector_.push_back(first_digit);
    }

    Bigint::Bigint(vector<int> init_array)
    {
        sign = true;
        bigint_vector_.clear();
        for (auto element : init_array)
        {
            bigint_vector_.push_back(element);
        }
    }

    void Bigint::convert_forward(long long integer)
    {
        bigint_vector_.clear();
        int i = 0;
        while (integer / 10)
        {
            bigint_vector_[i] = (integer % 10);
            integer = integer / 10;
            i++;
        }
        bigint_vector_[i] = integer;
    }

    long long Bigint::convert_backward()
    {
        long long number = 0;
        int i = 0;
        long long base = 1;
        while (i < bigint_vector_.size())
        {
            number += base * bigint_vector_[i];
            base *= 10;
            i++;
        }
        return number;
    }
    void Bigint::vector_printf()
    {
        cout << "The sign of result:" << sign << endl;
        cout << "The absolute value of result:";
        for (int i = (bigint_vector_.size() - 1); i >= 0; i--)
        {
            cout << bigint_vector_[i];
        }
        cout << endl;
    }
}


