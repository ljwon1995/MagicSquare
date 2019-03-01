#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

typedef struct{
    int row;
    int col;
}LOC;

void PrintSquare(int square[][MAX_SIZE], int size){
    int row, col;
    printf("Print Magic Square!\n\n");
    for(row = 0; row < size; row++){
        for(col = 0; col < size; col++)
            printf("%5d", square[row][col]);
        printf("\n");
    }
}

void FillSquare(int square[][MAX_SIZE], int size, int curNum, LOC curLoc){//find next location to fill compared with curLoc and fill the curNum.
    if(curNum == (size * size) + 1){
        return;
    }
    
    
    
    else{
        curLoc.row = ((curLoc.row - 1) < 0) ? (size - 1) : (curLoc.row - 1);
        curLoc.col = ((curLoc.col - 1) < 0) ? (size - 1) : (curLoc.col - 1);
        if(square[curLoc.row][curLoc.col]){//occupied.
            curLoc.row = (curLoc.row + 2) % size;
            curLoc.col = (curLoc.col + 1) % size;
        }
        square[curLoc.row][curLoc.col] = curNum;
        FillSquare(square, size, curNum + 1, curLoc);
        
    }
}

void InitSquare(int square[][MAX_SIZE], int size){
    int row, col;
    
    for(row = 0; row < size; row++)
        for(col = 0; col < size; col++)
            square[row][col] = 0;
    
}

int IsAcceptable(int size){ //return 1 to right, return -1 out of range, return -2 for even
    
    if(size > MAX_SIZE || size < 1){
        return -1;
    }
    
    else if(size % 2 == 0){
        return -2;
    }
    
    else{
        return 1;
    }
    
}

int GetSquareSizeByUser(){
    int size;
    
    printf("Enter the size of the square: ");
    scanf("%d", &size);
    switch(IsAcceptable(size)){
        case 1:
            return size;
            break;
        case -1:
            fprintf(stderr, "ERROR! Size is out of range\n");
            exit(EXIT_FAILURE);
            break;
        case -2:
            fprintf(stderr, "ERROR! Size is even\n");
            exit(EXIT_FAILURE);
            break;
            
    }
    fprintf(stderr, "ERROR! Abnormal exit in GetSquareSizeByUser()\n");
    exit(EXIT_FAILURE);
    
}

int main(){
    int square[MAX_SIZE][MAX_SIZE];
    int size;
    LOC curLoc;
    
    size = GetSquareSizeByUser();
    InitSquare(square, size);
    curLoc.row = 0;
    curLoc.col = (size - 1)/2;
    square[curLoc.row][curLoc.col] = 1;
    FillSquare(square, size, 2, curLoc);
    PrintSquare(square, size);
    
    
}
