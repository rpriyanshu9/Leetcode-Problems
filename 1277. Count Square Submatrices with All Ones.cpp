class Solution
{
public:
    int countSquares(vector<vector<int>> &mat)
    {
        int cnt = 0;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pre[i][j] = pre[i][j - 1] + mat[i - 1][j - 1];
                if (mat[i - 1][j - 1] == 1)
                    cnt++;
            }
        }
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                pre[i][j] += pre[i - 1][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int siz = 2; siz <= min(n, m); siz++)
                {
                    if (i + siz - 1 <= n && j + siz - 1 <= m)
                    {
                        int i_temp = i + siz - 1;
                        int j_temp = j + siz - 1;
                        if ((pre[i_temp][j_temp] - pre[i_temp - siz][j_temp] - pre[i_temp][j_temp - siz] + pre[i_temp - siz][j_temp - siz]) == (siz * siz))
                            cnt++;
                        else
                            break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};