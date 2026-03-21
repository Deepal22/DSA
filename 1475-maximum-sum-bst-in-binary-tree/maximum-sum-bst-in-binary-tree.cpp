/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    struct NodeValue {
        int minNode, maxNode, sum;
        bool isBST;

        NodeValue(int minNode, int maxNode, int sum, bool isBST) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->sum = sum;
            this->isBST = isBST;
        }
    };
    int maxSum = 0;
    NodeValue helper(TreeNode* root) {
        if (root == NULL) {
            return NodeValue(INT_MAX, INT_MIN, 0, true);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left.isBST && right.isBST && root->val > left.maxNode &&
            root->val < right.minNode) {
            int currSum = left.sum + right.sum + root->val;

            maxSum = max(maxSum, currSum);

            return NodeValue(min(root->val, left.minNode),
                             max(root->val, right.maxNode), currSum, true);
        }

        return NodeValue(INT_MIN, INT_MAX, 0, false);
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};