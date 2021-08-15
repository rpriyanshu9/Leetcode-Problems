class Solution
{
public:
    vector<vector<int>> perm;

    void make(int i, vector<int> nums)
    {
        if (i >= nums.size())
        {
            perm.push_back(nums);
            return;
        }
        for (int id = i; id < nums.size(); id++)
        {
            if (id != i && nums[id] == nums[i])
                continue;
            swap(nums[i], nums[id]);
            make(i + 1, nums);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        if (nums.size() == 1)
            return {nums};
        sort(nums.begin(), nums.end());
        make(0, nums);
        return perm;
    }
};