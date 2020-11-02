#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 *
 * @parent: Parent node
 *
 * @value: Value of node
 *
 * Return: Create new Binary tree
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	/*Assign data to this node*/
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

/**
 * sorted_array - Sorted array to binary tree converter
 * @arr: points to the first element in the sorted array
 * @start: starting value
 * @end: ending value
 * Return: pointer to the root node of the AVL Tree
 */

avl_t *sorted_array(int *arr, int start, int end)
{
	avl_t *tree;
	binary_tree_t *parent = NULL;

	if (start > end)
	{
		return (NULL);
	}


	int mid_value = (start + end) / 2;

	tree = binary_tree_node(parent, arr[mid_value]);

	if (!tree)
		return (NULL);

	tree->left = sorted_array(arr, start, mid_value - 1);
	tree->right = sorted_array(arr, mid_value + 1, end);

	if (tree->left)
	{
		tree->left->parent = tree;
	}

	else if (tree->right)
	{
		tree->right->parent = tree;
	}

	return (tree);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: points to the first element in the sorted array
 * @size: the numbers of in the array
 * Return: pointer to the root node of the AVL Tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = sorted_array(array, 0, size - 1);

	if (!array || size < 1)
	{
		return (NULL);
	}

	return (root);
}
