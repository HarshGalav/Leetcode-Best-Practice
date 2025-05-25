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
        int len=1;
        
        while(temp->next != NULL){
            temp=temp->next;
            len++;
        }
        k=k%len;
         if (k == 0) {
            temp->next = nullptr; 
            return head;
        }
        temp->next=head;
        int a=len-k;
        while(a>0){
            a--;
            temp=temp->next;

        }
        head=temp->next;
        temp->next=NULL;
        return head;

    }
};