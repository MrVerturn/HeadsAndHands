/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b ){
    int buf;
    buf = *a;
    *a = *b;
    *b = buf;  
}

//сортировка масива  
int* sort(int input[], int count, bool revers = false){
    int i, j = 0, index;

    for( i = 0; i < count; i++ ){
        index = i;
        for( j = i; j < count; j++ ){
            if(revers){
                if( input[j] >= input[index]  ){
                    index = j;
                }
            }else{
                if( input[j] <= input[index]  ){
                    index = j;
                }                
            }
        }
        
        if( i != index ){
            swap( &input[i], &input[index] );
        }
    }
    return input;
}

//функция для генерации кол-ва елементов в массивах, заполнение массивов и сортировка (последний символ '-1' нужен для вывода в консоль без сохранения размеров)
int** initMas(int n){
    int **res = new int *[n];
    int lengths[n];
    int i, j;
    srand(time(NULL));
    
    //генерация кол-ва элементов в массивах
    for( i = 0; i < n; i++ ){
        lengths[i] = i+1;
    }
    
    for( i = 0; i < n*10; i++ ){
        swap( &lengths[rand() % (n)], &lengths[rand() % (n)] );
    }
    
    //заполнение каждого массива
    for( i = 0; i < n; i++ ){
        res[i] = new int[lengths[i] + 1];
        
        for( j = 0; j < lengths[i]; j++ ){
            res[i][j] = (rand() % 20 + 1);
        }
        
        res[i][lengths[i]] = -1; 
    }
    
    //сортировка массивов
    for( i = 0; i < n; i++ ){
          if( (i % 2) == 0 ){
            res[i] = sort(res[i], lengths[i]); 
        }
        else{
            res[i] = sort(res[i], lengths[i], true);           
        }
    }
    
    return res;
}

//функция входа
int main()
{
    int count = 10;
    int i, j;
    
    //заполнение массива
    int **res =  initMas(count);
    
    //вывод результата
    for( i = 0; i < count; i++ ){
        j = 0;
        printf("%d =", i);    
        while(res[i][j] != -1){
            printf(" %d", res[i][j]);
            j++;
        };
        printf("_\n");
    }
    
    return 0;
}
