// 反转链表 递归 更简单的写法
class Solution {
public:
    ListNode *newHead = nullptr;
    void reverse(ListNode* cur){
        // 递归要返回最后一个元素
        if(!cur->next){ 
            newHead = cur;
            return;
        }
        reverse(cur->next);
        cur->next->next = cur;
        cur->next = nullptr;
        return;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        reverse(head);
        return newHead;
    }
};