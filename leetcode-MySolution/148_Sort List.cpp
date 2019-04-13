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
    ListNode* sortList(ListNode* head) {
        if(!head)
            return nullptr;
        
        ListNode* ptr=head,*tail=head;
        while(tail->next!=nullptr)
            tail = tail->next;
        
        return mergeList(head, tail);
    }
    
    // 合并两个排好序的链表
    ListNode* mergeSortedList(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode * dummyPtr = &dummy;
        while(l1 && l2){
            if(l1->val > l2->val){
                dummyPtr->next = l2;
                l2 = l2->next;
            }
            else{
                dummyPtr->next = l1;
                l1 = l1->next;
            }
            dummyPtr = dummyPtr->next;
        }
        dummyPtr->next = (l1)?l1:l2;
        return dummy.next;
    }
    
    // 利用快慢指针找到中间节点
    ListNode* getMid(ListNode* head){
        // 快慢指针，一遍就找到中间点
        ListNode* slow = head, * fast = head->next;
        while(slow && fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    //递归的合并
    ListNode* mergeList(ListNode* head, ListNode* tail){
        if(head==tail)
            return head;
        
        ListNode* mid = getMid(head);
        ListNode* l2 = mergeList(mid->next,tail);
        mid->next = nullptr;    //把两个链表断开
        ListNode* l1 = mergeList(head, mid);
        return mergeSortedList(l1, l2);
    }
    
    
    
    
    
};