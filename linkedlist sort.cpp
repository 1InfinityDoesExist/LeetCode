/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        for(struct ListNode *current = head; current->next != NULL; current = current->next)
        {
            for(struct ListNode *selection = current->next; selection != NULL; selection = selection->next)
            {
                if(current->val > selection->val)
                {
                    swap(&current->val, &selection->val);
                }
            }
        }
        return head;
    }
};
