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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        {
            return NULL;
        }
        while(lists.size() > 1)
        {
            lists.push_back(mergeTwoSortedList(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();

    }

    ListNode *mergeTwoSortedList(struct ListNode *head1, struct ListNode *head2)
    {
        if(head1 == NULL)
        {
            return head2;
        }
        if(head2 == NULL)
        {
            return head1;
        }
        if(head1->val <= head2->val)
        {
            head1->next = mergeTwoSortedList(head1->next, head2);
            return head1;
        }
        else
        {
            head2->next = mergeTwoSortedList(head1, head2->next);
            return head2;
        }
    }
};
