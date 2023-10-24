/**
 * @file bubblesort.c
 * @author Walt Jacob
 * @brief Bubblesort example
 * @date 2023-10-19
 *
 * @copyright Copyright Walter Jacob (c) 2023
 *
 * @details To build it with gcc with plenty of optimization, run
 *              gcc -O3 bubblesort.c -o bubble
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
    char arr[] = {'d', 'f', 'k', 'm', 'a', 'b'};
    unsigned int array_size = (unsigned int)(sizeof(arr) / sizeof(arr[0]));

    // Display the array before we start
    printf("Before first loop: ");
    print_array(arr, sizeof(arr) / sizeof(arr[0]));

    for (unsigned int i = 0; i < (array_size - 1); i++)
    {
        // printf("i = %u\n", i);
        for (unsigned int j = 0; j < (array_size - (i + 1)); j++)
        {
            // printf("j = %u\n", j);
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        // Display the array at each iteration
        printf("     after loop %i: ", i + 1);
        print_array(arr, sizeof(arr) / sizeof(arr[0]));
    }

    return 0;
}