struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode* tmp;
	if (!root)
		return (struct TreeNode* )0;    
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}
