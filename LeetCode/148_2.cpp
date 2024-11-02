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
    ListNode* sortList(ListNode* head) { 
        return mergeSort(head);
    }

    /**
     * 对给定的链表进行归并排序
    */
    ListNode* mergeSort(ListNode* head){
        // 如果链表为空或只有一个节点，无需排序直接返回
        if(!head || !head->next){
            return head;    
        }
        // 获取链表的中间节点，分别对左右子链表进行排序
        ListNode* mid = getMid(head);
        ListNode* rightSorted = mergeSort(mid->next);   // 排序右子链表
        mid->next = nullptr;                            // 断开两段子链表
        ListNode* leftSorted = mergeSort(head);         // 排序左子链表
        return mergeTwoLists(leftSorted, rightSorted);  // 两个子链表必然有序，合并两个有序的链表
    }

    /**
     * 获取以head为头节点的链表中间节点
     * 如果链表长度为奇数，返回最中间的那个节点
     * 如果链表长度为偶数，返回中间靠左的那个节点
    */
    ListNode* getMid(ListNode* head){
        if(!head)return head;   
        ListNode* slow = head, *fast = head->next;          // 快慢指针，慢指针初始为
        while(fast != nullptr && fast->next != nullptr)     
        {
            fast = fast->next->next;    // 快指针每次移动两个节点
            slow = slow->next;          // 慢指针每次移动一个节点
        }
        return slow;    // 快指针到达链表尾部时，慢指针即指向中间节点
    }

    /**
     * 合并两个有序链表list1和list2
    */
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};