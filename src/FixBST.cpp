/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};


void inorder_traversal(struct node *head, int **arr, int *index)
{
	if (head != NULL)
	{
		inorder_traversal(head->left, arr, index);
		arr[*index] = &head->data;
		(*index) = *index + 1;
		inorder_traversal(head->right, arr, index);
	}
}
void swap(int **arr, int index1, int index2)
{
	int temp;
	temp = *(arr[index1]);
	*(arr[index1]) = *(arr[index2]);
	*(arr[index2]) = temp;
}
void fix_bst(struct node *root){
	int **arr, index = 0, index1, rev_index1 = -1, rev_index2 = -1;
	if (root == NULL)
		return;
	arr = (int **)malloc(sizeof(int*)* 20);
	inorder_traversal(root, arr, &index);
	for (index1 = 0; index1 < index - 1; index1++)
	{
		if (*(arr[index1])>*(arr[index1 + 1]))
		{
			if (rev_index1 == -1)
			{
				rev_index1 = index1;
				rev_index2 = rev_index1 + 1;
			}
			else
				rev_index2 = index1 + 1;
		}
	}
	if (rev_index1 != -1 && rev_index2 != -1)
		swap(arr, rev_index1, rev_index2);
}
