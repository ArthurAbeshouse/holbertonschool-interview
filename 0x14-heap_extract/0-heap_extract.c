#include "binary_trees.h"

/**
 * heap_extract -  extracts the root node of a Max Binary Heap
 * @root: double pointer to thr root of the binary heap
 * Return: value in the root node
 */
int heap_extract(heap_t **root)
{
	heap_t *last_inserted_node = NULL;
	int swap;

	if (!*root)
		return (0);

	swap = (*root)->n;
	last_inserted_node = push_to_top(*root);

	if (last_inserted_node->parent->right)
		last_inserted_node->parent->right = NULL;
	else
		last_inserted_node->parent->left = NULL;

	(*root)->n = last_inserted_node->n;

	heapify_down(*root);

	free(last_inserted_node);

	return (swap);
}


/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_tree_height(heap_t *tree)
{
	size_t _left = 0, _right = 0;

	if (tree == NULL)
		return (0);

	else
	{
		_left = binary_tree_height(tree->left) + 1;
		_right = binary_tree_height(tree->right) + 1;
	}

	if (_left >= _right)
		return (_left);
	else
		return (_right);

}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: If tree is NULL, the function will return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * push_to_top - finds the node that goes to the top
 * @node: The root node
 * Return: The newly inserted node
 */
heap_t *push_to_top(heap_t *node)
{
	if (!node)
		return (NULL);

	if (!node->left && !node->right)
		return (node);

	if (binary_tree_height(node->left) > binary_tree_height(node->right))
		return (push_to_top(node->left));

	if (binary_tree_size(node->left) > binary_tree_size(node->right))
		return (push_to_top(node->right));

	return (push_to_top(node->right));
}

/**
 * heapify_down - moves a node down the tree
 * @root: pointer to binary heap
 */
void heapify_down(heap_t *root)
{
	heap_t *Lrgst_node = NULL;
	int tmp;

	if (!root)
		return;

	if (root->right)
	{
		if (root->right->n > root->left->n)
			Lrgst_node = root->right;
		else
			Lrgst_node = root->left;
	}
	else if (root->left)
		Lrgst_node = root->left;

	if (Lrgst_node && Lrgst_node->n > root->n)
	{
		tmp = Lrgst_node->n;
		Lrgst_node->n = root->n;
		root->n = tmp;
		heapify_down(Lrgst_node);
	}
}
