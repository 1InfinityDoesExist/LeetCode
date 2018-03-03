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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL)
        {
            return NULL;
        }
        if(head->next == NULL && n == 1)
        {
            return NULL;
        }
        int length (0);
        struct ListNode *current = head;
        while(current != NULL)
        {
            current = current->next;
            length++;
        }
        current = head;
        struct ListNode *prev = NULL;
        for(int iter = 1; iter < length-n+1; iter++)
        {
            prev = current;
            current = current->next;
        }
        struct ListNode *temp;
        if(current->val == head->val && current->next == head->next)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        else
        {
            prev->next = current->next;
            free(current);
        }
        return head;
    }
};
