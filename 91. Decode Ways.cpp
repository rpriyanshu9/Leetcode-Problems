class Solution
{
public:
    unordered_map<string, int> dp;

    int helper(string s)
    {
        if (s[0] == '0')
            return 0;
        if (dp.find(s) != dp.end())
            return dp[s];
        if (s.length() == 1)
        {
            return dp[s] = 1;
        }
        if (s.length() == 2)
        {
            int res = 0;
            int num = stoi(s);
            if (num >= 10 && num <= 26)
            {
                if (num % 10)
                    res = 2;
                else
                    res = 1;
            }
            else if (s[1] != '0')
            {
                res = 1;
            }
            return dp[s] = res;
        }
        if (s.length() >= 2)
        {
            if (stoi(s.substr(0, 2)) > 26)
            {
                return dp[s] = helper(s.substr(1));
            }
        }
        return dp[s] = helper(s.substr(1)) + helper(s.substr(2));
    }

    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        return helper(s);
    }
};