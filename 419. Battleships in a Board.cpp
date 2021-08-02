class Solution
{
public:
    void helper(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &board)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j] || board[i][j] == '.')
            return;
        vis[i][j] = 1;
        if ((i - 1 >= 0 && board[i - 1][j] == 'X') || (i + 1 < board.size() && board[i + 1][j] == 'X'))
        {
            helper(i - 1, j, vis, board);
            helper(i + 1, j, vis, board);
        }
        else if ((j - 1 >= 0 && board[i][j - 1] == 'X') || (j + 1 < board[0].size() && board[i][j + 1] == 'X'))
        {
            helper(i, j - 1, vis, board);
            helper(i, j + 1, vis, board);
        }
    }

    int countBattleships(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'X' && !vis[i][j])
                {
                    helper(i, j, vis, board);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};