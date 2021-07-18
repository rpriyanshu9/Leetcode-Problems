// RTE Solution due to overflow in calculating decimal equivalent of binary representation

class Solution
{
public:
    vector<int> gl_ans = {-1, -1};

    long to_decimal(vector<int> &arr, int start, int end)
    {
        long res = 0;
        for (int i = end, j = 0; i >= start; i--, j++)
            if (arr[i] == 1)
                res += pow(2, j);
        return res;
    }

    void helper(vector<int> &arr, int start, int sz, int level, vector<long> curr, vector<int> &ans)
    {
        if (level > 3)
            return;
        if (sz == 0)
            return;
        if (level == 3)
        {
            long now = to_decimal(arr, start, (start + sz) - 1);
            if (now == curr[0] && now == curr[1])
            {
                ans[1]++;
                gl_ans = ans;
            }
            return;
        }
        int limit = 3 - level;
        for (int i = start, j = 1; i < (start + sz) - limit; i++, j++)
        {
            curr.push_back(to_decimal(arr, start, i));
            ans.push_back(i);
            helper(arr, i + 1, sz - j, level + 1, curr, ans);
            curr.pop_back();
            ans.pop_back();
        }
    }

    vector<int> threeEqualParts(vector<int> &arr)
    {
        vector<long> curr = {};
        vector<int> ans = {};
        helper(arr, 0, arr.size(), 1, curr, ans);
        return gl_ans;
    }
};