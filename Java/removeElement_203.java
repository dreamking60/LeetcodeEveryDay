public class removeElement_203 {
    public ListNode removeElements(ListNode head, int val) {
        while(head != null) {
            if(head.val == val) {
                head = head.next;
            } else {
                break;
            }
        }
        ListNode next = head;
        while(next != null && next.next != null) {
            if(next.next.val == val) {
                next.next = next.next.next;
            } else {
                next = next.next;
            }
        }
        return head;
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}


class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

