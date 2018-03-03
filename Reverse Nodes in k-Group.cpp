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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        struct ListNode *cnt = head;
        int len (0);
        while(cnt != NULL)
        {
            len++;
            cnt = cnt->next;
        }
        if(k <= len)
        {
            struct ListNode *prev = NULL;
            struct ListNode *current = head;
            struct ListNode *next;
            int count (0);
            while(count < k && current != NULL)
            {
                next = current->next;
                current->next = prev;
                prev =  current;
                current = next;
                count++;
            }

            if(next != NULL)
            {
                head->next = reverseKGroup(next, k);
            }

            return prev;
        }
        else
        {
            return head;
        }

    }

};
