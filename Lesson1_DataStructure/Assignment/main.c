//--- ✄ --------- 2026.04.11 12:54 -------------------
//Created by Eng. Mahmoud Elyamani

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


/*      Effective Data      */
struct Sdata
{
    int ID;
    char name[40];
    float height;

};

/*      Linked List node        */
struct SStudent
{
    struct Sdata student;

    //Pointer of the same type that points to the next student in order  
    struct SStudent* pNextStudent;
};

//The head of our linked list:
struct SStudent *gpFirstStudent = NULL;

void AddStudent()
{
    struct SStudent *pNewStudent;
    struct SStudent *pLastStudent;
    char tempText[40];
    //Checks if the list is empty, if not it navigates to the target position
    if (gpFirstStudent == NULL)
    {
        //create a new record
        pNewStudent = (struct SStudent*)malloc (sizeof(struct SStudent));
        //assign it to gpfirst
        gpFirstStudent = pNewStudent;
    }
    else
    {
        //navigate until we reach last record
        pLastStudent = gpFirstStudent;
        while (pLastStudent->pNextStudent)
        pLastStudent = pLastStudent->pNextStudent;

        //create a new record
        pNewStudent = (struct SStudent*)malloc (sizeof(struct SStudent));
        pLastStudent->pNextStudent = pNewStudent;
    }
    //fill new record
    printf("\n Enter the ID: ");
    gets(tempText);
    pNewStudent->student.ID = atoi(tempText);

    printf("Enter student full name: ");
    gets(pNewStudent->student.name);

    printf("Enter student height: ");
    gets(tempText);
    pNewStudent->student.height = (float)atof(tempText);

    //set the next poiter (new_student) null
    pNewStudent->pNextStudent = NULL;
}

int DeleteStudent()
{
    char tempText[40];
    int selectedID;

    //Gets the selected ID
    printf("\n Ener the student id to be deleted: ");
    gets(tempText);
    selectedID = atoi(tempText);

    //checks to see if the list is empty
    if (gpFirstStudent)
    {
        struct SStudent *pSelectedStudent = gpFirstStudent;
        struct SStudent *pPreviousStudent = NULL;

        //compare each node with the selected ID
        while(pSelectedStudent)
        {
            if (pSelectedStudent->student.ID == selectedID)
            {
                if (pPreviousStudent)
                {
                    pPreviousStudent->pNextStudent = pSelectedStudent->pNextStudent;
                }
                else
                {
                    gpFirstStudent = pSelectedStudent->pNextStudent;
                }
                free (pSelectedStudent);
                return 1;
            }
            pPreviousStudent = pSelectedStudent;
            pSelectedStudent = pSelectedStudent->pNextStudent;
        }
    }
    //if the input value exceeds the number of nodes in the list, prints out an error message:
    printf("\n Cannot find student ID");
    return 0;
}


void ViewStudents()
{
    struct SStudent *pCurrentStudent = gpFirstStudent;
    unsigned int count = 0;

    //checks if the list is empty
    if (gpFirstStudent == NULL)
    printf("\n This list is empty");
    else
    {
        while (pCurrentStudent)
        {
            printf("\n record number %d ",count+1);
            printf("\n ID: %d",pCurrentStudent->student.ID);
            printf("\n Name: %s",pCurrentStudent->student.name);
            printf("\n Height: %.2f\n",pCurrentStudent->student.height);
            pCurrentStudent = pCurrentStudent->pNextStudent;
            count++;
        }
    }
}


void DeleteAll()
{
    struct SStudent *pCurrentStudent = gpFirstStudent;

    //checks if the list is empty
    if (gpFirstStudent == NULL)
    printf("\n This list is empty");
    else
    {
        while (pCurrentStudent)
        {
            struct SStudent *pTempStudent = pCurrentStudent;
            pCurrentStudent = pCurrentStudent->pNextStudent;
            free(pTempStudent);
        }
        gpFirstStudent = NULL;
    }  
}

void getNth()
{
    char tempText[10];
    int indexNumber, count = 1;
    struct SStudent *pTempStudent = gpFirstStudent;
    if(!pTempStudent)
    printf("\nThere's no students on this list.\n");
    else
    {
        printf("\nEnter an index number: ");
        gets(tempText);
        indexNumber = atoi(tempText);
        while(count != indexNumber)
        {
            if (pTempStudent->pNextStudent)
            {
                pTempStudent = pTempStudent->pNextStudent;
                count++;
            }
            else
            {
                printf("The index number(%d) exceeds the number of nodes(%d)!\n",indexNumber,count);
                break;
            }
        }
        printf("The index number %x has node ID of: %d",indexNumber,pTempStudent->student.ID);
    }
}

int main()
{
    char tempText[40];
    while(1)
    {
        printf("\n =====================================");
        printf("\n   Choose one of the following options: ");
        printf("\n   1: Add a Student ");
        printf("\n   2: Delete a Student ");
        printf("\n   3: View Students ");
        printf("\n   4: Delete All Students ");
        printf("\n   5: get node ID through index number ");
        printf("\n -Enter option number: ");

        gets(tempText);
        printf("\n =====================================");
        switch(atoi (tempText))
        {
            case 1:
            AddStudent();
            break;
            case 2:
            DeleteStudent();
            break;
            case 3:
            ViewStudents();
            break;
            case 4:
            DeleteAll();
            break;
            case 5:
            getNth();
            break;
            default:
            printf("\n Please input a valid number!");
            break;
        }
    }

    return 0;
}