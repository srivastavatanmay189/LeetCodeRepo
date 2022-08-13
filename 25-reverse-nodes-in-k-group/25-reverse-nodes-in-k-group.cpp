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
    ListNode *reverse(ListNode *head)
    {
        if(!head||!head->next)
        {
            return head;
        }
        ListNode *temp=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
        {
            return head;
        }
        int cnt=k-1;
        ListNode* curr=head;
        ListNode *next=curr->next;
        while(next&&cnt--)
        {
            curr=curr->next;
            next=next->next;
        }
        if(cnt>0)
        {
            return head;
        }
        else
        {
            curr->next=NULL;
            ListNode *temp=reverse(head);
            head->next=reverseKGroup(next,k);
            return temp;    
        }
        
    }
};