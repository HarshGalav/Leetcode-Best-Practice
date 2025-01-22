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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0;
        int m=0;
        ListNode *a=headA;
        ListNode *b=headB;
        while(a!=NULL){
            a=a->next;
            n++;
        }
        while(b!=NULL){
            b=b->next;
            m++;
        }
        a=headA;
        b=headB;
        if(n>m){
            int j=n-m;
            for(int i=0;i<j;i++){
                a=a->next;
            }
        }
        else if(m>n){
            int j=m-n;
            for(int i=0;i<j;i++){
                b=b->next;
            }
        }
        // a=headA;
        // b=headB;
        while(a!=NULL){
            if(a==b){
                return a;
            }
            a=a->next;
            b=b->next;
        }
        return NULL;
    }
};