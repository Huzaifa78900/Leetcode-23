class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int answer = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {

                int currentSum = nums[i] + nums[j] + nums[k];

                if (abs(target - currentSum) < abs(target - answer)) {
                    answer = currentSum;
                }

                if (currentSum == target) {
                    return currentSum;
                }

                if (currentSum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return answer;
    }
};