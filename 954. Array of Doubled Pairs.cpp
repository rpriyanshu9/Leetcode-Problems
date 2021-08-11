class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        sort(arr.begin(), arr.end());
        for (auto it : arr)
            mp[it]++;
        for (auto it : arr)
        {
            if (2 * it < it && mp.find(2 * it) == mp.end())
                continue;
            if (it % 2 && mp[it] > 0)
            {
                if (mp.find(it * 2) != mp.end() && mp[2 * it] > 0)
                {
                    mp[it]--;
                    mp[it * 2]--;
                }
            }
            else
            {
                if (mp[it] > 0)
                {
                    if (mp.find(it * 2) != mp.end() && mp[2 * it] > 0)
                    {
                        mp[it]--;
                        mp[it * 2]--;
                    }
                }
            }
        }

        for (auto it : mp)
            if (it.second > 0)
                return false;
        return true;
    }
};