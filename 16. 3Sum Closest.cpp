class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        int n = nums.size();
        int diff = INT_MAX;
        int poss_ans = INT_MAX;
        for (int i = 0; i < n - 2; i++)
        {
            int k = target - nums[i];
            int lo = i + 1, hi = n - 1;
            while (lo < hi)
            {
                int curr = nums[lo] + nums[hi];
                if (curr == k)
                {
                    return target;
                }
                else if (curr < k)
                {
                    lo++;
                }
                else
                {
                    hi--;
                }
                if (abs(curr + nums[i] - target) < abs(diff))
                {
                    diff = curr + nums[i] - target;
                    poss_ans = curr + nums[i];
                }
            }
        }
        return poss_ans;
    }
};