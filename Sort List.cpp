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
        if(head == NULL)
        {
            return NULL;
        }

        vector<int> v;
        struct ListNode *current = head;
        while(current != NULL)
        {
            v.push_back(current->val);
            current = current->next;
        }
        sort(v.begin(), v.end());
        head = NULL;
        for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
        {
            struct ListNode *temp;
            temp = (struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val = *iter;
            temp->next = NULL;
            if(head == NULL)
            {
                head = temp;
            }
            else
            {
                struct ListNode *p = head;
                while(p->next != NULL)
                {
                    p = p->next;
                }
                p->next = temp;
            }
        }
        return head;
    }
};
