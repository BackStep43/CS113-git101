#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct node { 
   int data;
   struct node *prev; 
   struct node *next; 
} Node; 
  
Node *create_list(int data)
{  
 Node *new_node = malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    
    return new_node;
}

void insert(Node *new_node , Node **head)
{
  Node *tmp = *head;
    while(1)
    {
        if(new_node->data < tmp->data)
        {
            if(*head == tmp)
            {
                *head = new_node;
                new_node->next = tmp;
                tmp->prev = new_node ;

            }
            else 
            {
                tmp->prev->next = new_node;
                new_node->next = tmp;
                new_node->prev = tmp->prev;
                tmp->prev = new_node; 

            }
            break;
        }
        else if(tmp->next == NULL && tmp->data <= new_node->data ) 
        {
            new_node->next = tmp->next;
            new_node->prev = tmp;
            tmp->next = new_node;
            break;
        }
        tmp = tmp->next;
    }
}

int main() 
{  
   Node *head, *tmp;
   int input ;
   scanf("%d",&input);
   if (input != -1)
   {
    tmp = create_list(input);
    head = tmp;
   }
  while (scanf("%d", &input) == 1) 
  {
          if (input == -1)
          break;
          tmp = create_list(input);
          insert(tmp, &head); 
  }
  
  for (tmp=head; tmp; tmp = tmp->next)
  {
    printf("%d\n", tmp->data);
  }

}