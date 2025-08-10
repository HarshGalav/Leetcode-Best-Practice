class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        int carry = 0;

        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2 != nullptr) {
            ListNode* x = l2;
            ListNode* last = nullptr;
            while (l2 != nullptr) {
                int sum = l2->val + carry;
                l2->val = sum % 10;
                carry = sum / 10;
                last = l2;
                l2 = l2->next;
            }
            if (carry) last->next = new ListNode(carry);
            temp->next = x;
        }
        else if (l1 != nullptr) {
            ListNode* x = l1;
            ListNode* last = nullptr;
            while (l1 != nullptr) {
                int sum = l1->val + carry;
                l1->val = sum % 10;
                carry = sum / 10;
                last = l1;
                l1 = l1->next;
            }
            if (carry) last->next = new ListNode(carry);
            temp->next = x;
        }
        else {
            if (carry != 0) {
                temp->next = new ListNode(carry);
            }
        }

        return ans->next;
    }
};
