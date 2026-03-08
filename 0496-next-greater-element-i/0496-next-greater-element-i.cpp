class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < n1; i++) {
            int indx = -1;

            for (int j = 0; j < n2; j++) {
                if (nums2[j] == nums1[i]) {
                    indx = j;
                    break;
                }
            }
            int nxt = -1;

            for (int j = indx + 1; j < n2; j++) {
                if (nums2[j] > nums1[i]) {
                    nxt = nums2[j];
                    break;
                }
            }
            res.push_back(nxt);
        }
        return res;
    }
};