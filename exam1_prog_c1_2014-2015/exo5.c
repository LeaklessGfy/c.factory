#include <stdio.h>
#include <string.h>

typedef struct student{
    char first_name[64];
    char last_name[64];
    int age;
}Student;

void initialize_student(Student *st, char *first_name, char *last_name, int age)
{
    strcpy(st->first_name, first_name);
    strcpy(st->last_name, last_name);
    st->age = age;
}

int main(void)
{
    Student st;
    
    initialize_student(&st, "TOTO", "Martin", 11);
    printf("%s - %s (%d)\n", st.first_name, st.last_name, st.age);

    return 0;
}

