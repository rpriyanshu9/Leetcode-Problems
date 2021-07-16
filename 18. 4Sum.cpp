class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        if (nums.size() < 4)
            return ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            if (i != 0)
            {
                if (nums[i] == nums[i - 1])
                {
                    continue;
                }
            }
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j != i + 1)
                {
                    if (nums[j] == nums[j - 1])
                    {
                        continue;
                    }
                }
                int left = j + 1;
                int right = n - 1;
                int cur = nums[i] + nums[j];
                while (left < right)
                {
                    if (cur + nums[left] + nums[right] == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left + 1 < n - 1 && nums[left + 1] == nums[left])
                            left++;
                        left++;
                        while (right - 1 >= 0 && nums[right - 1] == nums[right])
                            right--;
                        right--;
                    }
                    else if (cur + nums[left] + nums[right] < target)
                    {
                        while (left + 1 < n - 1 && nums[left + 1] == nums[left])
                            left++;
                        left++;
                    }
                    else
                    {
                        while (right - 1 >= 0 && nums[right - 1] == nums[right])
                            right--;
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};