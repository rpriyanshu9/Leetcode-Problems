class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq;
        for (auto pile : piles)
        {
            pq.push(pile);
        }
        for (int i = 0; i < k; i++)
        {
            int tmp = pq.top();
            pq.pop();
            if (tmp % 2)
            {
                pq.push(tmp / 2 + 1);
            }
            else
            {
                pq.push(tmp / 2);
            }
        }
        int res = 0;
        while (!pq.empty())
        {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};