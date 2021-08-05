class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int len_word1 = word1.length(), len_word2 = word2.length();
        int dp[len_word1 + 1][len_word2 + 1];
        int longest = 0;
        for (int i = 0; i <= len_word1; i++)
        {
            for (int j = 0; j <= len_word2; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return len_word1 + len_word2 - 2 * dp[len_word1][len_word2];
    }
};