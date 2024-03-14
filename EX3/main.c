#include <stdio.h>
#include <string.h>

typedef struct employee{
    int id, age;
    char name[100];
    float salary;
}employee_t;

void employee_info(employee_t emp){
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %.6f\n\n", emp.salary);
}
int employee_average_age(employee_t emp[], int n){
    
}

void employee_writefile(employee_t emp[], int n){
    FILE* file = fopen("employee.bin", "wb+");
    for(int i=0; i<n; i++){
        fwrite(&emp[i], sizeof(employee_t), 1, file);
    }
    fclose(file);
    
}

void employee_readfile(employee_t emp[]){
    FILE* file = fopen("employee.bin", "rb");
    int i =0;
    while(fread(&emp[i], sizeof(employee_t), 1, file)){
        printf("[%d] %d %s\n", i, emp[i].id, emp[i].name);
        i++;
    }
    fclose(file);
}

int main()
{
    employee_t cgu[3];
    employee_t read_cgu[3];
    
    
    cgu[0].id = 1;
    cgu[0].age = 20;
    cgu[0].salary = 30000.0;
    strcpy(cgu[0].name, "IU");
    
    cgu[1].id = 2;
    cgu[1].age = 26;
    cgu[1].salary = 36000.0;
    strcpy(cgu[1].name, "taylor");
    
    cgu[2].id = 3;
    cgu[2].age = 31;
    cgu[2].salary = 90000.0;
    strcpy(cgu[2].name, "swift");

    employee_writefile(cgu, 3);
    employee_readfile(read_cgu);
    
    printf("\n");
    
    for(int i=0; i<3; i++){
        employee_info(read_cgu[i]);
    }
    
    return 0;
}
