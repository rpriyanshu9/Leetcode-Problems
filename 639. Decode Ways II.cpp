class Solution
{
public:
    int mod = 1e9 + 7;
    unordered_map<string, long> dp;

    long helper(string s)
    {
        if (s[0] == '0')
            return 0;
        if (s.length() == 1)
        {
            if (s[0] == '*')
                return 9;
            return s[0] == '0' ? 0 : 1;
        }
        if (dp.find(s) != dp.end())
            return dp[s];
        if (s.length() == 2)
        {
            if (s[0] == '*')
            {
                if (s[1] == '0')
                    return dp[s] = 2;
                if (s[1] == '*')
                    return dp[s] = 96;
                if (stoi(s.substr(1)) >= 1 && stoi(s.substr(1)) <= 6)
                    return dp[s] = 11;
                if (stoi(s.substr(1)) >= 7 && stoi(s.substr(1)) <= 9)
                    return dp[s] = 10;
            }
            else if (s[1] == '*')
            {
                if (s[0] == '0')
                    return dp[s] = 0;
                if (s[0] == '1')
                    return dp[s] = 18;
                if (s[0] == '2')
                    return dp[s] = 15;
                if (stoi(s.substr(0, 1)) >= 3 && stoi(s.substr(0, 1)) <= 9)
                    return dp[s] = 9;
            }
            else
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
        }
        if (s[0] == '*')
        {
            if (s[1] == '0')
                return dp[s] = (helper(s.substr(1))) % mod + (2 * helper(s.substr(2))) % mod;
            if (s[1] == '*')
                return dp[s] = (9 * helper(s.substr(1))) % mod + (15 * helper(s.substr(2))) % mod;
            if (stoi(s.substr(1, 1)) >= 1 && stoi(s.substr(1, 1)) <= 6)
                return dp[s] = (9 * helper(s.substr(1))) % mod + (2 * helper(s.substr(2))) % mod;
            if (stoi(s.substr(1, 1)) >= 7 && stoi(s.substr(1, 1)) <= 9)
                return dp[s] = (9 * helper(s.substr(1))) % mod + helper(s.substr(2)) % mod;
        }
        if (s[1] == '*')
        {
            if (s[0] == '1')
                return dp[s] = helper(s.substr(1)) % mod + (9 * helper(s.substr(2))) % mod;
            if (s[0] == '2')
                return dp[s] = helper(s.substr(1)) % mod + (6 * helper(s.substr(2))) % mod;
            if (stoi(s.substr(0, 1)) >= 3 && stoi(s.substr(0, 1)) <= 9)
                return dp[s] = helper(s.substr(1)) % mod;
        }
        if (stoi(s.substr(0, 2)) > 26)
        {
            return dp[s] = helper(s.substr(1)) % mod;
        }
        return dp[s] = helper(s.substr(1)) % mod + helper(s.substr(2)) % mod;
    }

    int numDecodings(string s)
    {
        if (s.length() == 1)
        {
            if (s[0] == '*')
                return 9;
            return s[0] == '0' ? 0 : 1;
        }
        return helper(s);
    }
};