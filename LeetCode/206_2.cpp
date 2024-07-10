// 206. 反转链表
class Solution {
public:

    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == nullptr) return pre;
        ListNode* t = cur->next;
        cur->next = pre;
        return reverse(cur,t);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr,head);
    }

    // https://leetcode.cn/problems/reverse-linked-list/
    // ListNode* reverseList(ListNode* head) {
    //     if (head == nullptr || head->next == nullptr) {
    //         return head;
    //     }
    //     // 这里的cur就是最后一个节点
    //     ListNode* cur = reverseList(head->next);
	// 	// 这里请配合动画演示理解
	// 	// 如果链表是 1->2->3->4->5，那么此时的cur就是5
	// 	// 而head是4，head的下一个是5，下下一个是空
	// 	// 所以head.next.next 就是5->4
    //     head->next->next = head;
    //     // 防止链表循环，需要将head.next设置为空
    //     head->next = nullptr;
    //     // 每层递归函数都返回cur，也就是最后一个节点
    //     return cur;
    // }
};