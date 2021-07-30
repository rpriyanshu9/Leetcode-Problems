class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int res = 0;
        int n = rating.size();
        for (int i = 0; i < n; i++)
        {
            int gtl = 0, ltr = 0, ltl = 0, gtr = 0;
            for (int j = 0; j < i; j++)
            {
                if (rating[j] < rating[i])
                    ltl++;
                else
                    gtl++;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (rating[j] < rating[i])
                    ltr++;
                else
                    gtr++;
            }
            res += (gtl * ltr) + (ltl * gtr);
        }
        return res;
    }
};