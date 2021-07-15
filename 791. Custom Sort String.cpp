class Solution
{
public:
    string customSortString(string order, string str)
    {
        unordered_map<char, int> mp;
        string res = "";
        for (auto i : str)
            mp[i]++;
        for (auto i : order)
        {
            res += string(mp[i], i);
            mp.erase(i);
        }
        for (auto i : mp)
        {
            res += string(i.second, i.first);
        }
        return res;
    }
};