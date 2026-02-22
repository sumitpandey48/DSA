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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* findKthNode(ListNode* curr, int k) {
        while (curr != NULL && k > 1) {
            k--;
            curr = curr->next;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)
            return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr) {

            ListNode* kthNode = findKthNode(curr, k);

            if (!kthNode) {
                if (prev)
                    prev->next = curr;
                break;
            }

            ListNode* next = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = reverseLinkedList(curr);

            if (curr == head)
                head = newHead;
            else
                prev->next = newHead;

            prev = curr;
            curr = next;
        }
        return head;
    }
};
