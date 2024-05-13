/**
 * @file linear.c
 * @author Walt Jacob
 * @brief linear search example
 * @date 2023-10-24
 *
 * @copyright Copyright Walter Jacob (c) 2023
 *
 * @details To build it with gcc with plenty of optimization, run
 *              gcc -O3 linear.c -o linear
 *          then run it from the command line with
 *              linear c
 *          where c is the character you are looking for.
 *          First, the program does a linear search with a while loop. Then, it
 *          does the same thing with a for loop. This provides a nice example
 *          of the compiled differences between the two types of loop. Regardless
 *          of the compiler optimization option chosen, you will see that the
 *          while loop is fewer instructions and branches. The difference is
 *          minimal, however, and if your code is clearer with a for loop, then
 *          you should choose that option unless you definitely, really, have a
 *          good reason to think you know better.
 */

#include <stdio.h> // printf

int lin_search_while(char c, char *arr, unsigned int len)
{
    int ret = -1;
    int i = 0;

    while (arr[i] != c && i++ < len)
        ;

    if (i < len)
    {
        ret = i;
    }

    return ret;
}

int lin_search_for(char c, char *arr, unsigned int len)
{
    int ret = -1;
    int i;

    for (i = 0; arr[i] != c && i < len; i++)
        ;

    if (i < len)
    {
        ret = i;
    }

    return ret;
}

void print_result(char c, int idx)
{
    if (idx < 0)
    {
        printf("character %c not found in A\n", c);
    }
    else
    {
        printf("character %c found at index %i in A\n", c, idx);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid argument list!\n");
        return 1;
    }

    char target = *argv[1];
    char array[] = {88, 39, 33, 35, 90, 96, 46, 96, 43, 82, 91, 40}; // Random printable ASCII characters
    unsigned int array_size = (unsigned int)sizeof(array) / sizeof(array[0]);

    // while loop version
    print_result(target, lin_search_while(target, array, array_size));

    // for loop version
    print_result(target, lin_search_for(target, array, array_size));

    return 0;
}