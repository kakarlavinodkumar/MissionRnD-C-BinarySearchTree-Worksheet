/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

 


struct node* balance_binary_search_tree(struct node *root, int *arr, int low, int high)
{
	struct node *newnode, *current;
	int mid;
	if (low <= high)
	{
		mid = (low + high) / 2;
		newnode = (struct node*)malloc(sizeof(node));
		newnode->left = newnode->right = NULL;
		newnode->data = arr[mid];
		if (root == NULL)
			root = newnode;
		else
		{
			for (current = root;;)
			{
				if (newnode->data > current->data)
				{
					if (current->right == NULL)
						break;
					current = current->right;
				}
				else
				{
					if (current->left == NULL)
						break;
					current = current->left;
				}
			}
			if (newnode->data > current->data)
				current->right = newnode;
			else
				current->left = newnode;
		}
		balance_binary_search_tree(root, arr, low, mid - 1);
		balance_binary_search_tree(root, arr, mid + 1, high);
	}
	return root;
}
struct node * convert_array_to_bst(int *arr, int len){
	struct node *root = NULL;
	if (arr == NULL || len <= 0)
		return NULL;
	return 	balance_binary_search_tree(root, arr, 0, len - 1);
}

