#include <stdio.h>
#include <stdlib.h>

struct Vector{
    float number[4];
};

/*
    

*/
float countDet(struct Vector mat[4])
{
    asm(
        //macierz A a i b
        //(1,0,2,0)
        //(2,3,0,1)
        //(2,3,0,1)
        //(1,0,2,0)

        //mnozenie 2 pierwszych wierszy wynik w xmm1
        "movups (%0), %%xmm0\n"
        "movups (%1), %%xmm1\n"
        
        "shufps $0b01001000, %%xmm0, %%xmm0\n"
        "shufps $0b10110001, %%xmm1, %%xmm1\n"
        "mulps %%xmm0, %%xmm1\n"

        //mnozenie 3 i 4 wiersza wynik w xmm2
        "movups (%0), %%xmm0\n"
        "movups (%1), %%xmm2\n"

        "shufps $0b10110001, %%xmm0, %%xmm0\n"
        "shufps $0b01001000, %%xmm2, %%xmm2\n"
        "mulps %%xmm0, %%xmm2\n"

        //roznica xmm1 i xmm2 wynik w xmm2
        "subps %%xmm1, %%xmm2\n"

        //macierz B c i d
        //(0,1,1,2)
        //(3,2,3,3)
        //(3,2,3,3)
        //(0,1,1,2)

        //analogicznie jak w A

        "movups (%2), %%xmm0\n"
        "movups (%3), %%xmm1\n"
        "shufps $0b00010110, %%xmm0, %%xmm0\n"
        "shufps $0b11101111, %%xmm1, %%xmm1\n"
        "mulps %%xmm0, %%xmm1\n"

        "movups (%2), %%xmm0\n"
        "movups (%3), %%xmm3\n"

        "shufps $0b11101111, %%xmm0, %%xmm0\n"
        "shufps $0b00010110, %%xmm3, %%xmm3\n"
        "mulps %%xmm0, %%xmm3"

        //wynik w xmm3
        "subps %%xmm1, %%xmm3"

        //mnozenie A i B WYNIK w xmm3
        "mulps %%xmm2, %%xmm3\n"


        //macierz C a i b
        //(0,0,3,2)
        //(0,0,1,3)
        //(0,0,1,3)
        //(0,0,3,2)

        "movups (%0), %%xmm0\n"
        "movups (%1), %%xmm1\n"

        "shufps $0b00001110, %%xmm0, %%xmm0\n"
        "shufps $0b00000111, %%xmm1, %%xmm1\n"
        "mulps %%xmm0, %%xmm1\n"
        //wynik w xmm1


        "movups (%0), %%xmm0\n"
        "movups (%1), %%xmm2\n"

        "shufps $0b00000111, %%xmm0, %%xmm0" 
        "shufps $0b00001110, %%xmm2, %%xmm2"
          
        //macierz D c i d
        //(0,0,0,0)
        //(0,0,2,1)
        //(0,0,2,1)
        //(0,0,0,0)
    );
}

int main()
{
    struct Vector matrix[4];
    float det;

    float data[16] = {
        1,4,5,3,
        5,2,7,1,
        9,4,2,7,
        9,9,3,9
    };

    for(int i = 0, j = 0; i<4; i++, j+=4)
    {
        matrix[i].number[0] = data[j];
        matrix[i].number[1] = data[j+1];
        matrix[i].number[2] = data[j+2];
        matrix[i].number[3] = data[j+3];        
    }

    printf("Wyznacznik = %f", countDet(matrix));
}