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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* temp=head;
        int val=1;
        while(temp->next!=NULL){
            temp=temp->next;
            val++;
        }
        temp->next=head;
        k=k%val;
        if(k==0){
            temp->next=nullptr;
            return head;
        }
        int newval=val-k;
        while(newval!=0){
            temp=temp->next;
            newval--;
        }
        ListNode* newhead=temp->next;
        temp->next=nullptr;
        return newhead;
        
    }
};