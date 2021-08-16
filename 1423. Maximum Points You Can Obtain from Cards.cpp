class Solution
{
public:
    int maxScore(vector<int> &arr, int k)
    {
        vector<int> prefix(arr.size() + 1, 0), suffix(arr.size() + 1, 0);
        for (int i = 1; i <= arr.size(); i++)
        {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }
        for (int i = arr.size() - 1; i >= 0; --i)
        {
            suffix[i] = suffix[i + 1] + arr[i];
        }
        int res = INT_MIN;
        for (int i = 0; i <= k; i++)
        {
            res = max(res, prefix[i] + suffix[arr.size() - (k - i)]);
        }
        return res;
    }
};