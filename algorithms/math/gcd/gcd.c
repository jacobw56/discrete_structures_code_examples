/**
 * @file gcd.c
 * @author Walt Jacob
 * @brief Greatest common denominator example
 * @date 2023-10-24
 *
 * @copyright Copyright Walter Jacob (c) 2023
 *
 * @details To build it with gcc with plenty of optimization, run
 *              gcc -O3 gcd.c -o gcd
 *          then run it from the command line with
 *              gcd n m
 *          where n and m are positive integers.
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>  // printf
#include <stdlib.h> // strtoul

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Wrong number of args: gcd n m\n");
        return 1;
    }

    // note that we could do a *much* better job of input validation
    unsigned int n = (unsigned int)strtoul(argv[1], NULL, 10);
    unsigned int m = (unsigned int)strtoul(argv[2], NULL, 10);

    printf("GCD of n: %u \t m: %u\n", n, m);
    printf("We get \n");
    printf("\\begin{equation*}\n");
    printf("\\begin{aligned}\n");
    unsigned int x = n;
    unsigned int y = m;

    while (y != 0)
    {
        unsigned int r = x % y;
        unsigned int q = (unsigned int)(x / y);
        printf("%u = ", x);
        x = y;
        y = r;
        printf("%u \\cdot %u + %u \\\\\n", x, q, r);
    }
    printf("\\end{aligned}\n");
    printf("\\end{equation*}\n");
    printf("so that $\\gcd(%u,%u) = %u$\n", n, m, x);

    return 0;
}