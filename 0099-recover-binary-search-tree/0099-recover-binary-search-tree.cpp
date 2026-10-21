class Solution {
public:
    TreeNode * first = nullptr , *second = nullptr , *prev = nullptr;

    void recoverTree(TreeNode* root) {
        
        inorder(root);

        swap(first->val , second->val);
    }
    void inorder(TreeNode * node){
        if(node == nullptr) return;

        inorder(node->left);

        if(prev!=nullptr && prev->val >= node->val){
            if(first==nullptr){
                first = prev;
                second = node;
            }
            else{
                second = node;
            }
        }
        prev = node;

        inorder(node->right);
    }
};