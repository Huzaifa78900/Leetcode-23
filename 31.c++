class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // If such element exists
        if (i >= 0) {
            
            // Step 2: Find the element just greater than nums[i]
            int j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }

            // Swap them
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the remaining elements
        reverse(nums.begin() + i + 1, nums.end());
    }
};