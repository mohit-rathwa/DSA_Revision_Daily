#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;

    void findParents(TreeNode* node, TreeNode* p) {
        if (!node) return;
        parent[node] = p;
        findParents(node->left, node);
        findParents(node->right, node);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParents(root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);

        int dist = 0;
        while (!q.empty()) {
            if (dist == k) {
                vector<int> ans;
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !vis.count(curr->left)) {
                    vis.insert(curr->left);
                    q.push(curr->left);
                }
                if (curr->right && !vis.count(curr->right)) {
                    vis.insert(curr->right);
                    q.push(curr->right);
                }
                if (parent[curr] && !vis.count(parent[curr])) {
                    vis.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }
            dist++;
        }

        return {};
    }
};