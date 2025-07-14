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
    int getDecimalValue(ListNode* head) {
       
        int ans=0;
        vector<int>temp;
        while(head!=NULL){
            temp.push_back(head->val);
            head=head->next;

        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            ans=ans+pow(2,i)*temp[i];
        }
        return ans;
    }
};