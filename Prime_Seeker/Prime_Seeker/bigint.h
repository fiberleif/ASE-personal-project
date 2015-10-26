#pragma once
/*!
 * \ASE Requirement
 * \Input: 3 lines.
 * \First line is one character +, -, * or /.
 * \Second line is a positive number N in decimal.
 * \Third line is a positive number M in decimal.
 * \You should not assume the maximum length of input integers.
 * \Output:
 * \For +, - and *, output one line: the result in decimal.
 * \For /, output two lines: the quotient in decimal and the remainder in decimal. 
 * \author
 *   -Guoqing Liu(v-guoql@microsoft.com)
 */
#include<stdio.h>
#include<math.h>
#include<vector>

#include"constant.h"

using namespace std;

namespace Bigint
{
    class Bigint
    {
    public:
        //initialize the bigint.
        Bigint();
        Bigint(int first_digit);
        Bigint(vector<int> init_array);
        //convert the C's bulit-in type<long long> into bigint.
        void convert_forward(long long integer);
        //convert bigint into the C's bulit-in type<long long>.
        long long convert_backward();
        //print the private vector
        void vector_printf();

        //larger operator
        bool operator>(const Bigint &lhs) const
        {
            bool compare;
            if (bigint_vector_.size() > lhs.bigint_vector_.size())
                compare = true;
            else if (bigint_vector_.size() < lhs.bigint_vector_.size())
                compare = false;
            else
            {
                int i = (bigint_vector_.size() - 1);
                while ((i >= 0) && (bigint_vector_[i] == lhs.bigint_vector_[i]))
                {
                    i--;
                }
                if (i >= 0)
                {
                    compare = bool((bigint_vector_[i] - lhs.bigint_vector_[i]) > 0);
                }
                else
                {
                    return false;
                }
            }
            return compare;
        }
        //smaller operator
        bool operator<(const Bigint &lhs) const
        {
            bool compare;
            if (bigint_vector_.size() > lhs.bigint_vector_.size())
                compare = false;
            else if (bigint_vector_.size() < lhs.bigint_vector_.size())
                compare = true;
            else
            {
                int i = (bigint_vector_.size() - 1);
                while ((i >= 0) && (bigint_vector_[i] == lhs.bigint_vector_[i]))
                {
                    i--;
                }
                if (i >= 0)
                {
                    compare = bool((lhs.bigint_vector_[i] - bigint_vector_[i]) > 0);
                }
                else
                {
                    return false;
                }
            }
            return compare;
        }
        //equal operator
        bool operator==(const Bigint &lhs) const
        {
            bool compare;
            if (bigint_vector_.size() > lhs.bigint_vector_.size())
                compare = false;
            else if (bigint_vector_.size() < lhs.bigint_vector_.size())
                compare = false;
            else
            {
                int i = (bigint_vector_.size() - 1);
                while ((i >= 0) && (bigint_vector_[i] == lhs.bigint_vector_[i]))
                {
                    i--;
                }
                if (i >= 0)
                {
                    compare = false;
                }
                else
                {
                    return true;
                }
            }
            return compare;
        }
        //Add operator
        Bigint operator+(const Bigint &lhs) const
        {
            Bigint result;
            int carry;
            if (bigint_vector_.size() >= lhs.bigint_vector_.size())
            {
                for (int i = 0; i < lhs.bigint_vector_.size(); i++)
                {
                    result.bigint_vector_.push_back(bigint_vector_[i] + lhs.bigint_vector_[i]);
                }
                for (int i = lhs.bigint_vector_.size(); i < bigint_vector_.size(); i++)
                { 
                    result.bigint_vector_.push_back(bigint_vector_[i]);
                }
                for (int i = 0; i < result.bigint_vector_.size(); i++)
                {
                    if (i != (result.bigint_vector_.size() - 1))
                    {
                        result.bigint_vector_[i + 1] += (result.bigint_vector_[i] / 10);
                        result.bigint_vector_[i] = result.bigint_vector_[i] % 10;
                    }
                    else
                    {
                        carry = (result.bigint_vector_[i] / 10);
                        result.bigint_vector_[i] = result.bigint_vector_[i] % 10;
                    }
                }
                if (carry)
                    result.bigint_vector_.push_back(carry);
            }
            else
            {
                for (int i = 0; i < bigint_vector_.size(); i++)
                {
                    result.bigint_vector_.push_back(bigint_vector_[i] + lhs.bigint_vector_[i]);
                }
                for (int i = bigint_vector_.size(); i < lhs.bigint_vector_.size(); i++)
                {
                    result.bigint_vector_.push_back(lhs.bigint_vector_[i]);
                }
                for (int i = 0; i < result.bigint_vector_.size(); i++)
                {
                    if (i != (result.bigint_vector_.size() - 1))
                    {
                        result.bigint_vector_[i + 1] += (result.bigint_vector_[i] / 10);
                        result.bigint_vector_[i] = result.bigint_vector_[i] % 10;
                    }
                    else
                    {
                        carry = (result.bigint_vector_[i] / 10);
                        result.bigint_vector_[i] = result.bigint_vector_[i] % 10;
                    }
                }
                if(carry)
                    result.bigint_vector_.push_back(carry);

            }
            return result;
        }
        //Sub operator
        Bigint operator-(const Bigint &lhs) 
        {
            int carry;
            Bigint result;
            bool compare;
            if (bigint_vector_.size() > lhs.bigint_vector_.size())
                compare = true;
            else if (bigint_vector_.size() < lhs.bigint_vector_.size())
                compare = false;
            else
            {
                int i = (bigint_vector_.size() - 1);
                while ((i >= 0)&&(bigint_vector_[i] == lhs.bigint_vector_[i]))
                {
                    i--;
                }
                if (i >= 0)
                {
                    compare = bool((bigint_vector_[i] - lhs.bigint_vector_[i]) > 0);
                }
                else
                {
                    result.bigint_vector_.push_back(0);
                    return result;
                }
            }
            if (compare)
            {
                for (int i = 0; i < lhs.bigint_vector_.size(); i++)
                {
                    result.bigint_vector_.push_back(bigint_vector_[i] - lhs.bigint_vector_[i]);
                }
                for (int i = lhs.bigint_vector_.size(); i < bigint_vector_.size(); i++)
                {
                    result.bigint_vector_.push_back(bigint_vector_[i]);
                }
                for (int i = 0; i < result.bigint_vector_.size(); i++)
                {
                    if (result.bigint_vector_[i] < 0)
                    {
                        result.bigint_vector_[i + 1] -= 1;
                        result.bigint_vector_[i] += 10;
                    }
                }
                int i = (result.bigint_vector_.size() - 1);
                vector<int>::iterator iter = result.bigint_vector_.end();
                iter--;
                carry = result.bigint_vector_[i];
                if (!carry)
                    result.bigint_vector_.erase(iter);
            }
            else
            {
                result.sign = false;
                for (int i = 0; i < bigint_vector_.size(); i++)
                {
                    result.bigint_vector_.push_back(lhs.bigint_vector_[i] - bigint_vector_[i]);
                }
                for (int i = bigint_vector_.size(); i < lhs.bigint_vector_.size(); i++)
                {
                    result.bigint_vector_.push_back(lhs.bigint_vector_[i]);
                }
                for (int i = 0; i < result.bigint_vector_.size(); i++)
                {
                    if (result.bigint_vector_[i] < 0)
                    {
                        result.bigint_vector_[i + 1] -= 1;
                        result.bigint_vector_[i] += 10;
                    }
                }
                int i = (result.bigint_vector_.size() - 1);
                vector<int>::iterator iter = result.bigint_vector_.end();
                iter--;
                carry = result.bigint_vector_[i];
                if (!carry)
                    result.bigint_vector_.erase(iter);

            }
           return result;

        }
        //Mul operator
        Bigint operator*(const Bigint &lhs) const
        {
            size_t result_size = bigint_vector_.size() + lhs.bigint_vector_.size() - 1;
            vector<int> init(result_size, 0);
            Bigint result(init);
            int carry;
            for (int x = 0; x < bigint_vector_.size(); x++)
            {
                for (int y = 0; y < lhs.bigint_vector_.size(); y++)
                {
                    result.bigint_vector_[x + y] += (bigint_vector_[x] * lhs.bigint_vector_[y]);
                }
            }
            for (int i = 0; i < result.bigint_vector_.size(); i++)
            {
                if (i != (result.bigint_vector_.size() - 1))
                {
                    result.bigint_vector_[i + 1] += (result.bigint_vector_[i] / 10);
                    result.bigint_vector_[i] = result.bigint_vector_[i] % 10;
                }
                else
                {
                    carry = (result.bigint_vector_[i] / 10);
                    result.bigint_vector_[i] = result.bigint_vector_[i] % 10;
                }
            }
            if (carry)
                result.bigint_vector_.push_back(carry);
            return result;
        }
        //Dic operator
        Bigint operator/(const Bigint &lhs) const
        {
            vector<int> one_(1, 1);
            vector<int> zero_(1, 0);
            Bigint result(zero_);
            Bigint tool(bigint_vector_);
            Bigint one(one_);
            while ((tool > lhs)||(tool == lhs))
            {
                result = result + one;
                tool = tool - lhs;
            }
            return result;
        }
        //Mode operator
        Bigint operator%(const Bigint &lhs) const
        {
            vector<int> one_(1, 1);
            vector<int> zero_(1, 0);
            Bigint tool(bigint_vector_);
            Bigint one(one_);
            while ((tool > lhs) || (tool == lhs))
            {
               tool = tool - lhs;
            }
            return tool;
        }
    private:
        vector<int> bigint_vector_;
        bool sign;
    };
}