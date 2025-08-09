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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        // ListNode* temp=prev->next;
        if(prev!=nullptr&&prev->next!=nullptr)
        prev->next=prev->next->next;
        // delete(temp);
        return head;
    }
};