/**
 * @file fy_shuffle.h
 * @author Walt Jacob (jacobw56@gmail.com)
 * @brief Fisher-Yates shuffle
 * @date 2024-05-20
 *
 * @copyright Copyright (c) 2023
 *
 * @details Refactored FY shuffle to show how to build static libraries.
 *
 */
#ifndef _FY_H_
#define _FY_H_

#include <stdlib.h> // rand, srand

/* Fisher–Yates shuffle */
void shuffle(int *array, size_t len);

#endif // _FY_H_