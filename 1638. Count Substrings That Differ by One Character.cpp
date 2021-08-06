class Solution
{
public:
    int countSubstrings(string s, string t)
    {
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < t.length(); j++)
            {
                if (s[i] != t[j])
                {
                    int left = 0, right = 0;
                    int tempi = i - 1, tempj = j - 1;
                    while (tempi >= 0 && tempj >= 0 && s[tempi] == t[tempj])
                    {
                        left++;
                        --tempi;
                        --tempj;
                    }
                    tempi = i + 1;
                    tempj = j + 1;
                    while (tempi < s.length() && tempj < t.length() && s[tempi] == t[tempj])
                    {
                        right++;
                        ++tempi;
                        ++tempj;
                    }
                    res += (left + 1) * (right + 1);
                }
            }
        }
        return res;
    }
};