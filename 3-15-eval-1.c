#include<stdio.h>
#include<stdlib.h>

typedef struct student {
    char *name, *grade;
    int id;
} student;

// Q1. Search a particular student given id in the most efficient way
//  Id will be of type 1..n will be sorted (ascendingly)

student* Initialize(const int number)
{
    student *s = (student*)calloc(number, sizeof(student));
    for(int i = 0; i < number; i++ ) {
        s[i].id = i;
        if (i % 3 == 0) {
            s[i].name = "Naresh";
            s[i].grade = "AA";
        } else if (i % 3 == 1) {
            s[i].name = "Suresh";
            s[i].grade = "AB";
        } else if (i % 3 == 2) {
            s[i].name = "Ramesh";
            s[i].grade = "FP";
        }
    }
    return s;
}

student search(int id, student *s, int size)
{
    int  start = 0, mid, end = size - 1;

    if (id > end) {
        printf("\nID does not exist, exiting.\n");
        exit(1);
    }

    mid = (start + end) / 2;
    while (start != end) {
        if (s[mid].id == id) {
            return s[mid];
        } else if (id > s[mid].id) {
            start = mid;
        } else if (id < s[mid].id) {
            end = mid;
        }
        mid = (start + end) / 2;
    }
}

int main (void)
{
    int number, id;
    printf("Enter the number of students to Initialize the database\n");
    scanf("%d", &number);
    student *students = Initialize(number);
    printf("\nEnter id you want to search for\n");
    scanf("%d", &id);
    student s = search(id, students, number);
    printf("Student found, id is %d, name is \"%s\", and grade is %s.\n", s.id, s.name, s.grade);
    return 0;
}