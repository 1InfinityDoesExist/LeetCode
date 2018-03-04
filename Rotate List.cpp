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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(k == 0 || head == NULL)
        {
            return head;
        }
        struct ListNode *current = head;
        vector<int> v;
        int len (0);
        while(current != NULL)
        {
            len++;
            v.push_back(current->val);
            current = current->next;
        }


        if(k > len)
        {
            k = k%len;
        }
        rotate(v.rbegin(), v.rbegin()+k, v.rend());
        struct ListNode *temp = NULL;
        for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
        {
            struct ListNode *p;
            p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->val = *iter;
            p->next = NULL;
            if(temp == NULL)
            {
                temp = p;
            }
            else
            {
                struct ListNode *pp = temp;
                while(pp->next != NULL)
                {
                    pp = pp->next;
                }
                pp->next = p;
            }
        }
        v.clear();
        return temp;
    }
};
