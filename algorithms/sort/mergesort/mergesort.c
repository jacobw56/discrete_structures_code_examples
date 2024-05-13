/**
 * @file mergesort.c
 * @author Walt Jacob
 * @brief Merge sort example
 * @date 2023-10-19
 *
 * @copyright Copyright Walter Jacob (c) 2023
 *
 * @details To build it with gcc with plenty of optimization, run
 *              gcc -O3 mergesort.c -o merge
 */

#include <stdio.h> // printf

#define MAX_ARRAY_SIZE 100
static char left[MAX_ARRAY_SIZE], right[MAX_ARRAY_SIZE];

void print_array(char *arr, size_t len)
{
    for (unsigned int i = 0; i < len; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void merge(char *arr, unsigned int mid, unsigned int len)
{
    unsigned int i, j = 0, k = 0;
    for (i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (i = 0; i < len - mid; i++)
    {
        right[i] = arr[mid + i];
    }
    i = 0;
    while ((i < mid) && (j < len - mid))
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < mid)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < len - mid)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort_inc(char *arr, unsigned int len)
{
    if (len > 1)
    {
        unsigned int m = (unsigned int)(len / 2);
        merge_sort_inc(arr, m);
        merge_sort_inc(&arr[m], len - m);
        merge(arr, m, len);
    }
    printf("After loop with length %u:\n", len);
    print_array(arr, (size_t)len);
}

int main(void)
{
    // here's a character array, we could make one for int arrays, etc.
    char arr1[13] = {'d', 'm', 'f', 'k', 'a', 'b', 'l', 'p', 'q', 'c', 'z', 'w', 'g'};
    unsigned int array_size = (unsigned int)(sizeof(arr1) / sizeof(arr1[0]));

    // Display the array before we start
    printf("Increasing:\n");
    printf("Before first loop: ");
    print_array(arr1, array_size);

    merge_sort_inc(arr1, array_size);

    return 0;
}