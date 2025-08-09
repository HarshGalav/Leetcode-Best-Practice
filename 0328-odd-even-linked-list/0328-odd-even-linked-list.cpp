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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenHead=new ListNode(-1);
        ListNode* oddHead= new ListNode(-1);
        ListNode* evenTail=evenHead;
        ListNode* oddTail=oddHead;
        ListNode* cur=head;
        ListNode* temp;
        int cnt=0;
        while(cur){
            cnt++;
            int val=cur->val;
            if(cnt%2==0){
                evenTail->next=new ListNode(val);
                evenTail=evenTail->next;
            }
            else{
                oddTail->next=new ListNode(val);
                oddTail=oddTail->next;
            }
            cur=cur->next;
        }
        oddTail->next=evenHead->next;
        return oddHead->next;
    }
};