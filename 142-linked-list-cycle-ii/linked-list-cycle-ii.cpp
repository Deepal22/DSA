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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow;
        ListNode *fast;
        if(head==nullptr)return nullptr;
        slow = head->next;
        if(slow==nullptr) return nullptr;
        fast = head->next->next;
        while(slow!=fast){
            if(fast==nullptr) return nullptr;
            slow=slow->next;
            if(fast->next == nullptr) return nullptr;
            fast=fast->next->next;
        }
        slow = head;
        while(slow!=fast){
            slow=slow->next;
            fast = fast->next;
        }
        return fast;
    }
};