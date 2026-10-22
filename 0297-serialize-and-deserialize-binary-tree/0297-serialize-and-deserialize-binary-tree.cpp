class Codec {
public:
    void serialize_helper(TreeNode * root , string &data){

        if(root == NULL){
            data += "#,";
            return;
        }

        data += to_string(root->val)+",";

        serialize_helper(root->left,data);
        serialize_helper(root->right,data);

    }
    TreeNode * deserialize_helper(vector<string>&tokens ,int &idx){

        if(tokens[idx]=="#"){
            idx++;
            return nullptr;
        }

        TreeNode * curr = new TreeNode(stoi(tokens[idx++]));

        curr->left = deserialize_helper(tokens , idx);
        curr->right = deserialize_helper(tokens , idx);

        return curr;
    }
    string serialize(TreeNode* root) {
        string data;
        serialize_helper(root,data);
        return data;
    }

    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string token;
        stringstream ss(data);

        while(getline(ss,token,',')){
            tokens.push_back(token);
        }

        int idx = 0;
        return deserialize_helper(tokens , idx);

        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));