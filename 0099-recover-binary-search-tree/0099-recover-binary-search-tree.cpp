class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode * first = nullptr ,*second = nullptr ,*prev = nullptr;
        TreeNode * curr = root;

        while(curr){

            if(!curr->left){

                if(prev && prev->val >= curr->val){
                    if(!first){
                        first = prev;
                        second = curr;
                    }
                    else{
                        second = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            }
            else{
                    TreeNode * pred = curr->left;

                    while(pred->right!=nullptr && pred->right!=curr){
                        pred = pred->right;
                    }

                    if(pred->right == nullptr){
                        pred->right = curr;
                        curr= curr->left;
                    }
                    else{

                        pred->right = nullptr;
                        if(prev && prev->val>=curr->val){
                            if(!first){
                                first = prev;
                                second = curr;
                            }
                            else{
                                second = curr;
                            }
                            prev = curr;
                        }
                        prev = curr;
                        curr=curr->right;
                        
                    }
            }
        }
        swap(first->val , second->val);
    }
};