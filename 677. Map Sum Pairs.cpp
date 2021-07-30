class MapSum
{
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> ump;
    unordered_map<string, int> ump2;
    MapSum()
    {
    }

    void insert(string key, int val)
    {
        if ((ump2.find(key) == ump2.end()))
        {
            ump2[key] = val;
            for (int i = 1; i <= key.size(); i++)
            {
                if (ump.find(key.substr(0, i)) != ump.end())
                    ump[key.substr(0, i)] += val;
                else
                {
                    ump[key.substr(0, i)] = val;
                }
            }
        }
        else
        {
            for (int i = 1; i <= key.size(); i++)
            {
                ump[key.substr(0, i)] -= ump2[key];
                ump[key.substr(0, i)] += val;
            }
            ump2[key] = val;
        }
    }

    int sum(string prefix)
    {
        return ump[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
s