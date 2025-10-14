class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums3[n + m];
        int first = 0;
        int second = 0;
        int index = 0;

        while (first < m && second < n) {
            if (nums1[first] <= nums2[second]) {
                nums3[index] = nums1[first];
                first++, index++;
            } else {
                nums3[index] = nums2[second];
                second++, index++;
            }
        }

        while (first < m) {
            nums3[index++] = nums1[first++];
        }
        while (second < n) {
            nums3[index++] = nums2[second++];
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = nums3[i];
        }
    }
};