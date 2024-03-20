#include <stdio.h>
#include <string.h>

int main()
{
    FILE *out, *in;
    char name[]="main2.c";
    char c[10],end[]="m";
    int a=12, line=1;
    
    in = fopen("main.txt", "w+");
    out = fopen("main.c", "r+");
    
    fseek(out, 0, SEEK_END);
    int len = ftell(out);
    fseek(out, 0, SEEK_SET);
    
    
    for(int i=1; i<len; i++){
        fgets(c,sizeof(char)*2, out);
        fputs(c, in);
        if(strstr(c, "m")){
            printf("%d", line);
            break;
        }
        if(strstr(c, "\n")){
            line+=1;
        }
        fseek(out, i, SEEK_SET);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}
