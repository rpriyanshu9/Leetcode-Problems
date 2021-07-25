class Solution
{
public:
    bool check(int cx, int cy, int r, int px, int py)
    {
        int lhs = (px - cx) * (px - cx) + (py - cy) * (py - cy);
        int rhs = r * r;
        return lhs <= rhs;
    }

    int bin_lo(vector<vector<int>> &points, int limit)
    {
        int lo = 0, hi = points.size() - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (points[mid][0] < limit)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }

    int bin_hi(vector<vector<int>> &points, int limit)
    {
        int lo = 0, hi = points.size() - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (points[mid][0] <= limit)
            {
                lo = mid + 1;
            }
            else
                hi = mid;
        }
        return hi;
    }

    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {
        vector<int> res;
        sort(points.begin(), points.end());
        for (auto query : queries)
        {
            int cnt = 0;
            int start = bin_lo(points, query[0] - query[2]);
            int end = bin_hi(points, query[0] + query[2]);
            for (int i = start; i <= end; i++)
            {
                if (check(query[0], query[1], query[2], points[i][0], points[i][1]))
                    cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};