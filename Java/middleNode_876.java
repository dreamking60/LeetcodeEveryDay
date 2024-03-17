/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
public class middleNode_876 {

    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
        
    }

    public ListNode middleNode(ListNode head) {
        int i = 0;
        ListNode first = head;
        ListNode second = head;
        while(first.next != null) {
            if(i++%2 == 0) {
                first = first.next;
                second = second.next;
            } else {
                first = first.next;
            }
        }
        return second;
    }

    // Space Complexity: O(1)
    // Time Complexity: O(n)
    // 100%
}

