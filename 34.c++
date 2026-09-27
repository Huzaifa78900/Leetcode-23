class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        // Find first position >= target
        int left = 0, right = n - 1;
        int first = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) {
                if (nums[mid] == target)
                    first = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Target does not exist
        if (first == -1)
            return {-1, -1};

        // Find last position <= target
        left = 0;
        right = n - 1;
        int last = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                if (nums[mid] == target)
                    last = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {first, last};
    }
};
