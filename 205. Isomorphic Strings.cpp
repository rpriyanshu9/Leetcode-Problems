class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() == 1)
            return true;

        vector<int> m1(256, -1);
        vector<int> m2(256, -1);

        for (int i = 0; i < s.length(); i++)
        {
            if (m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = i;
            m2[t[i]] = i;
        }
        return true;
    }
};