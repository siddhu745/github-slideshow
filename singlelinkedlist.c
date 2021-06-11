#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *link;   
};  
struct node *head;  
void createlist();
void front_insert ();   
void lastinsert ();  
void randominsert();  
void frontdelete();  
void last_delete();  
void random_delete();  
void display();  
void search(); 
void countnodes();

void main ()  
{  
    int choice =0;  
    while(choice != 11)   
    {  
        printf("\n\n\t*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");
        printf("*sugession:\n to perform other operations,you must create a list...."); 
        printf("\n===============================================\n");  
        printf("\n1.create single linked list\n2.Insert in begining\n3.Insert at last\n4.Insert at any random location\n5.Delete from Beginning\n6.Delete from last\n7.Delete node at specified location\n8.Search for an element\n9.Show\n10.count no of nodes\n11.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        { 
            case 1:
            createlist();
            break; 
            case 2:  
            front_insert();      
            break;  
            case 3:  
            lastinsert();         
            break;  
            case 4:  
            randominsert();       
            break;  
            case 5:  
            frontdelete();       
            break;  
            case 6:  
            last_delete();        
            break;  
            case 7:  
            random_delete();          
            break;  
            case 8:  
            search();         
            break;  
            case 9:  
            display();        
            break;
            case 10:
            countnodes();
            break;  
            case 11:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
void createlist()
{
    int n;
    struct node *temp;
    head = malloc(sizeof(struct node));
    printf("enter no of nodes:");
    scanf("%d",&n);
    printf("enter data to node 1:");
    scanf("%d",&head->data);
    head->link=NULL;
    temp=head;
    for(int i=1;i<n;i++)
    {
        struct node *new=malloc(sizeof(struct node));
        printf("enter data to node %d:",i+1);
        scanf("%d",&new->data);
        temp->link=new;
        new->link=NULL;
        temp=temp->link;
    }
    printf("single linked list is created.....");

}
void front_insert()  
{  
    struct node *ptr;  
    int item;  
    ptr = (struct node *) malloc(sizeof(struct node *));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&item);    
        ptr->data = item;  
        ptr->link = head;  
        head = ptr;  
        printf("\nNode inserted");  
    }  
      
}  
void lastinsert()  
{  
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)  
        {  
            ptr -> link = NULL;  
            head = ptr;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> link != NULL)  
            {  
                temp = temp -> link;  
            }  
            temp->link = ptr;  
            ptr->link = NULL;  
            printf("\nNode inserted");  
          
        }  
    }  
}  
void randominsert()  
{  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
          
        printf("\nEnter the location which you want to insert ");  
        scanf("\n%d",&loc);
        if(loc==1) front_insert();
        else 
        {
            printf("\nEnter element value");  
            scanf("%d",&item);  
            ptr->data = item;
            temp=head;  
            for(i=2;i<loc;i++)  
            {  
                temp = temp->link;  
                if(temp == NULL)  
                {  
                    printf("\ncan't insert\n");  
                    return;  
                }  
          
            }  
            ptr ->link = temp ->link;   
            temp ->link = ptr;   
            printf("\nNode inserted"); 
        } 
    }  
}  
void frontdelete()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->link;  
        free(ptr);  
        printf("\nNode deleted from the begining ...\n");  
    }  
}  
void last_delete()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> link == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted ...\n");  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->link != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->link;  
        }  
        ptr1->link = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last ...\n");  
    }     
}  
void random_delete()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node\n");  
    scanf("%d",&loc);
    if(loc==1) frontdelete();
    else
    { 
        ptr=head;  
        for(i=1;i<loc;i++)  
        {  
            ptr1 = ptr;       
            ptr = ptr->link;  
              
            if(ptr == NULL)  
            {  
                printf("\nCan't delete");  
            }  
        }  
        ptr1 ->link = ptr ->link;  
        free(ptr);  
        printf("\nDeleted node %d ",loc);
    }  
}  
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> link;  
        }  
        if(flag==1)  
        {  
            printf("Item not found\n");  
        }  
    }     
          
}  
  
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> link;  
        }  
    }  
} 
void countnodes()
{ 
    int i=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("%d nodes present",i);
    }
    else
    {
        while(temp!=NULL)
        {
            i++;
            temp=temp->link;
        }
        printf("%d nodes present",i);
    }
}    