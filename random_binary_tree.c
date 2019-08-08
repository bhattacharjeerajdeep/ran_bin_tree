#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
  int data;
  struct Node *left,*right;
} node;

node *createtree(int x);
int tree_height(node *root);
void printonelevel(node *root, int level, int lvl);
void print_tree_levelorder(node *root);
int two_power(int x);
int bound_rand(int x1,int x2);

int main() {
  srand(time(0));
  int n_node;
  printf("Enter the total number of nodes: ");
  scanf("%d",&n_node);
  node *p=createtree(n_node);
  print_tree_levelorder(p);
  return 0;
}
/* This is a recursive funtion that creates a tree taking the value of nodes
below it (including itself) as argument */

node *createtree(int x) {
  node *start = (node*)malloc(sizeof(node));
  start->data=bound_rand(10,99);
  if(x>1) {
    int r=bound_rand(0,x-1);
    start->left=createtree(r);
    start->right=createtree(x-r-1);
    return start;
  }
  else if(x==1) {
    start->left=NULL;
    start->right=NULL;
    return start;
  }
  else if(x==0)
    free(start);
    return NULL;
}
// Gives back the height of the tree in integer value.
int tree_height(node *root) {
  if(root==NULL)
    return 0;
  else {
    int lheight = tree_height(root->left);
    int rheight = tree_height(root->right);
    if(lheight>rheight)
      return lheight+1;
    else
      return rheight+1;
  }
}
// Print a particular level of tree
void printonelevel(node *root, int level,int space) {
  if(level==1) {
    int gap=two_power(space);
    for(int i=0;i<2*gap;i++) {
      if(i==gap-1 && root==NULL)
        printf("--");
      else if(i==gap-1 && root!=NULL)
        printf("%d",root->data);
      else
        printf("  ");
    }
  }
  else if(root==NULL){
    printonelevel(NULL,level-1,space);
    printonelevel(NULL,level-1,space);
  }
  else {
    printonelevel(root->left,level-1,space);
    printonelevel(root->right,level-1,space);
  }
}
// Print a tree in level order
void print_tree_levelorder(node *root) {
  int h= tree_height(root);
  printf("The random tree created is -> \n");
  for(int i=1; i<=h; i++) {
    printonelevel(root,i,h-i);
    printf("\n");
  }
}
// Compute exponent of two
int two_power(int x) {
  int mul=1;
  for(int i=0; i<x;i++) {
    mul=mul*2;
  }
  return mul;
}
// Returns random value between the boundaries
int bound_rand(int x1,int x2) {
  if(x1<x2)
  return(x1+(rand()%(x2-x1+1)));
  else
  return(x2+(rand()%(x1-x2+1)));
}
