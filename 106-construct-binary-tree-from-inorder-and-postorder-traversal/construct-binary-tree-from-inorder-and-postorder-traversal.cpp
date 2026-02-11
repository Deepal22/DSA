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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;

        map<int, int> hashMap;

        for(int i = 0; i < inorder.size(); i++){
            hashMap[inorder[i]] = i;
        }

        return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hashMap);
    }

    TreeNode* buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int>&hashMap){
        if(ps > pe || is > ie) return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int inRoot = hashMap[postorder[pe]];
        int numsleft = inRoot - is;

        root -> left = buildTreePostIn(inorder, is, inRoot - 1, postorder, ps, ps + numsleft - 1, hashMap);
        root -> right = buildTreePostIn(inorder, inRoot + 1, ie, postorder, ps + numsleft, pe - 1, hashMap);

        return root;
    }
};