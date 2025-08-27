/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* given) {
        ListNode* temp = given->next;
        given->val = temp->val;
        given->next = temp->next;
        delete(temp);
    }    
};