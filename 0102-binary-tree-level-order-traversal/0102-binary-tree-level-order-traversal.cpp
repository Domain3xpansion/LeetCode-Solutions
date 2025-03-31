/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> visited;
        if(root == NULL) 
            return visited;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qS = q.size();
            vector<int> level;
            for(int i = 0; i<qS; i++){
                TreeNode* elem = q.front();
                level.push_back(elem->val);
                if(elem->left != NULL)
                    q.push(elem->left);
                if(elem->right != NULL)
                    q.push(elem->right);
                q.pop();
            }
            visited.push_back(level);
        }
        return visited;
    }
};