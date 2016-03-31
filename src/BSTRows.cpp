/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};



struct node* search(struct node *head, int key)
{
	if (head != NULL)
	{
		if (key == (head->data))
			return head;
		if (key > head->data)
			return search(head->right, key);
		else
			return search(head->left, key);
	}
}


int* BSTRighttoLeftRows(struct node* root)
{
	int read_index, write_index, *arr, end_index, start_index;
	if (root == NULL)
		return NULL;
	arr = (int *)malloc(sizeof(int)* 20);
	struct node *search_key;
	arr[0] = root->data;
	for (read_index = 0, write_index = 1;; read_index = end_index)
	{
		for (start_index = read_index, end_index = write_index; start_index <end_index; start_index++)
		{
			search_key = search(root, arr[start_index]);
			if (search_key->right != NULL)
				arr[write_index++] = (search_key->right)->data;
			if (search_key->left != NULL)
				arr[write_index++] = (search_key->left)->data;
		}
		if (end_index == write_index)
			break;
	}
	return arr;
}
