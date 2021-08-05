class Solution
{
public:
    void firstRow(int index, int r, string &res, string &s)
    {
        if (index >= s.length())
        {
            return;
        }
        res += s[index];
        firstRow(index + r + (r - 2), r, res, s);
    }

    void middleRows(int index, int r, int prev, string &res, string &s)
    {
        if (index >= s.length())
        {
            if (index - prev < s.length())
            {
                res += s[index - prev];
            }
            return;
        }
        if (index <= r)
        {
            res += s[index];
        }
        else
        {
            res += s[index - prev];
            res += s[index];
        }
        middleRows(index + r + (r - 2), r, prev, res, s);
    }

    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string res = "";
        firstRow(0, numRows, res, s);
        for (int i = 0; i < numRows - 2; i++)
        {
            middleRows(0 + i + 1, numRows, 2 * (i + 1), res, s);
        }
        firstRow(0 + numRows - 1, numRows, res, s);
        return res;
    }
};