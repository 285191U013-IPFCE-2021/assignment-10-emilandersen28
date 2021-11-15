#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  //allocates memory for node
  node *p = malloc (sizeof (node));
  //set p value to the input v
  p->value = v;
  
  
  if (q == NULL)
    p->next = NULL;
  else
  //if the stack inst empty sets p to point to next element
    p->next = q;
  return p;
}

/* free all nodes in the list p */
node * free_list (node * p)
{
//saves temporary
  node *q = p;
//loop runs through the list and free up the nodes.
  while (q != NULL)
    {   
      node *t = q->next;
      free (q);
      q = t;
    }
  //returns new list
  return q;
}


/* print list to console */
void print_list (node * p)
{
  //prints value to the pointer p
  printf("%d",p->value);
  //if p is not the last node in the list, takes the pointer to p->next and passes it to the function again.
  if(p->next != NULL)
    //recursive
    print_list(p->next);
}

int sum_squares (node * p)
{
  //If list is empty, the empty list is returned
  if (p == NULL)
    return 0;
  //Base case
  else if (p->next == NULL)
    return square(p->value);
  //Recursive function call
  else
    return sum_squares(p->next)+square(p->value);
}
//exercise 3
node *map (node * p, int (*f) (int))
{
  //If list is empty, the empty list is returned
  if (p == NULL)
    return p;
  //Recursive step
  else
    return make_node((*f)(p->value), map(p->next,f));
}

//computes sqare of input.
int square (int x)
{
  return x * x;
}
