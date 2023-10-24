/**
 * @file bogosort.c
 * @author Walt Jacob
 * @brief Bogosort example
 * @date 2023-10-17
 *
 * @copyright Copyright Walter Jacob (c) 2023
 *
 * @details To build it with gcc with plenty of optimization, run
 *              gcc -O3 bogosort.c -o bogo
 *          Run times start to get insane with 13 elements on very fast
 *          hardware in 2023.
 */

#include <limits.h>  // INT_MAX
#include <stdbool.h> // bool
#include <stdio.h>   // printf
#include <stdlib.h>  // rand, srand
#include <time.h>    // timespec

#define ARRAY_SIZE 10 /*<< Set your array size here! Careful though... */

/* Get posix nsecs (C11) */
static long get_nanos(void)
{
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return (long)ts.tv_sec * 1000000000L + ts.tv_nsec;
}

/* Fisher–Yates shuffle */
void shuffle(int *array, size_t len)
{
    unsigned int currentIndex = (unsigned int)len, randomIndex;

    // While there remain elements to shuffle.
    for (currentIndex = len - 1; currentIndex > 0; currentIndex--)
    {
        // Pick a remaining element.
        randomIndex = rand() % (currentIndex + 1);

        // And swap it with the current element.
        int tmp = array[randomIndex];
        array[randomIndex] = array[currentIndex];
        array[currentIndex] = tmp;
    }
}

/* Sort check */
bool check(int *array, size_t len)
{
    for (unsigned int i = 0; i < len - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}

/* pretty-ish print int array */
void print_array(int *array, size_t len)
{
    for (unsigned int i = 0; i < len; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

int main()
{
    /* initialize random seed: */
    srand(get_nanos());

    // Add one element at a time to see the time explode
    int arr[ARRAY_SIZE];
    unsigned long long int count = 0;

    // Populate array
    for (unsigned int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    // Let monkeys shuffle until they are in order
    while (check(arr, ARRAY_SIZE) == false)
    {
        count++;
        shuffle(arr, ARRAY_SIZE);
    }

    // How long did that take? Also verify
    printf("count: %llu\n", count);
    print_array(arr, ARRAY_SIZE);

    return 0;
}