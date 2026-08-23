#include <stdio.h>
#include <stdlib.h>
typedef struct employee_s employee_t;

struct employee_s {
    char *fname;
    char *lname;
    int   id;
    int   ssn;
    char *title;
};

typedef struct {
    employee_t *employee_1;
    employee_t *employee_2;
} employee_container_s;

employee_t *get_employee();
void print_employee_info(employee_t *em);

int
main()
{
    employee_container_s es;
    es.employee_1 = get_employee();
    es.employee_2 = get_employee();
    print_employee_info(es.employee_1);
    print_employee_info(es.employee_2);
    return 0;
}

employee_t *
get_employee()
{
    employee_t *em = malloc(sizeof(employee_t));
    if (em == NULL) {
        perror("malloc failed");
        exit(1);
    }
    printf("Enter the employee's first name: ");
    scanf("%ms", &em->fname);
    printf("Enter the employee's last name: ");
    scanf("%ms", &em->lname);
    printf("Enter the employee's ID number: ");
    scanf("%d", &em->id);
    printf("Enter the last four digits of the employee's SSN: ");
    scanf("%d", &em->ssn);
    printf(
    "Enter the employee's job title (do not include the word 'Engineer'): ");
    scanf("%ms", &em->title);
    printf("\n");
    return em;
}

void
print_employee_info(employee_t *em)
{
    printf("Employee information for %s %s:\n", em->fname, em->lname);
    printf("ID: %d\n", em->id);
    printf("SSN: %d\n", em->ssn);
    printf("Title: %s Engineer\n\n", em->title);
}
