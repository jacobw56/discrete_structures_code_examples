/**
 * @file selectionsort.c
 * @author Walt Jacob
 * @brief Selection sort example
 * @date 2023-10-19
 *
 * @copyright Copyright Walter Jacob (c) 2023
 *
 * @details To build it with gcc with plenty of optimization, run
 *              gcc -O3 selectionsort.c -o selection
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

void selection_inc(char *arr, unsigned int len)
{
    for (unsigned int i = 0; i < len - 1; i++)
    {
        char key = arr[i];
        unsigned int idx = i;
        for (unsigned int j = i + 1; j < len; j++)
        {
            if (arr[j] < key)
            {
                key = arr[j];
                idx = j;
            }
        }
        arr[idx] = arr[i];
        arr[i] = key;
        printf("     after loop %i: ", i + 1);
        print_array(arr, len);
    }
}

int main(void)
{
    // here's a character array, we could make one for int arrays, etc.
    char arr1[] = {'d', 'm', 'f', 'k', 'a', 'b'};
    char arr2[] = {'d', 'm', 'f', 'k', 'a', 'b'};
    unsigned int array_size = (unsigned int)(sizeof(arr1) / sizeof(arr1[0]));

    // Display the array before we start
    printf("Increasing:\n");
    printf("Before first loop: ");
    print_array(arr1, array_size);

    selection_inc(arr1, array_size);

    return 0;
}