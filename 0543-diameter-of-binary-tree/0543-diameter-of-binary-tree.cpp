class Solution {
public:
    int maxi = 0;
    int solve(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        maxi = max(maxi , l + r);

        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        solve(root);

        return maxi;
    }
};