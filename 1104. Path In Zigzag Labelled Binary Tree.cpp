class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        int level = 0;
        while ((1 << level) <= label)
            level++;
        vector<int> res;
        while (label >= 1)
        {
            res.push_back(label);
            int inversion = (1 << level) - 1 + (1 << (level - 1)) - label;
            label = inversion / 2;
            level--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};