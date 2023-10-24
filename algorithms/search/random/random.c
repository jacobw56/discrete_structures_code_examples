/**
 * @file random.c
 * @author Walt Jacob
 * @brief Random search example
 * @date 2023-10-24
 *
 * @copyright Copyright Walter Jacob (c) 2023
 *
 * @details To build it with gcc with plenty of optimization, run
 *              gcc -O3 random.c -o random
 *          then run it from the command line with
 *              random c
 *          where c is the character you are looking for.
 */

#include <stdbool.h> // bool
#include <stdio.h>   // printf
#include <stdlib.h>  // rand, srand
#include <time.h>    // timespec

/* Get posix nsecs (C11) */
static long get_nanos(void)
{
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return (long)ts.tv_sec * 1000000000L + ts.tv_nsec;
}

/* Fisher–Yates shuffle */
void shuffle(char *array, unsigned int len)
{
    unsigned int currentIndex = (unsigned int)len, randomIndex;

    // While there remain elements to shuffle.
    for (currentIndex = len - 1; currentIndex > 0; currentIndex--)
    {
        // Pick a remaining element.
        randomIndex = rand() % (currentIndex + 1);

        // And swap it with the current element.
        char tmp = array[randomIndex];
        array[randomIndex] = array[currentIndex];
        array[currentIndex] = tmp;
    }
}

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
    /* initialize random seed: */
    srand(get_nanos());

    // here's a character array, we could make one for int arrays, etc.
    char arr[] = {'f', 'p', 't', 'v', 'w', 'y'};
    unsigned int array_size = (unsigned int)(sizeof(arr) / sizeof(arr[0]));
    char target = *argv[1];

    printf("Searching for %c in the array ", target);
    print_array(arr, sizeof(arr) / sizeof(arr[0]));

    bool found = false;
    shuffle(arr, array_size);
    // print_array(arr, array_size);
    while (array_size > 0)
    {
        if (arr[array_size - 1] == target)
        {
            found = true;
            break;
        }
        if (--array_size > 0)
        {
            shuffle(arr, array_size);
            // print_array(arr, array_size);
        }
    }

    if (found)
        printf("Found %c in array after %u iterations\n", target, (unsigned int)(sizeof(arr) / sizeof(arr[0])) - array_size + 1);
    else
        printf("Could not find %c in the array\n", target);

    return 0;
}