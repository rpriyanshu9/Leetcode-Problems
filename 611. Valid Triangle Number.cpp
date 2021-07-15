class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = nums[i] + nums[j];
                int lo = j + 1, hi = n - 1;
                int ans = 0;
                if (lo <= n - 1)
                {
                    while (lo <= hi)
                    {
                        int mid = lo + (hi - lo) / 2;
                        if (nums[mid] < sum)
                        {
                            ans = mid;
                            lo = mid + 1;
                        }
                        else
                        {
                            hi = mid - 1;
                        }
                    }
                    if (ans > 0)
                        res += ans - j;
                }
            }
        }
        return res;
    }
};