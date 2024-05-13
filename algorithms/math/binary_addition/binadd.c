/**
 * @file insertionsort.c
 * @author Walt Jacob
 * @brief Insertionsort example
 * @date 2023-10-19
 *
 * @copyright Copyright Walter Jacob (c) 2023
 *
 * @details To build it with gcc with plenty of optimization, run
 *              gcc -O3 binadd.c -o binadd
 *          To run it
 *              binadd a b
 *          where a and b are 32-bit unsigned integers.
 */

#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 32

void print_array(unsigned int *arr, unsigned int len)
{
    for (unsigned int i = 0; i < len; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void sum(const unsigned int *a, const unsigned int *b, unsigned int len, unsigned int *c)
{
    unsigned int carry = 0;
    for (unsigned int i = 0; i < len; i++)
    {
        unsigned int s = a[i] + b[i];
        if (carry == 1 && s == 2)
        {
            c[i] = 1;
            carry = 1;
        }
        else if ((carry == 1 && s == 1) || (carry == 0 && s == 2))
        {
            c[i] = 0;
            carry = 1;
        }
        else
        {
            c[i] = s + carry;
            carry = 0;
        }
    }
    c[len] = carry;
}

unsigned int upow(unsigned int n, unsigned int e)
{
    unsigned int a = n;
    switch (e)
    {
    case 0:
        return 1;
    case 1:
        return n;
    default:
        for (unsigned int i = 2; i <= e; i++)
        {
            a *= n;
        }
        break;
    }
    return a;
}

void u_to_binarr(unsigned int n, unsigned int *arr, unsigned int len)
{
    // Find the length of a_int in max bits
    unsigned int test = 1;
    unsigned int exp = 0;
    while (n > test)
    {
        test *= 2;
        exp++;
    }
    // printf("test: %u, exp: %u\n", test, exp);
    while (exp > 0)
    {
        exp--;
        unsigned int v = upow(2, exp);
        if (n >= v)
        {
            n -= v;
            arr[exp] = 1;
        }
        else
        {
            arr[exp] = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    // We need three args: the program and two integers
    if (argc != 3)
    {
        printf("Invalid argument list!\n");
        return 1;
    }

    char *p_end;
    long int a_int = strtol(argv[1], &p_end, 10);
    long int b_int = strtol(argv[2], &p_end, 10);

    if (a_int < 0 || b_int < 0)
    {
        printf("Only positive integers in decimal, please!\n");
        return 2;
    }

    unsigned int a[ARR_LEN] = {0};
    unsigned int b[ARR_LEN] = {0};

    u_to_binarr(a_int, a, ARR_LEN);
    u_to_binarr(b_int, b, ARR_LEN);

    // print_array(a, ARR_LEN);
    // print_array(b, ARR_LEN);

    unsigned int c[ARR_LEN + 1];

    sum(a, b, ARR_LEN, c);
    print_array(c, ARR_LEN + 1);

    return 0;
}