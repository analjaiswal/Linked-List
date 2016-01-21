#include<stdio.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct Node *next;
};
void insertbegin(struct Node **);
void deletebegin(struct Node **);
void traverse(struct Node *);
void insertend(struct Node **);
void deleteend(struct Node **);
void insertmid(struct Node **);
void deletemid(struct Node **);
void max(struct Node *);
int main()
{
 int op;
 struct Node *head;
 head = NULL;
 printf("Enter the choice:\n 1:Insert at beginning\n 2:Delete at beginning\n 3:Exit\n 4:Traverse\n 5:Insert at end\n 6:Delete at end\n 7:Insert at mid\n 8:Delete at mid\n 9:Maximum And Minimum\n");
 scanf("%d", &op);
 while( op != 3 )
 {
  if( op == 1)
  insertbegin(&head);
  else if( op == 2 )
  deletebegin(&head);
  else if(op == 4)
  traverse(head);
  else if( op == 5)
  insertend(&head);
  else if( op == 6)
  deleteend(&head);
  else if(op == 7)
  insertmid(&head);
  else if(op == 8)
  deletemid(&head);
  else if(op == 9)
  max(head);
  else
  exit(1);
  printf("What to do next:");
  scanf("%d", &op);
 }
 return;
}

void insertbegin(struct Node **start)
{
 //If no head exists then make one.
 if (*start == NULL)
 {
  struct Node *temp;
  temp = malloc(sizeof(struct Node));
  temp->data=5;
  temp->next=NULL;
  *start = temp;
 }
 
 else
 {
  printf("Enter the value of n:\n");
  struct Node *temp1;
  temp1 = *start;
  struct Node *temp = malloc(sizeof(struct Node));
  scanf("%d", &temp->data);

  temp->next=temp1;
  *start=temp;
 }
}
void deletebegin(struct Node **start)
{
 if(*start == NULL)
 printf("List is empty\n");
 else
 {
  struct Node *temp = *start;
  *start = temp-> next;
  free(temp);
 }
}
void traverse(struct Node *head)
{
 struct Node *temp = head;
 if(temp == NULL)
 printf("List is empty\n");
 else
 {
  while(temp != NULL)
  {
   printf("|%d|-->| ", temp->data);
   temp = temp->next;
  }
 }
}
void insertend(struct Node **start)
{
 struct Node *temp = *start;
 struct Node *temp1 = malloc(sizeof(struct Node));
 printf("Enter the value:\n");
 scanf("%d", &temp1->data);
 temp1->next=NULL;
 while(temp->next != NULL)
 {
  temp = temp->next;
 }
 temp->next = temp1;
}
void deleteend(struct Node **start)
{
 struct Node *temp = *start;
 struct Node *prev = *start;
 while(temp->next != NULL)
 {
  prev = temp;
  temp = temp->next;
 }
  prev->next=NULL;
  free(temp);
}
void insertmid(struct Node **start)
{
 int value;
 struct Node *temp = *start;
 struct Node *temp1 = malloc(sizeof(struct Node));
 printf("Enter the value after which you want to insert:\n");
 scanf("%d", &value);
 while(temp->data != value)
 {
  temp = temp->next;
 }
 printf("Enter the value of new node\n");
 scanf("%d", &temp1->data);
 temp1->next = temp->next;
 temp->next=temp1;
}
void deletemid(struct Node **start)
{
 int value;
 printf("Enter the data whose node you want to delete:\n");
 scanf("%d", &value);
 struct Node *temp = *start;
 struct Node *prev = *start;
 while(temp->data != value)
 {
  prev=temp;
  temp=temp->next;
 }
 prev->next = temp->next;
 free(temp);
}
void max(struct Node *head)
{
 int max, min;
 struct Node *temp = head;
 max = temp->data;
 min = temp->data;
 while(temp->next != NULL)
 {
  temp = temp->next;
  if(max < temp->data)
  max = temp->data;
  if(min > temp->data)
  min = temp->data;
 }
 printf("The max no is %d and min no is %d\n", max, min);
}
