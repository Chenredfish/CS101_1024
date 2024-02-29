#include <stdio.h>

void print_sp(int n, int m){
    for(int j=0; j<=m-n; j++){
        printf(" ");
    }
    
}


void print_num(int n){
    for(int j=1; j<=n; j++){
        printf("%d ", n);
    }
    printf("\n");
}


int main()
{
    int  rows=6;
    for(int i=1; i<=rows; i++){
        print_sp(i, rows);
        print_num(i);
    }
    return 0;
}
