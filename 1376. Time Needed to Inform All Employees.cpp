class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        unordered_map<int, vector<int>> mp;
        vector<int> timeNeeded(informTime.size(), 0);
        timeNeeded[headID] = 0;
        int i = 0;
        for (auto it : manager)
        {
            mp[it].push_back(i++);
        }
        queue<int> q;
        q.push(headID);
        int res = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int t = q.front();
                q.pop();
                for (auto it : mp[t])
                {
                    timeNeeded[it] += timeNeeded[t] + informTime[t];
                    res = max(res, timeNeeded[it]);
                    q.push(it);
                }
            }
        }
        return res;
    }
};