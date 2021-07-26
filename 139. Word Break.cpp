class Solution
{
public:
    unordered_map<string, bool> dp;

    bool helper(string s, unordered_set<string> &dict)
    {
        if (s.length() <= 0)
            return true;
        if (dp.find(s) != dp.end())
            return dp[s];
        bool res = false;
        for (int i = 1; i <= s.length(); i++)
        {
            if (dict.find(s.substr(0, i)) != dict.end())
            {
                dp[s.substr(i)] = helper(s.substr(i), dict);
                res = res || dp[s.substr(i)];
            }
        }
        return res;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        for (auto word : wordDict)
        {
            dict.insert(word);
        }
        return helper(s, dict);
    }
};