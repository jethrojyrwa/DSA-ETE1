//ete1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct empl{
    char name[50];
    int performance_score;
    int employeeID; 
    struct empl *next;
}Employee;

Employee *head = NULL;

Employee *addEmployee();
void displayEmployees(Employee *ptr);
void highestPerformanceEmployee();
void splitLowHigh();

void main(){
    int ch, ei,ps;
    char name[50];
    do{
        printf("\nMenu");
        printf("\n1. Add an Employee");
        printf("\n2. Display All Employee Details");
        printf("\n3. Find Employee with Highest Performance Score");
        printf("\n4. Split Employees Based on Peformance");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            head = addEmployee();
            break;

            case 2:
            displayEmployees(head);
            break;

            case 3:
            highestPerformanceEmployee();
            break;

            case 4:
            splitLowHigh();
            break;

            case 5:
            break;

            default:
            printf("\nInvalid Choice entered");
        }
    }while(ch!=5);
}

Employee *addEmployee(){
    Employee *newNode;
    int ei,ps;
    newNode = (Employee *)malloc(sizeof(Employee));
    printf("\nEnter the Employee Details:\n");
            printf("\nEmployee Name: ");
            getchar();
            fgets(newNode->name, sizeof(newNode->name),stdin);
            while(1){
    
                printf("\nPerformance Score: ");
                scanf("%d",&ps);
                if((ps < 0) || (ps > 100)){
                    printf("\nInvalid Performance Score. \nEnter a performance score between 0 and 100");
                }
                else{
                    break;
                }
            }
            
            while(1){
                printf("\nEnter Employee ID: ");
                scanf("%d",&ei);

                if(ei<0){
                    printf("\nInvalid Employee ID.\nEmployee ID should be a positive integer");
                }
                else{
                    break;
                }
            }
    if(newNode==NULL){
        printf("\nCould not allocate space");
        return NULL;
    }

    newNode->performance_score = ps;
    newNode->employeeID = ei;
    newNode->next = NULL;

    if(head==NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        Employee *ptr = head;
        while(ptr->next!=head){
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    return head;
}

void displayEmployees(Employee *ptr){

    if(ptr==NULL){
        printf("\nThere are currently no Employees added to the list");
        return;
    }

    Employee *current = ptr;
    while(current->next!=ptr){
        printf("\nEmployee Name: %s",current->name);
        printf("Peformance Score: %d",current->performance_score);
        printf("\nEmployee ID: %d",current->employeeID);
        printf("\n-----------------------");
        current = current->next;
    }
    printf("\nEmployee Name: %s",current->name);
    printf("Peformance Score: %d",current->performance_score);
    printf("\nEmployee ID: %d",current->employeeID);
    printf("\n-----------------------");
}

void highestPerformanceEmployee(){
    if(head==NULL){
        printf("\nNo employees to split");
        return;
    }
    Employee *ptr = head;
    Employee *max = head;

    do {
        if (ptr->performance_score > max->performance_score) {
            max = ptr;
        }
        ptr = ptr->next;
    } while (ptr != head);

    printf("\nEmployee Details with Highest Performance Score");
    printf("\nEmployee Name: %s",max->name);
    printf("Peformance Score: %d",max->performance_score);
    printf("\nEmployee ID: %d",max->employeeID);

}

void splitLowHigh(){
    Employee *low=NULL, *high=NULL;
    Employee *ptr = head;
    
    if(head==NULL){
        printf("\nNo employees to split");
        return;
    }


    do{
        if(ptr->performance_score < 40){
            Employee *newNode=NULL;
            newNode = (Employee *)malloc(sizeof(Employee));
            strcpy(newNode->name,ptr->name);
            newNode->performance_score = ptr->performance_score;
            newNode->employeeID = ptr->employeeID;
            newNode->next = NULL;
            if(low==NULL){
                low = newNode;
                newNode->next = low;
            }
            else{
                Employee *ptr = low;
                while(ptr->next!=low){
                    ptr = ptr->next;
                }
                newNode->next = ptr->next;
                ptr->next = newNode;
            }
        }
        else{
            Employee *newNode=NULL;
            newNode = (Employee *)malloc(sizeof(Employee));
            strcpy(newNode->name,ptr->name);
            newNode->performance_score = ptr->performance_score;
            newNode->employeeID = ptr->employeeID;
            newNode->next = NULL;
            if(high==NULL){
                high = newNode;
                newNode->next = high;
            }
            else{
                Employee *ptr = high;
                while(ptr->next!=high){
                    ptr = ptr->next;
                }
                newNode->next = ptr->next;
                ptr->next = newNode;
            }
        }
        ptr = ptr->next;
    }while(ptr!=head);
    
    printf("\n\n\nEmployees with Performance Score lesser than 40");
    displayEmployees(low);

    printf("\n\n\nEmployees with Performance Score greater than 40");
    displayEmployees(high);

}

