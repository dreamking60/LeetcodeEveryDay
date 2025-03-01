class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* next;

        if(cur1 == nullptr) {
            return cur2;
        }

        if(cur2 == nullptr) {
            return cur1;
        }

        if(cur1->val <= cur2->val) {
            head = cur1;
            head->next = mergeTwoLists(cur1->next, cur2);
        } else {
            head = cur2;
            head->next = mergeTwoLists(cur1, cur2->next);
        }

        return head;
    }
};