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
    unordered_map<int, int> count;
    int maxCount = 0;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for (auto & e: count)
            if (e.second == maxCount)
                res.push_back(e.first);
        return res;
    }


    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int s = dfs(root->left) + dfs(root->right) + root->val;
        maxCount = max(maxCount, ++count[s]);
        return s;
    }
};