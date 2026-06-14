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
    int pairSum(ListNode* head) {
        
        stack<int>st;

        ListNode* curr = head;

        while(curr != NULL){
            st.push(curr->val);
            curr = curr->next;
        }

        int N = st.size();
        curr = head;

        int cnt = 1;

        int ans = 0;

        while(cnt <= N/2){

            ans = max(ans,curr->val+st.top());
            curr = curr->next;
            st.pop();
            cnt++;
        }
        
        return ans;
    }
};