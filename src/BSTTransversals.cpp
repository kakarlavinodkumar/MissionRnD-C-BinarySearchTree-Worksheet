/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
}; 

void inorder_to_array_copy(struct node *root, int *arr, int *index)
{
	if (root != NULL)
	{
		inorder_to_array_copy(root->left, arr, index);
		arr[*index] = root->data;
		*index = *index + 1;
		inorder_to_array_copy(root->right, arr, index);
	}
}
void inorder(struct node *root, int *arr){
	int index = 0;
	if (arr == NULL)
		return;
	inorder_to_array_copy(root, arr, &index);
}
void preorder_to_array_copy(struct node *root, int *arr, int *index)
{
	if (root != NULL)
	{
		arr[*index] = root->data;
		*index = *index + 1;
		preorder_to_array_copy(root->left, arr, index);
		preorder_to_array_copy(root->right, arr, index);
	}
}
void preorder(struct node *root, int *arr)
{
	int index = 0;
	if (arr == NULL)
		return;
	preorder_to_array_copy(root, arr, &index);
}
void post_order_to_array(struct node *root, int *arr, int *index)
{
	if (root != NULL)
	{
		post_order_to_array(root->left, arr, index);
		post_order_to_array(root->right, arr, index);
		arr[*index] = root->data;
		*index = (*index) + 1;
	}
}
void postorder(struct node *root, int *arr){
	int index = 0;
	if (arr == NULL)
		return;
	post_order_to_array(root, arr, &index);
}

