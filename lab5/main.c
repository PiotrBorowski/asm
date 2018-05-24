#include <stdio.h>
#include <stdlib.h>

struct Vector{
    float number[4];
};

/*
    

*/
float countDet(struct Vector mat[4])
{
    struct Vector temp;
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
        "mulps %%xmm0, %%xmm3\n"

        //wynik w xmm3
        "subps %%xmm1, %%xmm3\n"

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

        "shufps $0b00000111, %%xmm0, %%xmm0\n" 
        "shufps $0b00001110, %%xmm2, %%xmm2\n"
        "mulps %%xmm0, %%xmm2\n"
        //wynik w xmm2

        //roznica  wynik w xmm2
        "subps %%xmm1, %%xmm2\n"
        
        //macierz D c i d
        //(0,0,0,0)
        //(0,0,2,1)
        //(0,0,2,1)
        //(0,0,0,0)
        "movups (%2), %%xmm0\n"
        "movups (%3), %%xmm1\n"

        "shufps $0b00000000, %%xmm0, %%xmm0\n"
        "shufps $0b00001001, %%xmm1, %%xmm1\n"
        "mulps %%xmm0, %%xmm1\n"
        //wynik w xmm1

        "movups (%2), %%xmm0\n"
        "movups (%3), %%xmm4\n"

        "shufps $0b00000000, %%xmm4, %%xmm4\n"
        "shufps $0b00001001, %%xmm0, %%xmm0\n"
        "mulps %%xmm0, %%xmm4\n"
        //wynik w xmm4

        "subps %%xmm1, %%xmm4\n"

        //mnozenie C razy D wynik w xmm4
        "mulps %%xmm2, %%xmm4\n"

        //wynik
        "addps %%xmm3, %%xmm4\n"
        "movups %%xmm4, (%4)\n" //do temp

        :
        : "r" (mat[0].number), "r" (mat[1].number),  "r" (mat[2].number),  "r" (mat[3].number), "r" (temp.number)  
    );

    return temp.number[0] + temp.number[1] + temp.number[2] + temp.number[3];
}

void printVector(struct Vector vec){
    printf("%f %f %f %f\n",vec.number[0], vec.number[1],vec.number[2],vec.number[3]);
} 

int main()
{
    struct Vector matrix[4];
    float det;

    float data[16] = {
        1,0,2,0,
        0,1,3,7,
        1,0,1,0,
        0,1,0,1
    };

    for(int i = 0, j = 0; i<4; i++, j+=4)
    {
        matrix[i].number[0] = data[j];
        matrix[i].number[1] = data[j+1];
        matrix[i].number[2] = data[j+2];
        matrix[i].number[3] = data[j+3];   
        printVector(matrix[i]);     
    }


    printf("Wyznacznik = %f\n", countDet(matrix));
}