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
class Solution{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans = new ListNode();
        ListNode *current = ans;

        int kMain = lists.size();
        int k = kMain;
        int i = 0;
        int minVal = INT_MAX;
        int minIdx = -1;

        while (k > 0)
        {
            if (lists[i] != nullptr && lists[i]->val < minVal)
            {
                minVal = lists[i]->val;
                minIdx = i;
            }

            i++;

            if (i == kMain)
            {
                if (minIdx == -1) break;

                current->next = new ListNode(minVal);
                current = current->next;

                lists[minIdx] = lists[minIdx]->next;

                minVal = INT_MAX;
                minIdx = -1;
                i = 0;
            }
        }

        return ans->next;
    }
};


