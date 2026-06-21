class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>a;
        a.push_back(nums[0]);

        for(int i = 1; i < nums.size();i++){
               if(nums[i] != nums[i - 1]){
                  a.push_back(nums[i]);
               }
        }
        for(int i = 0; i < a.size(); i++){
            nums[i] = a[i];
        }
        return a.size();
    }
};