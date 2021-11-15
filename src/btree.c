#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//function that creates a new node in the tree
struct tree_node * createNode(int value)
{
  //alocates size of the structs.
    struct tree_node *new = malloc(sizeof(struct tree_node));

      //sets item to value and the l and r pointers to NULL.
      new->item = value;
      new->left = NULL;
      new->right= NULL;

    return new;
};
//Function tha finds smallest node
int smallestNode(struct tree_node *t)
{
  struct tree_node* temp = t;
//runs through left side of binary until incounters null, bc the most left item will always be the smallest
  while(t->left != NULL)
  {
    temp = t->left;
  }
    return temp->item;
}

// Insert item x into the tree t
struct tree_node * Insert (int x, struct tree_node *t)
{  
  //If the pointer passed is NULL it will create a node and insert x 
  if(t == NULL)
  {
    return createNode(x);
  }
//if x is bigger than item, then  the right child pointer is passed to insert as a recusive function
  if(x > t->item)
  {
    t->right = Insert(x,t->right);
  }
  else
  //if x is smaller than item, then the left child pointer is passed to insert as a recusive function
  {
    t->left = Insert(x,t->left);
  }
  return t;
}

// Removes one item from the tree t
struct tree_node * Remove (int x, struct tree_node *t)
{
  //Incase tree is empty, the empty tree is returned
  if (t == NULL)
  {
    return t;
  }
  //Recursive call to go through the tree until x is found
  if(x > t->item)
  {
    t->right = Remove(x, t->right);
  }
  else if(x < t->item)
  {
    t->left = Remove(x, t->left);
  }
  // If the node we are looking for has no children, the node is freed
  // and the new tree is returned
  else if (t->left == NULL && t->right == NULL)
  {
    free(t);
    return NULL;
  }
  else if(t->right == NULL || t->left == NULL)
  {
    struct tree_node * temp_t = NULL;
    //If only one child is present, it is saved in a temporary value and transfered, and the node is deleted
    if (t->right == NULL)
    {
      temp_t = t->left;
    }
    else if(t->left == NULL)
    {
      temp_t = t->right;
    }
      free(t);
      return temp_t;
  }
  else
  {
    // Smallest node on right side is found, and the value of t->item
    // is changed to the replacement value, and the original node is removed
    int smallest = smallestNode(t->right);

    t->item = smallest;

    t->right = Remove(t->item,t->right);  
  }
  return t;
}

// Check if a certain number is contained in the tree
int Contains (int x, struct tree_node *t)
{
  //If the tree is empty, the empty tree is returned
  if(t == NULL)
    {
      return 0;
    } 
  //Base case
  if(t->item == x)
    {
      return 1;
    }
  //Function is recursively called on the left side if x is smaller, and on the right otherwise
  else if(x < t->item)
    {
      return Contains(x,t->left);
    }
  else
    {
      return Contains(x,t->right);
    }
  //Function returns true if the tree contains x, otherwise returns false
}

// Create an empty tree
struct tree_node * Initialize (struct tree_node *t)

{
  t = NULL;
  return t;
}

// Test if empty
int Empty (struct tree_node *t)
{
  //if t == NULL the tree must be empty, and true is returned
  if (t == NULL)
    return 1;
  else
  //Otherwise false is returned
    return 0;
}

/*it will always be able to accept more inputs until the pc runs out of memory 
bc it is dynamically allocated memory.
*/
int Full (struct tree_node *t)
{
  return 0;
}
