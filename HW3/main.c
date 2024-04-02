#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char record(){
    FILE* file;
    char filename[] = "record.bin";
    file = fopen(filename, "rb+");
    char num[1];
    fread(num, sizeof(char), 1, file);
    fseek(file, 0, SEEK_SET);
    num[0]+=1;
    fwrite(num, sizeof(char), 1, file);
    fclose(file);
    return num[0];
}

void buy(int input){
    
    int seed = 1;
    char num[1], filename[100]="lotto";
    time_t Time, curtime;
    time(&curtime);
    Time = time(NULL);
    seed = Time%10;
    FILE* file;
    srand(seed);
    
    num[0] = record();
    printf("你購買的%d組特透號碼儲存至lotto%d.txt\n", input, num[0]-48);
    strcat(filename, num);
    strcat(filename, ".txt");
    file = fopen(filename, "w+");
    
    char *arr_time = ctime(&curtime);
    fwrite(arr_time, sizeof(char), 30, file);
    
    for(int i=0; i<input; i++){
        fwrite("\n", sizeof(char), 2, file);
        for(int j=0; j<7; j++){
            int num = rand()%70;
            //printf("%d ", num);
            char arr_write[3] = {(num/10)+48,(num%10)+48, 0};
            fwrite(arr_write, sizeof(char), 3, file);
        }
        //printf("\n");
    }
    fclose(file);
}

void check(){
    
}

int main()
{
    int input=0;
    
    printf("請輸入你要購買的樂透彩數量：");
    scanf("%d", &input);
    
    if(input){
        buy(input);
    }
    else{
        check;
    }
    return 0;
}
