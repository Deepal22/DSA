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
    int ans = 0;
    vector<int> solve(TreeNode* root) {
        if (!root) return {0, INT_MAX, INT_MIN, 1};
        
        vector<int> a = solve(root->left);
        vector<int> b = solve(root->right);
        
        if (a[3] && b[3] && a[2] < root->val && b[1] > root->val) {
            int sum = root->val + a[0] + b[0];
            ans = max(ans, sum);
            return {sum, min(a[1], root->val), max(b[2], root->val), 1};
        }
        
        return {0, INT_MIN, INT_MAX, 0};
    }
    
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};