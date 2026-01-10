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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *oh = new ListNode(-1), *ot = oh;
        ListNode *eh = new ListNode(-1), *et = eh;
        ListNode* curr = head;
        int pos = 1;

        while (curr != NULL) {
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            if (pos % 2 == 1) {
                ot->next = temp;
                ot = temp;
            } else {
                et->next = temp;
                et = temp;
            }
            pos++;
        }

        ot->next = eh->next;
        return oh->next;
    }
};