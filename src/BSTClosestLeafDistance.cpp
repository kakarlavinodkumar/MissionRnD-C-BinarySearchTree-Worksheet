/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

struct node *search(struct node *root, int key, int *distance)
{
	struct node *temp;
	for (temp = root; temp != NULL;)
	{
		if (temp->data == key)
			return temp;
		else
		{
			(*distance)++;
			if (key > temp->data)
				temp = temp->right;
			else
				temp = temp->left;
		}
	}
	return NULL;
}
int minimum_height_of_subtree(struct node *temp1)
{
	if (temp1->left == NULL&&temp1->right == NULL)
		return 0;
	else if (temp1->left == NULL)
		return 1 + minimum_height_of_subtree(temp1->right);
	else if (temp1->right == NULL)
		return 1 + minimum_height_of_subtree(temp1->left);
	else
	{
		if (1 + minimum_height_of_subtree(temp1->left) > 1 + minimum_height_of_subtree(temp1->right))
			return 1 + minimum_height_of_subtree(temp1->right);
		else
			return 1 + minimum_height_of_subtree(temp1->left);
	}
}
int closest_leaf_node(struct node *root, int key, int search_distance, int min)
{
	int  cur_distance;
	struct node *temp;
	for (temp = root; temp->data != key; search_distance--)
	{
		if (temp->data < key)
		{
			if (temp->left != NULL)
			{
				cur_distance = 1 + minimum_height_of_subtree(temp->left) + search_distance;
				if (cur_distance < min)
					min = cur_distance;
			}
			temp = temp->right;
		}
		else
		{
			if (temp->right != NULL)
			{
				cur_distance = 1 + minimum_height_of_subtree(temp->right) + search_distance;
				if (cur_distance < min)
					min = cur_distance;
			}
			temp = temp->left;
		}
		//	printf("\nmin\t%d\tcur_distance\t%d", min, cur_distance);
	}
	return min;
}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	int  search_distane = 0, min_height;
	if (root == NULL || temp == NULL)
		return -1;
	struct node *key_node;
	key_node = search(root, temp->data, &search_distane);
	if (search_distane == -1)
		return -1;
	else
	{
		min_height = minimum_height_of_subtree(key_node);
		return  closest_leaf_node(root, temp->data, search_distane, min_height);
	}
}