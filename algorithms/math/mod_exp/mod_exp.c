/**
 * @file mod_exp.c
 * @author Walt Jacob
 * @brief Modular exponentiation example
 * @date 2023-10-24
 *
 * @copyright Copyright Walter Jacob (c) 2023
 *
 * @details To build it with gcc with plenty of optimization, run
 *              gcc -O3 mod_exp.c -o mod_exp
 *          then run it from the command line with
 *              mod_exp b n m
 *          where b is the base, n is the exponent of b, and m is the modulus.
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>  // printf
#include <stdlib.h> // strtoul

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Too few args: mod_exp b n m\n");
        return 1;
    }

    // note that we could do a *much* better job of input validation
    unsigned int b = (unsigned int)strtoul(argv[1], NULL, 10);
    unsigned int n = (unsigned int)strtoul(argv[2], NULL, 10);
    unsigned int m = (unsigned int)strtoul(argv[3], NULL, 10);

    printf("b: %u \t n: %u \t m: %u\n", b, n, m);

    unsigned int x = 1;
    unsigned int power = b % m;

    // first we need the number of bits in n
    unsigned int k = (unsigned int)(1.0 + log2((double)n));

    for (unsigned int i = 0; i < k; i++)
    {
        if ((1 << i) & n)
        {
            x = (x * power) % m;
        }
        power = (power * power) % m;
        // printf("i: %u \t a_i: %u \t x: %u   \t power: %u\n", i, (bool)((1 << i) & n), x, power);
    }

    printf("Final x: %u\n", x);

    return 0;
}