class Solution {
public:
    void inorder(TreeNode * root ,vector<int>&vals ,vector<TreeNode *>&nds){
        if(root == NULL) return;

        inorder(root->left,vals,nds);
        vals.push_back(root->val);
        nds.push_back(root);
        inorder(root->right,vals,nds);
    }
    void recoverTree(TreeNode* root) {
        vector<int> vals;
        vector<TreeNode *> nds;

        inorder(root , vals , nds);
        sort(vals.begin(),vals.end());

        for(int i=0;i<vals.size();i++){
            nds[i]->val =vals[i];
        }
    }
};