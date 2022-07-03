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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        for(int i=0;i<k;i++) {
            if(temp==nullptr)
                return head;
            temp=temp->next;
        }
        
        
        //reverse first k nodes
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next=nullptr;
        int count=0;
        
        while(curr && count<k) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        
        //recursion will take care the rest
        if(next)
            head->next = reverseKGroup(next,k);
        //return head of reversed list i.e., prev
        return prev;
    }
};