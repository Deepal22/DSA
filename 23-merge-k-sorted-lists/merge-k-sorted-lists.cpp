/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size() == 0) return nullptr ;
        if(arr.size() < 2) return arr[0] ;
        ListNode * dummy = new ListNode(0) ;
        ListNode * temp = dummy ;
        ListNode * node1  = arr[0] ;
        ListNode * node2 = arr[1] ;
        for(int i = 1 ; i < arr.size() ; i++){
            temp = dummy;
            if(i == 1)
            node1 = arr[i-1];
            else{
                node1 = dummy->next;
            }
            node2 = arr[i];
        while(node1 && node2){
            if(node1->val < node2->val){
                temp->next = node1;
                node1 = node1->next;
                temp = temp->next;
            }else{
                temp->next = node2;
                node2 = node2->next;
                temp = temp->next;
            }
        }
        if(node1){
            temp->next = node1;
        }
        if(node2){
            temp->next= node2;
        }
        }
        return dummy->next;
    }
};