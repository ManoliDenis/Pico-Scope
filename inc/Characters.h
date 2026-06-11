#ifndef CHARACTERS_H_
#define CHARACTERS_H_
 
#include <stdio.h>
#include "pico/stdlib.h"

/** @brief: Characters and Fonts for RENDERMAP */

#define CHAR_SIZE_X 5
#define CHAR_SIZE_Y 5


extern const uint8_t NUMBER_ZERO[25];
extern const uint8_t NUMBER_ONE[25];
extern const uint8_t NUMBER_TWO[25];
extern const uint8_t NUMBER_THREE[25];
extern const uint8_t NUMBER_FOUR[25];
extern const uint8_t NUMBER_FIVE[25];
extern const uint8_t NUMBER_SIX[25];
extern const uint8_t NUMBER_SEVEN[25];
extern const uint8_t NUMBER_EIGHT[25];
extern const uint8_t NUMBER_NINE[25];
extern const uint8_t LETTER_A[25];
extern const uint8_t LETTER_B[25];
extern const uint8_t LETTER_C[25];
extern const uint8_t LETTER_D[25];
extern const uint8_t LETTER_E[25];
extern const uint8_t LETTER_F[25];
extern const uint8_t LETTER_G[25];
extern const uint8_t LETTER_H[25];
extern const uint8_t LETTER_I[25];
extern const uint8_t LETTER_J[25];
extern const uint8_t LETTER_K[25];
extern const uint8_t LETTER_L[25];
extern const uint8_t LETTER_M[25];
extern const uint8_t LETTER_N[25];
extern const uint8_t LETTER_O[25];
extern const uint8_t LETTER_P[25];
extern const uint8_t LETTER_Q[25];
extern const uint8_t LETTER_R[25];
extern const uint8_t LETTER_S[25];
extern const uint8_t LETTER_T[25];
extern const uint8_t LETTER_U[25];
extern const uint8_t LETTER_V[25];
extern const uint8_t LETTER_W[25];
extern const uint8_t LETTER_X[25];
extern const uint8_t LETTER_Y[25];
extern const uint8_t LETTER_Z[25];


const uint8_t* NUMBER(uint8_t num);
const uint8_t* LETTER(uint8_t ltr);

#endif