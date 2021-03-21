#include "binary_trees.h"

/**
 * binary_height_recursion - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_height_recursion(const binary_tree_t *tree)
{
	size_t _left = 0, _right = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	_left = binary_height_recursion(tree->left) + 1;
	_right = binary_height_recursion(tree->right) + 1;

	if (_left > _right)
	{
		return (_left);
	}
	else
	{
		return (_right);
	}
}

/**
 * b_t_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree
 */

size_t b_t_height(const binary_tree_t *tree)
{
	return (binary_height_recursion(tree));
}

/**
 * is_avl - checks to see if a binary tree is an AVL
 * @tree: Pointer to the root node of the tree
 * @max: the max limit
 * @min: the minimum limit
 * Return: a boolean
 */

size_t is_avl(const binary_tree_t *tree, int max, int min)
{
	size_t hidari = b_t_height(tree->left), migi = b_t_height(tree->right);

	if (!tree)
		return (0);

	hidari = hidari > migi ? hidari - migi : migi - hidari;
	if (hidari > 0)
		return (0);
	hidari = 1;
	migi = 1;

	if (tree->left && ((tree->left->n >= tree->n) ||
			   (tree->left->n <= min)))
		return (0);
	if (tree->right && ((tree->right->n <= tree->n) ||
			    (tree->right->n >= max)))
		return (0);
	if (tree->left)
		hidari = is_avl(tree->left, tree->n, min);
	if (tree->right)
		migi = is_avl(tree->right, max, tree->n);
	return (hidari == 1 && migi == 1);
}

/**
 * binary_tree_is_avl - Checks if binary tree is a valid AVL
 * @tree: Pointer to the root node of the tree to rotate
 * Return: 1 if AVL, 0 if not
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (tree ? is_avl(tree, INT_MAX, INT_MIN) : 0);
}
