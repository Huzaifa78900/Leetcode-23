class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = strs[0];

        for (int i = 1; i < strs.size(); i++) {

            while (strs[i].substr(0, ans.length()) != ans) {

                ans.pop_back();

                if (ans.empty())
                    return "";
            }
        }

        return ans;
    }
};