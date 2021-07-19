class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (mid == 0)
            {
                if (nums[mid] > nums[mid + 1])
                {
                    return nums[(mid + 1) % n];
                }
            }
            else if (mid == n - 1)
            {
                if (nums[mid] > nums[mid - 1])
                {
                    return nums[(mid + 1) % n];
                }
            }
            else
            {
                if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                {
                    return nums[(mid + 1) % n];
                }
            }
            if (nums[lo] <= nums[mid])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return -1;
    }
};