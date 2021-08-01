class Solution
{
public:
    int dfs(int i, int j, int id, vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || vis[i][j] || !grid[i][j])
            return 0;
        vis[i][j] = 1;
        grid[i][j] = id;
        return 1 + dfs(i - 1, j, id, vis, grid) + dfs(i + 1, j, id, vis, grid) + dfs(i, j - 1, id, vis, grid) + dfs(i, j + 1, id, vis, grid);
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        int id = 2;
        unordered_map<int, int> mp;
        int maxx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    mp[id] = dfs(i, j, id, vis, grid);
                    maxx = max(maxx, mp[id]);
                    id++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!grid[i][j])
                {
                    int temp = 0;
                    unordered_set<int> sett;
                    if (i - 1 >= 0)
                    {
                        if (grid[i - 1][j] != 0)
                        {
                            sett.insert(grid[i - 1][j]);
                            temp += mp[grid[i - 1][j]];
                        }
                    }
                    if (i + 1 < n)
                    {
                        if (grid[i + 1][j] != 0 && sett.find(grid[i + 1][j]) == sett.end())
                        {
                            sett.insert(grid[i + 1][j]);
                            temp += mp[grid[i + 1][j]];
                        }
                    }
                    if (j - 1 >= 0)
                    {
                        if (grid[i][j - 1] != 0 && sett.find(grid[i][j - 1]) == sett.end())
                        {
                            sett.insert(grid[i][j - 1]);
                            temp += mp[grid[i][j - 1]];
                        }
                    }
                    if (j + 1 < n)
                    {
                        if (grid[i][j + 1] != 0 && sett.find(grid[i][j + 1]) == sett.end())
                        {
                            sett.insert(grid[i][j + 1]);
                            temp += mp[grid[i][j + 1]];
                        }
                    }
                    maxx = max(maxx, 1 + temp);
                }
            }
        }
        return maxx == INT_MIN ? n * n : maxx;
    }
};