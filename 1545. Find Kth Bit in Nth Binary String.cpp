class Solution
{
public:
    //Brute

    void helper(string &s, int n)
    {
        if (n <= 0)
            return;
        s += "1";
        int siz = s.length();
        for (int i = siz - 2; i >= 0; --i)
        {
            if (s[i] == '1')
                s += "0";
            else
                s += "1";
        }
        helper(s, n - 1);
    }

    char findKthBit(int n, int k)
    {
        string num = "0";
        helper(num, n - 1);
        return num[k - 1];
    }
};