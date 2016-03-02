#include <iostream>
#include <climits>
#include <stdlib.h>

using namespace std;

struct _node
{
	int value;
	struct _node *left;
	struct _node *right;
};

typedef struct _node node;

int is_bst(node *root, int min, int max)
{
	if (root == NULL)
		return 1;
	if (root->value < min || root->value > max)
		return 0;
	else
		return (is_bst(root->left, min, root->value) && (is_bst(root->right, root->value, max)));
}


void insert(node ** tree, node * item) 
{
	if(!(*tree)) 
	{
		*tree = item;
		return;
	}
	if(item->value<(*tree)->value)
		insert(&(*tree)->left, item);
	else if(item->value>(*tree)->value)
		insert(&(*tree)->right, item);
}

void printout(node * tree) {
	if(tree->left) 
		printout(tree->left);
	cout << tree->value << endl;
	//printf("%d\n",tree->value);
	if(tree->right) 
		printout(tree->right);
}

int main()
{
	node * curr, * root;
	int i;

	root = NULL;

	for(i=1;i<=10;i++) {
		curr = (node *)malloc(sizeof(node));
		curr->left = curr->right = NULL;
		curr->value = rand()%1000;
		cout << "inserting " << curr->value << endl;
		insert(&root, curr);
	}
	cout << endl << "Printing Tree" << endl;
	printout(root);

	cout << "Is BST - " << is_bst(root, INT_MIN, INT_MAX) << endl;
	return 0;
}
	
