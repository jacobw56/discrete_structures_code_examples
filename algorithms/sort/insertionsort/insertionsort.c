/**
 * @file insertionsort.c
 * @author Walt Jacob
 * @brief Insertionsort example
 * @date 2023-10-19
 *
 * @copyright Copyright Walter Jacob (c) 2023
 *
 * @details To build it with gcc with plenty of optimization, run
 *              gcc -O3 insertionsort.c -o insertion
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

int main(void)
{
    // here's a character array, we could make one for int arrays, etc.
    char arr[] = {'d', 'm', 'f', 'k', 'a', 'b'};
    unsigned int array_size = (unsigned int)(sizeof(arr) / sizeof(arr[0]));

    // Display the array before we start
    printf("Before first loop: ");
    print_array(arr, sizeof(arr) / sizeof(arr[0]));

    for (unsigned int j = 1; j < array_size; j++)
    {
        unsigned int i = 0;
        while (arr[j] > arr[i])
        {
            i++;
        }
        char temp = arr[j];
        for (unsigned int k = 0; k < j - i; k++)
        {
            arr[j - k] = arr[j - k - 1];
        }
        arr[i] = temp;

        // Display the array at each iteration
        printf("     after loop %i: ", j);
        print_array(arr, sizeof(arr) / sizeof(arr[0]));
    }

    return 0;
}