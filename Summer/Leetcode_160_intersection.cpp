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
            unordered_set<ListNode*> nodes;
            ListNode* tmp = headA;
    
            while(tmp != nullptr) {
                nodes.insert(tmp);
                tmp = tmp->next;
            }
            
            tmp = headB;
            while(tmp != nullptr) {
                if(nodes.count(tmp)) {
                    return tmp;
                }
                tmp = tmp->next;
            }
    
            return nullptr;
        }
    };