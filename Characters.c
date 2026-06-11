#include "Characters.h"

const uint8_t NUMBER_ZERO[] = {
    0, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 0
};

const uint8_t NUMBER_ONE[] = {
    0, 0, 1, 0, 0,
    0, 1, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 1, 1, 1, 0
};

const uint8_t NUMBER_TWO[] = {
    0, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    0, 0, 0, 1, 0,
    0, 0, 1, 0, 0,
    1, 1, 1, 1, 1
};

 const uint8_t NUMBER_THREE[25] = {
    1,1,1,1,1,
    0,0,0,0,1,
    0,0,1,1,0,
    0,0,0,0,1,
    1,1,1,1,1
};

 const uint8_t NUMBER_FOUR[25] = {
    1,1,0,0,0,
    1,1,0,1,1,
    1,1,1,1,1,
    0,0,0,1,1,
    0,0,0,1,1
};

 const uint8_t NUMBER_FIVE[25] = {
    1,1,1,1,1,
    1,0,0,0,0,
    1,1,1,1,0,
    0,0,0,0,1,
    1,1,1,1,0
};

 const uint8_t NUMBER_SIX[25] = {
    0,1,1,1,0,
    1,0,0,0,0,
    1,1,1,1,0,
    1,0,0,0,1,
    0,1,1,1,0
};

 const uint8_t NUMBER_SEVEN[25] = {
    1,1,1,1,1,
    0,0,0,0,1,
    0,0,0,1,0,
    0,0,1,0,0,
    0,1,0,0,0
};

 const uint8_t NUMBER_EIGHT[25] = {
    0,1,1,1,0,
    1,0,0,0,1,
    0,1,1,1,0,
    1,0,0,0,1,
    0,1,1,1,0
};

 const uint8_t NUMBER_NINE[25] = {
    0,1,1,1,0,
    1,0,0,0,1,
    0,1,1,1,1,
    0,0,0,0,1,
    0,1,1,1,0
};

const uint8_t LETTER_A[25] = {
    0, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1
};

const uint8_t LETTER_B[25] = {
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 0
};

const uint8_t LETTER_C[25] = {
    0, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    0, 1, 1, 1, 1
};

const uint8_t LETTER_D[25] = {
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 0
};

const uint8_t LETTER_E[25] = {
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 1
};

const uint8_t LETTER_F[25] = {
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0
};

const uint8_t LETTER_G[25] = {
    0, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 0, 0, 1, 1,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 1
};

const uint8_t LETTER_H[25] = {
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1
};

const uint8_t LETTER_I[25] = {
    0, 1, 1, 1, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 1, 1, 1, 0
};

const uint8_t LETTER_J[25] = {
    0, 0, 0, 1, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 0
};

const uint8_t LETTER_K[25] = {
    1, 0, 0, 0, 1,
    1, 0, 0, 1, 0,
    1, 1, 1, 0, 0,
    1, 0, 0, 1, 0,
    1, 0, 0, 0, 1
};

const uint8_t LETTER_L[25] = {
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 1
};

const uint8_t LETTER_M[25] = {
    1, 0, 0, 0, 1,
    1, 1, 0, 1, 1,
    1, 0, 1, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1
};

const uint8_t LETTER_N[25] = {
    1, 0, 0, 0, 1,
    1, 1, 0, 0, 1,
    1, 0, 1, 0, 1,
    1, 0, 0, 1, 1,
    1, 0, 0, 0, 1
};

const uint8_t LETTER_O[25] = {
    0, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 0
};

const uint8_t LETTER_P[25] = {
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0
};

const uint8_t LETTER_Q[25] = {
    0, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 0, 1, 0, 1,
    1, 0, 0, 1, 0,
    0, 1, 1, 0, 1
};

const uint8_t LETTER_R[25] = {
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 0,
    1, 0, 1, 0, 0,
    1, 0, 0, 1, 1
};

const uint8_t LETTER_S[25] = {
    0, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 0, 1,
    1, 1, 1, 1, 0
};

const uint8_t LETTER_T[25] = {
    1, 1, 1, 1, 1,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0
};

const uint8_t LETTER_U[25] = {
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 0
};

const uint8_t LETTER_V[25] = {
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    0, 1, 0, 1, 0,
    0, 0, 1, 0, 0
};

const uint8_t LETTER_W[25] = {
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 1, 0, 1,
    1, 1, 0, 1, 1,
    1, 0, 0, 0, 1
};

const uint8_t LETTER_X[25] = {
    1, 0, 0, 0, 1,
    0, 1, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 1, 0, 1, 0,
    1, 0, 0, 0, 1
};

const uint8_t LETTER_Y[25] = {
    1, 0, 0, 0, 1,
    0, 1, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0
};

const uint8_t LETTER_Z[25] = {
    1, 1, 1, 1, 1,
    0, 0, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 1, 0, 0, 0,
    1, 1, 1, 1, 1
};

const uint8_t* LETTER(uint8_t ltr)
{
    switch(ltr)
    {
        case 'A': case 'a': return LETTER_A;
        case 'B': case 'b': return LETTER_B;
        case 'C': case 'c': return LETTER_C;
        case 'D': case 'd': return LETTER_D;
        case 'E': case 'e': return LETTER_E;
        case 'F': case 'f': return LETTER_F;
        case 'G': case 'g': return LETTER_G;
        case 'H': case 'h': return LETTER_H;
        case 'I': case 'i': return LETTER_I;
        case 'J': case 'j': return LETTER_J;
        case 'K': case 'k': return LETTER_K;
        case 'L': case 'l': return LETTER_L;
        case 'M': case 'm': return LETTER_M;
        case 'N': case 'n': return LETTER_N;
        case 'O': case 'o': return LETTER_O;
        case 'P': case 'p': return LETTER_P;
        case 'Q': case 'q': return LETTER_Q;
        case 'R': case 'r': return LETTER_R;
        case 'S': case 's': return LETTER_S;
        case 'T': case 't': return LETTER_T;
        case 'U': case 'u': return LETTER_U;
        case 'V': case 'v': return LETTER_V;
        case 'W': case 'w': return LETTER_W;
        case 'X': case 'x': return LETTER_X;
        case 'Y': case 'y': return LETTER_Y;
        case 'Z': case 'z': return LETTER_Z;
        default: return LETTER_A;
    }
}

const uint8_t* NUMBER(uint8_t num)
{
    switch(num)
    {
        case 0:
            return NUMBER_ZERO;
        break;
        case 1:
            return NUMBER_ONE;
        break;

        case 2:
            return NUMBER_TWO;
        break;

        case 3:
            return NUMBER_THREE;
        break;

        case 4:
            return NUMBER_FOUR;
        break;

        case 5:
            return NUMBER_FIVE;
        break;

        case 6: 
            return NUMBER_SIX;
        break;

        case 7:
            return NUMBER_SEVEN;
        break;

        case 8:
            return NUMBER_EIGHT;
        break;

        case 9:
            return NUMBER_NINE;
        break;

        default:
            return NUMBER_ZERO;
        break;
    }
}