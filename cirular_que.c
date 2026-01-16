#include <stdio.h>
#define MAX 5
int q[MAX];
int r=0, f=0, cnt=0;
void enqeue();
void deqeue();
void display();

void main()
{
    int ch;
    do
    {
        printf("\n-------BUS PASS DISTRIBUION SYSTEM-------");
        printf("\n1.Add student(Enqeue)");
        printf("\n2.Distribute Bus Pass (Deqeue)");
        printf("\n3.Show waiting students");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:enqeue();break;
            case 2:deqeue();break;
            case 3:display();break;
            case 4:printf("\n Exiting program.......");break;
            default:printf("\n Invalid choice");
        }

    }while(ch!=4);
}
void enqeue()
{
    int roll;
    if(cnt==MAX)
    {
        printf("\n Queue is full(overflow)");
    }
    else
    {
        printf("\n Enter stdent roll number:");
        scanf("%d",&roll);
        q[r]=roll;
        r=(r+1)%MAX;
        cnt++;
        printf("\n students added to waiting list");
    }
}

void deqeue()
{
    if(cnt==0)
    {
        printf("\nQueue id Empty(underflow)");
    }
    else
    {
        printf("\n Bus pass distributed to Roll No:%d",q[f]);
        f=(f+1)%MAX;
        cnt--;
    }
}

void display()
{
    int i, c=cnt;
    i-f;
    if(cnt==0)
        printf("\n No students waiting");
    else
    {
        printf("\n waiting students (Roll Numbers):\n");
        for(i = f; i != r; i = (i + 1) % MAX)
        {
            printf("%d\t",q[i]);
        }
    }
}