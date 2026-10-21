class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode * build(vector<int>&preorder , int ps ,int pe ,vector<int>&inorder ,int is,int ie){
        
        if(ps>pe || is>ie) return NULL;
        
        TreeNode * root = new TreeNode(preorder[ps]);
        int idx = mp[preorder[ps]];
        int len = idx - is;

        root->left = build(preorder ,ps+1 , ps+len ,inorder , is ,idx-1);
        root->right = build(preorder ,ps+len+1 , pe , inorder , idx+1 , ie);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }

        return build(preorder , 0 , n-1 , inorder , 0 , n-1);
    }
};