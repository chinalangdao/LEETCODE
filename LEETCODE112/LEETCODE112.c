bool helper(struct TreeNode * root, int sum){
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL)
        return sum == root->val;
    return helper(root->left, sum - root->val) || helper(root->right, sum - root->val);
}

bool hasPathSum(struct TreeNode* root, int sum){
    return helper(root, sum);
}
