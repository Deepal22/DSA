/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void distanceRoot(TreeNode* root, int k){
        if(root == NULL || k<0){
            return;
        }
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        
        distanceRoot(root->left,k-1);
        distanceRoot(root->right,k-1);
    }
    int distance(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL){
            return -1;
        }
        if(target == root){
            distanceRoot(root, k);
            return 0;
        }
        
        int dl = distance(root->left, target, k);
        if(dl != -1){
            if(dl+1 == k){
                ans.push_back(root->val);
            }
            else{
                distanceRoot(root->right, k-dl-2);
            }
            return 1+dl;
        }
        int dr = distance(root->right, target, k);
        if(dr != -1){
            if(dr+1 == k){
                ans.push_back(root->val);
            }
            else{
                distanceRoot(root->left, k-dr-2);
            }
            return 1+dr;
        }
        return -1;
    }
    

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       distance(root, target, k);
       return ans;
    }
};