#pragma once
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

namespace Bigint
{
    enum arithmetic_type : char
    {
        Add = '+',
        Sub = '-',
        Mul = '*',
        Div = '/'
    };

    inline void ParseArgs(arithmetic_type
        &operator_, vector<int> &first, vector<int> &second)
    {
        char line1 = getchar();
        first.clear();
        second.clear();
        string first_;
        string second_;
        switch (line1)
        {
        case '+':
            operator_ = Add;
            break;
        case '-':
            operator_ = Sub;
            break;
        case '*':
            operator_ = Mul;
            break;
        case '/':
            operator_ = Div;
            break;
        default:
            throw operator_;
        }
        cin >> first_ >> second_;
        for (int i = (first_.size() - 1); i >= 0; i--)
        {
            first.push_back(first_[i] - '0');
        }
        for (int i = (second_.size() - 1); i >= 0; i--)
        {
            second.push_back(second_[i] - '0');
        }
        

    }
}