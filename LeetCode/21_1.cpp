class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* prev = dummyHead;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                prev->next = list1;
                list1 = list1 -> next;
            }else{
                prev->next = list2;
                list2 = list2 -> next;
            }
            prev = prev -> next;
        }
        prev -> next = list1 == nullptr? list2 : list1;
        return dummyHead -> next;
    }
};