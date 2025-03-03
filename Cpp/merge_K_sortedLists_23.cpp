/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
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
        int size = lists.size();
        if(size == 0) return nullptr;
        if(size == 1) return lists[0];

        ListNode* head = mergeHalfLists(lists, 0, size - 1);

        return head;
    }

    ListNode* mergeHalfLists(vector<ListNode*>& lists, int start, int end) {
        if(start == end) return lists[start];
        if(start > end) return nullptr;

        int mid = start + (end - start) / 2;
        ListNode* left = mergeHalfLists(lists, start, mid);
        ListNode* right = mergeHalfLists(lists, mid + 1, end);

        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* head;
        if(list1->val < list2->val) {
            head = list1;
            head->next = mergeTwoLists(list1->next, list2);
        } else {
            head = list2;
            head->next = mergeTwoLists(list1, list2->next);
        }

        return head;
    }

};
// @lc code=end

