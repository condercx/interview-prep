/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int calculateDepth(struct TreeNode* root) {
	if (root == NULL) return 0;

	int leftDepth = calculateDepth(root->left);

	int rightDepth = calculateDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}