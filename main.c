#include <stdio.h>
#include "bst.h"

int compare(void * a, void* b) {
    Student x = *(Student*)a;
    Student y = *(Student*)b;
    return strcmp(y.name, x.name);
}

int main() {
    /*creating a binary search tree and passing a pointer to the function that will be used for priorities*/
    bst_tree_t *Students = bst_tree_create(compare);
    char command[50];
    printf("This program is used to store the results of an exam.\nTo insert details of a student press 1.\nTo get the students in alphabetical order press 2\nTo get the grade of a student press 3\nTo terminate the program press 4\n");
    
    while(1) {
        printf("Command:");
        scanf("%s", command);
        if(!strcmp(command, "1")) {
            Student intel;
            printf("Name:");
            scanf("%s", intel.name);
            printf("Class:");
            scanf("%s", intel.class);
            printf("Grade:");
            scanf("%lf", &intel.grade);
            /* Inserting the student structure into the binary seach tree*/
            bst_tree_insert(Students, &intel, sizeof(Student));

        } else if(!strcmp(command, "2")) {
            /*getting the list of students sorted by grade in descending order*/
            bst_tree_sort(Students->root);
        } else if(!strcmp(command, "3")) {
            printf("Numele:");
            char name[30];
            scanf("%s", name);
            /*make program not case sensitive*/
            for(int i = 0; i < strlen(name); i++) {
                name[i] = tolower(name[i]);
            }
            /*searching for the student with the given name*/
            Student *stud = bst_tree_search(Students->root, name);
            if(stud != NULL) {
                printf("Grade is %lf\n", stud->grade);
            } else {
                printf("No such student\n");
            }
        } else if(!strcmp(command, "4")) {

            break;
        } else {
            printf("Incorrect command!!!!!\n");
        }
    }
    bst_tree_free(Students);


}