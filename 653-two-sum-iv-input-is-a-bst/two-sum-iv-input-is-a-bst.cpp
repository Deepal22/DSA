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
private:
    class BSTIterator {
    private:
        stack<TreeNode*> st;
        bool reverse = false;

        void pushAll(TreeNode* root) {
            while(root != nullptr) {
                st.push(root);
                if (!reverse) root = root->left;
                else root = root->right;
            }
        }

    public:
        BSTIterator(TreeNode* root, bool rev = false) {
            reverse = rev;
            pushAll(root);
        }

        int next() {
            TreeNode* temp = st.top();
            st.pop();
            if (!reverse) pushAll(temp->right);
            else pushAll(temp->left);
            return temp->val;
        }

        bool hasNext() {
            return !st.empty();
        }
    };

public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator next = BSTIterator(root);
        BSTIterator before = BSTIterator(root, true);

        int i = next.next();
        int j = before.next();
        while(i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = next.next();
            else j = before.next();
        }

        return false;
    }
};