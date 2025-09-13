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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int count=0;
        while(temp && count<k){
            temp=temp->next;
            count++;
        }
        if(count<k) return head;

        ListNode* prev=nullptr;
        temp=head;
        for(int i=0;i<k;i++){
            ListNode* nextnode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextnode;
        }
        head->next=reverseKGroup(temp,k);

        return prev;
    }
};