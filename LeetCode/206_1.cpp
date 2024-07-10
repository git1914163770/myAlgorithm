// 206. 反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* t;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur){
            t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        return prev;
    }
};