#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct Vector{
    int a, b, c, d;
};


struct Vector Array[2048];

// 4 * 2048 = 8192 liczb

void generate()
{
    for(int i = 0; i < 2048; i++)
    {
        Array[i].a = rand()%100000 + 1; 
        Array[i].b = rand()%100000 + 1; 
        Array[i].c = rand()%100000 + 1; 
        Array[i].d = rand()%100000 + 1; 
    }
}

void printVector(struct Vector vec){
    printf("%d %d %d %d\n",vec.a, vec.b,vec.c,vec.d);
} 

struct Vector ADD_SIMD(int numberOfNumbers)
{   
    double Time = 0;
    struct Vector x, y, result;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < numberOfNumbers / 4; j+=2)
        {
            x = Array[j];
            y = Array[j+1];

            clock_t start = clock();
            asm(
                "movups %1, %%xmm0 \n"
                "movups %2, %%xmm1 \n"
                "addps %%xmm1, %%xmm0 \n"
                "movups %%xmm0, %0 \n"
                : "=g"(result)
                : "g"(x), "g"(y)
            );
            clock_t stop = clock();
            Time += (double) (stop - start) / CLOCKS_PER_SEC;
           
        }
    }
    Time /= 10.0;
    printf("+ %lf\n", Time);
    return result;
}

struct Vector SUB_SIMD(int numberOfNumbers)
{   
    double Time = 0;
    struct Vector x, y, result;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < numberOfNumbers / 4; j+=2)
        {
            x = Array[j];
            y = Array[j+1];

            clock_t start = clock();
            asm(
                "movups %1, %%xmm0 \n"
                "movups %2, %%xmm1 \n"
                "subps %%xmm1, %%xmm0 \n"
                "movups %%xmm0, %0 \n"
                : "=g"(result)
                : "g"(x), "g"(y)
            );
            clock_t stop = clock();
            Time += (double) (stop - start) / CLOCKS_PER_SEC;
           
        }
    }
    Time /= 10.0;
    printf("- %lf\n", Time);
    return result;
}

struct Vector MUL_SIMD(int numberOfNumbers)
{   
    double Time = 0;
    struct Vector x, y, result;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < numberOfNumbers / 4; j+=2)
        {
            x = Array[j];
            y = Array[j+1];

            clock_t start = clock();
            asm(
                "movups %1, %%xmm0 \n"
                "movups %2, %%xmm1 \n"
                "mulps %%xmm1, %%xmm0 \n"
                "movups %%xmm0, %0 \n"
                : "=g"(result)
                : "g"(x), "g"(y)
            );
            clock_t stop = clock();
            Time += (double) (stop - start) / CLOCKS_PER_SEC;
           
        }
    }
    Time /= 10.0;
    printf("* %lf\n", Time);
    return result;
}

struct Vector DIV_SIMD(int numberOfNumbers)
{   
    double Time = 0;
    struct Vector x, y, result;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < numberOfNumbers / 4; j+=2)
        {
            x = Array[j];
            y = Array[j+1];

            clock_t start = clock();
            asm(
                "movups %1, %%xmm0 \n"
                "movups %2, %%xmm1 \n"
                "divps %%xmm1, %%xmm0 \n"
                "movups %%xmm0, %0 \n"
                : "=g"(result)
                : "g"(x), "g"(y)
            );
            clock_t stop = clock();
            Time += (double) (stop - start) / CLOCKS_PER_SEC;
           
        }
    }
    Time /= 10.0;
   // printVector(x);
    //printVector(y);
    //printVector(result);
    printf("/ %lf\n", Time);
    return result;
}

struct Vector ADD_SISD(int numberOfNumbers){
      
    double Time = 0;
    struct Vector x, y, result;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < numberOfNumbers / 4; j+=2)
        {
            x = Array[j];
            y = Array[j+1];

            clock_t start = clock();
            asm(
                "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "add %%ebx, %%eax \n"
                "mov %%eax, %0 \n"                
                : "=g"(result.a)
                : "g"(x.a), "g"(y.a)
            );
              asm(
               "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "add %%ebx, %%eax \n"
                "mov %%eax, %0 \n"
                : "=g"(result.b)
                : "g"(x.b), "g"(y.b)
            );
              asm(
                 "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "add %%ebx, %%eax\n"
                "mov %%eax, %0\n"
                : "=g"(result.c)
                : "g"(x.c), "g"(y.c)
            );
              asm(
                 "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "add %%ebx, %%eax \n"
                "mov %%eax, %0 \n"
                : "=g"(result.d)
                : "g"(x.d), "g"(y.d)
            );
            clock_t stop = clock();
            Time += (double) (stop - start) / CLOCKS_PER_SEC;
           // printVector(x);
           // printVector(y);
           // printVector(result);
        }
    }
    Time /= 10.0;
    //printVector(x);
    //printVector(y);
    //printVector(result);
    printf("+ %lf\n", Time);
    return result;
}

struct Vector SUB_SISD(int numberOfNumbers){
      
    double Time = 0;
    struct Vector x, y, result;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < numberOfNumbers / 4; j+=2)
        {
            x = Array[j];
            y = Array[j+1];

            clock_t start = clock();
            asm(
                "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "sub %%ebx, %%eax \n"
                "mov %%eax, %0 \n"                
                : "=g"(result.a)
                : "g"(x.a), "g"(y.a)
            );
              asm(
               "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "sub %%ebx, %%eax \n"
                "mov %%eax, %0 \n"
                : "=g"(result.b)
                : "g"(x.b), "g"(y.b)
            );
              asm(
                 "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "sub %%ebx, %%eax\n"
                "mov %%eax, %0\n"
                : "=g"(result.c)
                : "g"(x.c), "g"(y.c)
            );
              asm(
                 "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "sub %%ebx, %%eax \n"
                "mov %%eax, %0 \n"
                : "=g"(result.d)
                : "g"(x.d), "g"(y.d)
            );
            clock_t stop = clock();
            Time += (double) (stop - start) / CLOCKS_PER_SEC;
           // printVector(x);
           // printVector(y);
           // printVector(result);
        }
    }
    Time /= 10.0;
    printf("- %lf\n", Time);
    return result;
}
struct Vector MUL_SISD(int numberOfNumbers){
      
    double Time = 0;
    struct Vector x, y, result;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < numberOfNumbers / 4; j+=2)
        {
            x = Array[j];
            y = Array[j+1];

            clock_t start = clock();
            asm(
                "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "mul %%ebx \n"
                "mov %%eax, %0 \n"                
                : "=g"(result.a)
                : "g"(x.a), "g"(y.a)
            );
              asm(
               "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "mul %%ebx \n"
                "mov %%eax, %0 \n"
                : "=g"(result.b)
                : "g"(x.b), "g"(y.b)
            );
              asm(
                 "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "mul %%ebx \n"
                "mov %%eax, %0\n"
                : "=g"(result.c)
                : "g"(x.c), "g"(y.c)
            );
              asm(
                 "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "mul %%ebx \n"
                "mov %%eax, %0 \n"
                : "=g"(result.d)
                : "g"(x.d), "g"(y.d)
            );
            clock_t stop = clock();
            Time += (double) (stop - start) / CLOCKS_PER_SEC;
           // printVector(x);
           // printVector(y);
           // printVector(result);
        }
    }
    Time /= 10.0;
    printf("* %lf\n", Time);
    return result;
}
struct Vector DIV_SISD(int numberOfNumbers){
      
    double Time = 0;
    struct Vector x, y, result;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < numberOfNumbers / 4; j+=2)
        {
            x = Array[j];
            y = Array[j+1];

            clock_t start = clock();
            asm(
                "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "div %%ebx\n"
                "mov %%eax, %0 \n"                
                : "=g"(result.a)
                : "g"(x.a), "g"(y.a)
            );
              asm(
               "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "div %%ebx\n"
                "mov %%eax, %0 \n"
                : "=g"(result.b)
                : "g"(x.b), "g"(y.b)
            );
              asm(
                 "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "div %%ebx\n"
                "mov %%eax, %0\n"
                : "=g"(result.c)
                : "g"(x.c), "g"(y.c)
            );
              asm(
                 "mov %1, %%eax \n"
                "mov %2, %%ebx \n"
                "div %%ebx\n"
                "mov %%eax, %0 \n"
                : "=g"(result.d)
                : "g"(x.d), "g"(y.d)
            );
            clock_t stop = clock();
            Time += (double) (stop - start) / CLOCKS_PER_SEC;
           // printVector(x);
           // printVector(y);
           // printVector(result);
        }
    }
    Time /= 10.0;
    printf("/ %lf\n", Time);
    return result;
}
int main(){
    srand(time(NULL));
    //File * file = fopen("wyniki.txt", "w");
    //if(file == NULL){
       // printf("FILE ERROR");
        //exit(2);
    //}

    generate();


    for(int i = 2048; i<=8192;i*=2)
    {
        printf("Wyniki SIMD dla %d \n",i);
        printf("Sredni czas [s] \n");
        ADD_SIMD(i);
        SUB_SIMD(i);
        MUL_SIMD(i);
        DIV_SIMD(i);

        printf("Wyniki SISD dla %d \n", i);
        printf("Sredni czas [s] \n");
        ADD_SISD(i);
        SUB_SISD(i);
        MUL_SISD(i);
        DIV_SISD(i);
    }

    


    return 0;
}