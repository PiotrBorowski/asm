#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct Vector{
    int a, b, c, d;
};

struct Vector Array[2048];







int main(){
    srand(time(NULL));
    FILE *file = fopen("wyniki.txt", "w");
    if(file == NULL){
        printf("FILE ERROR");
        exit(2);
    }



    return 0;
}