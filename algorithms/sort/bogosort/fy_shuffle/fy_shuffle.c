#include "fy_shuffle.h"

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