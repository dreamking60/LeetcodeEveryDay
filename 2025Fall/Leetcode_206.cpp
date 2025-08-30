// Leetcode 206: Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1. Iteration
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* pre = nullptr;
            ListNode* next = head;
            ListNode* tmp;
            while(next != nullptr) {
                tmp = next->next;
                next->next = pre;
                pre = next;
                next = tmp;
            }
    
            return pre;
        }
    };