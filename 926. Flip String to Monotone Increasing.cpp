class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int prefix[s.length()];
        prefix[0] = s[0] - '0';
        for (int i = 1; i < s.length(); i++)
        {
            prefix[i] = prefix[i - 1] + (s[i] - '0');
        }
        int last_index = s.length() - 1;
        int t1 = prefix[last_index], t2 = s.length() - prefix[last_index];
        int res = min(t1, t2);
        for (int i = 0; i <= last_index; i++)
        {
            int ones_left = prefix[i];
            int zeros_right = (last_index - i) - (prefix[last_index] - prefix[i]);
            res = min(res, ones_left + zeros_right);
        }
        return res;
    }
};