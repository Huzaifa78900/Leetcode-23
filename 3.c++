class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int i = 0;
        int maxLen = 0;

        for (int j = 0; j < s.length(); j++) {

            
            if (mp.find(s[j]) != mp.end() && mp[s[j]] >= i) {
                i = mp[s[j]] + 1;
            }

            // Store the latest index of the character
            mp[s[j]] = j;

            // Update the maximum length
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};