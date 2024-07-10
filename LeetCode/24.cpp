// 24. 两两交换链表中的节点
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* p = dummyHead;
        while(p->next != nullptr && p->next->next != nullptr){
            ListNode* t = p->next;
            ListNode* t2 = p->next->next->next;
            p->next = t->next;
            p->next->next = t;
            t->next = t2;
            p = p->next->next;
        }
        ListNode* L = dummyHead->next;
        delete dummyHead;
        return L;
    }
};