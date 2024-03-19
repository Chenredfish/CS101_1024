#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int input=0, seed = 1;
    time_t Time, curtime;
    time(&curtime);
    Time = time(NULL);
    seed = Time%10;
    FILE* file;
    
    
    srand(seed);
    printf("請輸入你要購買的樂透彩數量：");
    scanf("%d", &input);
    
    printf("你購買的%d組特透號碼儲存至lotto.txt\n", input);
    
    
    file = fopen("lotto.txt", "w+");
    
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
    return 0;
}
