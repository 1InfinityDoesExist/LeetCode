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
    ListNode* middleNode(ListNode* head) {
        int len (0);
        struct ListNode *ptr = head;
        while(ptr != NULL)
        {
            len++;
            ptr = ptr->next;
        }
        /*
        if(len%2 == 0)
        {
            struct ListNode *p = head;
            int iter = 1;
            while(iter <= len/2)
            {
                p = p->next;
                iter++;
            }
            return p;
        }
        else
        {
            struct ListNode *p = head;
            int iter = 1;
            while(iter <= len/2)
            {
                p = p->next;
                iter++;
            }
            return p;
        }*/
        struct ListNode *p = head;
        int iter = 1;
        while(iter <= len/2)
        {
            p = p->next;
            iter++;
        }
        return p;
    }
};
