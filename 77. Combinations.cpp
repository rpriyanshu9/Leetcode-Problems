class Solution
{
public:
    vector<vector<int>> res;

    void helper(int start, int limit, int todo, vector<int> curr)
    {
        if (todo < 0 || start > limit)
            return;
        if (todo == 0)
        {
            res.push_back(curr);
        }
        for (int i = start + 1; i <= limit; i++)
        {
            curr.push_back(i);
            helper(i, limit, todo - 1, curr);
            curr.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k)
    {
        helper(0, n, k, {});
        return res;
    }
};