// Can be solved greedily too
class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> ump;
        for (auto it : arr)
        {
            ump[it]++;
        }
        vector<pair<int, int>> p;
        for (auto it : ump)
        {
            p.push_back({it.second, it.first});
        }
        sort(p.begin(), p.end());
        int n = arr.size();
        int max = p.back().first;
        p.pop_back();
        int req = n - max;
        int res = 1;
        while (req > n / 2)
        {
            pair<int, int> x = {req, 0};
            auto it = lower_bound(p.begin(), p.end(), x);
            if (it == p.end())
            {
                req -= p.back().first;
                p.pop_back();
            }
            else
            {
                req -= (*it).first;
                p.erase(it);
            }
            res++;
        }
        return res;
    }
};