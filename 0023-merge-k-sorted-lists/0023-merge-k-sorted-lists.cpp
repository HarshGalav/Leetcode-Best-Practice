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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>v;
        for(auto i:lists){
            ListNode* temp=i;
            while(temp!=NULL){
                v.push_back(temp->val);
                temp=temp->next;
            }

        }
        sort(v.begin(),v.end());
        ListNode* cur=new ListNode(0);
        ListNode* t=cur;
        for(auto i:v){
            t->next=new ListNode(i);
            t=t->next;
        }
        return cur->next;
    }
};