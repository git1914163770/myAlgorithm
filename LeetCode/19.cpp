// 19. 删除链表的倒数第 N 个结点

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* p = dummyHead;
        ListNode* slow = dummyHead;
        // 1 <= n <= sz 不用加p != null 判断
        while(n--){
            p = p->next;
        }
        // 要找到倒数第n个节点前一个节点
        while(p->next != nullptr){
            p = p->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};