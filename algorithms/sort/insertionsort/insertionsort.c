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

void insertion_inc_recursive(char *arr, unsigned int len)
{
    if (len == 1)
        return;
    insertion_inc_recursive(arr, len - 1);
    char key = arr[len - 1];
    int j = len - 2;
    while (j > -1 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
    printf("     after loop %i: ", len);
    print_array(arr, len);
}

void insertion_inc(char *arr, unsigned int len)
{
    for (unsigned int i = 1; i < len; i++)
    {
        char key = arr[i];
        int j = i - 1;
        while (j > -1 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("     after loop %i: ", i);
        print_array(arr, len);
    }
}

void insertion_dec(char *arr, unsigned int len)
{
    for (unsigned int i = 1; i < len; i++)
    {
        char key = arr[i];
        int j = i - 1;
        while (j > -1 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("     after loop %i: ", i);
        print_array(arr, len);
    }
}

int main(void)
{
    // here's a character array, we could make one for int arrays, etc.
    char arr1[] = {'d', 'm', 'f', 'k', 'a', 'b'};
    char arr2[] = {'d', 'm', 'f', 'k', 'a', 'b'};
    char arr3[] = {'d', 'm', 'f', 'k', 'a', 'b'};
    unsigned int array_size = (unsigned int)(sizeof(arr1) / sizeof(arr1[0]));

    // Display the array before we start
    printf("Increasing:\n");
    printf("Before first loop: ");
    print_array(arr1, array_size);

    insertion_inc(arr1, array_size);

    printf("\nDecreasing:\n");
    printf("Before first loop: ");
    print_array(arr2, array_size);
    insertion_dec(arr2, array_size);

    printf("\nIncreasing, recursive:\n");
    printf("Before first loop: ");
    print_array(arr3, array_size);
    insertion_inc_recursive(arr3, array_size);

    return 0;
}