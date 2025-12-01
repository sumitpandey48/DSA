class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int a = nums1.size(), b = nums2.size();
        int i = 0, j = 0;

        while (i < a && j < b) {
            if (nums1[i] < nums2[j]) {
                nums3.push_back(nums1[i]);
                i++;
            } else {
                nums3.push_back(nums2[j]);
                j++;
            }
        }

        while (i < a) {
            nums3.push_back(nums1[i]);
            i++;
        }
        while (j < b) {
            nums3.push_back(nums2[j]);
            j++;
        }
        int c = a + b;
        if (c % 2 == 1) {
            return nums3[c / 2];
        } else {
            return (nums3[c / 2 - 1] + nums3[c / 2]) / 2.0;
        }
    }
};