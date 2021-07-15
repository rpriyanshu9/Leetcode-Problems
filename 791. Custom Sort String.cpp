class Solution
{
public:
    string customSortString(string order, string str)
    {
        string res = "";
        bool visit[200] = {false};
        for (int i = 0; i < order.length(); i++)
        {
            for (int j = 0; j < str.length(); j++)
            {
                if (str[j] == order[i])
                {
                    res += str[j];
                    visit[j] = true;
                }
            }
        }
        for (int j = 0; j < str.length(); j++)
        {
            if (visit[j] == false)
            {
                res += str[j];
            }
        }
        return res;
    }
};