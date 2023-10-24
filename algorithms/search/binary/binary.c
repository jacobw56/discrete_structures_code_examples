/**
 * @file binary.c
 * @author Walt Jacob
 * @brief Binary search example
 * @date 2023-10-24
 *
 * @copyright Copyright Walter Jacob (c) 2023
 *
 * @details To build it with gcc with plenty of optimization, run
 *              gcc -O3 binary.c -o binary
 *          then run it from the command line with
 *              binary c
 *          where c is the character you are looking for.
 */

#include <stdio.h> // printf

void print_array(char *arr, size_t len)
{
    for (unsigned int i = 0; i < len; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    // here's a character array, we could make one for int arrays, etc.
    char arr[] = {'f', 'p', 't', 'v', 'w', 'y'};
    unsigned int array_size = (unsigned int)(sizeof(arr) / sizeof(arr[0]));
    char target = *argv[1];

    printf("Searching for %c in the array ", target);
    print_array(arr, sizeof(arr) / sizeof(arr[0]));

    unsigned int i = 0;
    unsigned int j = array_size - 1;
    while (i < j)
    {
        unsigned int temp = (i + j) / 2;
        if (target > arr[temp])
            i = temp + 1;
        else
            j = temp;
    }

    if (target == arr[i])
        printf("Found %c at location %u\n", target, i);
    else
        printf("Could not find %c in the array\n", target);

    return 0;
}