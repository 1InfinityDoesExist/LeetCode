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
    *b  = temp;
}
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        struct ListNode *ptr = head;
        while(ptr != NULL && ptr->next != NULL)
        {
            swap(&ptr->val, &ptr->next->val);
            ptr = ptr->next->next;
        }
        return head;


    }
};
