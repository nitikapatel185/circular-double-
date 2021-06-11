#include<stdio.h>
#include<stdlib.h>
//node creation
struct  node{
    int data;
    struct Node *next,*prev;
};
struct Node *head,*ptr;
//function creation
void insert_begin(int value)
{
    //allocate node
    struct Node *temp;
    temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    if(head==NULL)
    {
        head=temp;
        temp->next=head;
        temp->prev=head;
    }
    else
    {
        ptr=head;
        ptr=head->prev;
        head->prev=temp;
        temp->next=head;
        ptr->next=temp;
        temp->prev=ptr;
        head=temp;
    }    
}

void insert_nposition(int ele,int value)
{
    //allocate node
    struct Node *temp;
    temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    if(head==NULL)
    {
        head=temp;
        temp->next=head;
        temp->prev=head;
    }
    else
    {
        ptr=head;
        while(ptr->data!=ele)
        {
            ptr=ptr->next;
        }
            temp->next=ptr->next;
            temp->prev=ptr;
            ptr->next=temp;
            ptr->next->prev=temp;
    }
}
void insert_end(int value)
{
    //allocate node
    struct Node *temp;
    temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    if(head==NULL)
    {
        head=temp;
        temp->next=head;
        temp->prev=head;
    }
    else
    {
        ptr=head;
        ptr=head->prev;
        ptr->next=temp;
        temp->prev=ptr;
        temp->next=head;
        head->prev=temp;
    }
}
void delete_begin()
{
    struct Node *ptr,*p;
    if(head==NULL)
        printf("List is empty");
    if(head->next==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        ptr=head;
        ptr=ptr->prev;
        p=head;
        head=head->next;
        head->prev=ptr;
        ptr->next=head;
        free(p);
    }
}

void delete_nposition()
{
    struct Node *ptr;
    if(head==NULL)
        printf("List is empty");
    if(head->next==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        ptr=head;
        ptr->prev->next=ptr->next;
        ptr->next->prev-ptr->prev;
        free(ptr);
    }
    
}
void delete_end()
{
    struct Node *ptr;
    if(head==NULL)
        printf("List is empty");
    if(head->next==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        ptr=head;
        ptr=head->prev;
        ptr->prev->next=head;
        head->prev=ptr->prev;
        free(ptr);
    }  
}
void display()
{
    if(head== NULL)
    {
        printf("list is empty");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("<->%d",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
    
}
void main()
{
    int value,ele,ch;
    printf("1.Insert at begining\n");
    printf("2.Insert at nposition\n");
    printf("3.Insert at end\n");
    printf("4.Delete at begining\n");
    printf("5. Delete at nposition\n");
    printf("6.Delelte at end\n");
    printf("7.display\n");
    printf("8.exit\n");
    while(1)
    {
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter the value to insert at beginning:");
                scanf("%d",&value);
                insert_begin(value);
                display();
                break;
            }
            case 2:
            {
                printf("Enter the value to insert nposition:");
                scanf("%d",&value);
                printf("Enter the elements:");
                scanf("%d",&ele);
                insert_nposition(value,ele);
                display();
                break;
            }
            case 3:
            {
                printf("Enter the value to insert at end:");
                scanf("%d",&value);
                insert_end(value);
                display();
                break;
            }
             case 4:
            {
                delete_begin();
                display();
                break;
            }
            case 5:
            {
                printf("Entere element you want to delete:\n");
                scanf("%d",&ele);
                delete_nposition(ele);
                display();
                break;
            }
            case 6:
            {
                delete_end();
                display();
                break;
            }
            case 7:
            {
                display();
            }
            case 8:
            {
                exit(0);
            }
        }
    }
}