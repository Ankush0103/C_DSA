#include <stdio.h>
#include <stdlib.h> 

struct stack
{
  int data;
  struct stack *next;
};

void push(int data,struct stack**top)
{
  //Create a new stack element
  struct stack *new_node = (struct stack*)malloc(sizeof(struct stack));

  if(new_node!=NULL)
  {
    new_node->data=data;

    new_node->next=*top;

    *top=new_node;
  }
  else
  {
    printf("\nStack Overflow\n");
  }
}

int pop(struct stack **top)
{

  if(*top!=NULL)
  {
    struct stack*auxiliary=*top;

    int data = auxiliary->data;

    *top=auxiliary->next;

    //Remove node
    free(auxiliary);

    auxiliary=NULL;

    return data;

  }
  return -1;
}


struct stack* is_consecutive(struct stack*top)
{
  //This stack variables are used to store actual stack element
  struct stack*ptr=NULL;

  //This is two auxiliary variables which are used to get pair elements
  struct stack*first=NULL;
  struct stack*second=NULL;
  
  //This is a flag variable which is indicate result
  int sort = 1;

  while(top!=NULL && sort==1)
  {
    push(pop(&top),&ptr);

    //Get first pair element
    first = ptr;

    if(top != NULL)
    {
      //When in case have two pair element exists
      push(pop(&top),&ptr);
      
      //Get second pair element
      second = ptr;
      
      //Compare two stack element
      if(first->data != second->data && (second->data+1 != first->data))
      {
        //When pairwise elements are not consecutive
        sort=0; 
      }
    }
  }
  if(sort==1)
  {
    printf("Stack is Pairwise sorted");
  }
  else
  {
    printf("Stack is Not Pairwise sorted");
  }
  //Remove element of auxiliary stack and insert to actual stack
  while(ptr!=NULL)
  {
    //insert element into actual stack
    push(pop(&ptr),&top);
  }

  printf("\n");
  return top;
}
//Remove given stack elements
void remove_elements(struct stack**top)
{
  struct stack*ptr = NULL;
  while(*top != NULL)
  {
     ptr=*top;
     *top = ptr->next;
     printf("%d ",ptr->data);
     free(ptr);
     ptr=NULL;
  }
  printf("\n");

}
int main()
{
  struct stack *top1=NULL;

  //Add element into stack
  push(3, &top1);
  push(4, &top1);
  push(1, &top1);
  push(2, &top1);
 
  top1 = is_consecutive(top1);
  //Remove remaining elements into stack
  remove_elements(&top1);

  struct stack *top2 = NULL;
  //Case 2
  push(6, &top2);
  push(7, &top2);
  push(1, &top2);
  push(3, &top2);
  push(4, &top2);
  top2 = is_consecutive(top2);
  //Remove remaining elements into stack
  remove_elements(&top2);

  struct stack *top3 = NULL;
  //Case 3
  push(6, &top3);
  push(7, &top3);
  push(3, &top3);
  push(4, &top3);
  top3 = is_consecutive(top3);
  //Remove remaining elements into stack
  remove_elements(&top3);
  return 0;
}