class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = "";
        for(int idx = 0; strs.size() > 0; prefix = prefix + strs[0][idx], idx++)
        {
            for(int iter = 0; iter < strs.size(); iter++)
            {
                if(idx >= strs[iter].size() || iter > 0 && strs[iter][idx] != strs[iter-1][idx])
                {
                    return prefix;
                }
            }
        }
        return prefix;

    }
};
