class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> res;
        int l = 0;
        for (auto it : mat)
        {
            int lo = 0, hi = it.size() - 1;
            if (it[hi] == 1)
            {
                res.push_back({hi + 1, l});
            }
            else
            {
                int re = -1;
                while (lo < hi)
                {
                    int mid = (lo + hi) / 2;
                    if (it[mid] <= 0)
                    {
                        hi = mid;
                    }
                    else
                    {
                        re = mid;
                        lo = mid + 1;
                    }
                }
                res.push_back({re + 1, l});
            }
            l++;
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        int i = 0;
        for (auto it : res)
        {
            i++;
            ans.push_back(it.second);
            if (i >= k)
            {
                return ans;
            }
        }
        return {};
    }
};