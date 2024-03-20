#include <stdio.h>

int main()
{
    FILE *out, *in;
    char name[]="main2.c";
    char c[10];
    int a=12;
    
    in = fopen("main.txt", "w+");
    out = fopen("main2.c", "r+");
    
    fseek(out, 0, SEEK_END);
    int len = ftell(out);
    fseek(out, 0, SEEK_SET);
    
    
    for(int i=1; i<len; i++){
        fgets(c,sizeof(char)*2, out);
        fputs(c, in);
        fseek(out, i, SEEK_SET);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}
