class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxWater = 0;

        while (i < j) {
            int width = j - i;
            int currArea;

            if (height[i] < height[j])
                currArea = height[i] * width;
            else
                currArea = height[j] * width;

            if (currArea > maxWater)
                maxWater = currArea;

            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return maxWater;
    }
};