#include<stdio.h>
#include<iostream>
#include<vector>
#include<time.h>

#include"bigint.h"
#include"constant.h"

#define _BIGINT_LIBRARY_

int main(int argc,char *argv[])
{
    clock_t start_ = clock();
#if defined (_BIGINT_LIBRARY_)
    Bigint::Bigint init(2);
    Bigint::Bigint zero(0);
    std::vector<Bigint::Bigint> prime_(1,init);
    int prime_size = atoi (argv[1]);
    Bigint::Bigint number(3);
    while (prime_.size() < prime_size)
    {
        bool flag = 1;
        Bigint::Bigint number_sqrt = number;
        for (std::vector<Bigint::Bigint>::iterator prime_iter_ = prime_.begin(); prime_iter_ != prime_.end(); prime_iter_++)
        {
            if ((*prime_iter_) > number_sqrt)
            {   
                break;
            }
            else
            {
                if ((number%(*prime_iter_)) == zero)
                {
                    flag = 0;
                    break;
                }

            }
        }
        if (flag == 1)
        {
            prime_.push_back(number);
        }
        number = number + init;
    }
    printf("The pre-set prime size is %d\n", prime_size);
    printf("The prime sequence is under:\n");
    for (std::vector<Bigint::Bigint>::iterator prime_iter_ = prime_.begin(); prime_iter_ != prime_.end(); prime_iter_++)
    {
        (*prime_iter_).vector_printf();
        cout << endl;
    }
#else
    std::vector<long long> prime_(1,2);
    int prime_size = atoi(argv[1]);
    long long number = 3;
    while (prime_.size() < prime_size)
    {
        bool flag = 1;
        double number_sqrt = sqrt(number);
        for (std::vector<long long>::iterator prime_iter_ = prime_.begin(); prime_iter_ != prime_.end(); prime_iter_++)
        {
            if ((*prime_iter_) > number_sqrt)
            {   
                break;
            }
            else
            {
                if ((number%(*prime_iter_)) == 0)
                {
                    flag = 0;
                    break;
                }

            }
        }
        if (flag == 1)
        {
            prime_.push_back(number);
        }
        number = number + 2;
    }
    printf("The pre-set prime size is %d\n", prime_size);
    printf("The prime sequence is under:\n");
    for (std::vector<long long>::iterator prime_iter_ = prime_.begin(); prime_iter_ != prime_.end(); prime_iter_++)
    {
        printf("%ld\n", *prime_iter_);
    }
#endif
    printf("Total process time cost:%f\n", (clock() - start_) / (double)CLOCKS_PER_SEC);
    return 0;
}