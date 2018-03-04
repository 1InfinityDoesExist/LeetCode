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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {

        if(m == n || head == NULL)
        {
            return head;
        }
        bool flag = false;
        if(m == 1)
        {
            flag = true;
        }
        struct ListNode *node = head;
        int len (0);
        while(node != NULL)
        {
            len++;
            node = node->next;
        }

        if(n > len)
        {
            return head;
        }

        if(m == 1 && n == len && m != n)
        {

            struct ListNode *prev = NULL;
            struct ListNode *current = head;
            struct ListNode *next;
            while(current != NULL)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
            return head;
        }
        if(flag)
        {

            struct ListNode *ptr = head;
            struct ListNode *qtr = head;

            for(int iter = 1; iter < n; iter++)
            {
                qtr = qtr->next;
            }

            struct ListNode *prev = NULL;
            struct ListNode *current = ptr;
            struct ListNode *next;
            while(prev != qtr)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
           ptr->next = current;
           return prev;

        }



        //if not true...

        struct ListNode *ptr = head;
        struct ListNode *ptrTail = NULL;
       for(int iter = 1; iter < m ;iter++)
       {
            ptrTail = ptr;
            ptr = ptr->next;
        }

        struct ListNode *qtr = head;

        for(int iter = 1; iter < n ; iter++)
        {
            qtr = qtr->next;
        }

        struct ListNode *prev = NULL;
        struct ListNode *current = ptr;
        struct ListNode *next;
        while(prev != qtr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        ptrTail->next = prev;
        ptr->next = current;
        return head;

    }
};
