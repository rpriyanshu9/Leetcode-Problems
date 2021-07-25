class Solution
{
public:
    int res = 0;
    void helper(int curr, int limit)
    {
        if (curr > limit)
            return;
        res++;
        helper(curr << 1, limit);
        if ((curr & 1) != 1)
        {
            helper((curr << 1) + 1, limit);
        }
    }

    int findIntegers(int n)
    {
        if (n <= 1)
            return n + 1;

        //BFS
        // int level = (int)log2(n);
        // level++;
        // int cnt=1;
        // queue<int> q;
        // q.push(1);
        // while(level--){
        //     cnt+=q.size();
        //     int siz = q.size();
        //     while(siz--){
        //         int tmp = q.front();
        //         q.pop();
        //         if(level==1){
        //             if((tmp<<1)<=n) cnt++;
        //             if((tmp&1)!=1){
        //                 if(((tmp<<1)+1)<=n) cnt++;
        //             }
        //             continue;
        //         }
        //         q.push(tmp<<1);
        //         if((tmp&1)!=1){
        //             q.push((tmp<<1)+1);
        //         }
        //     }
        // }
        // return cnt;

        //DFS
        //Verdict: 527 / 527 test cases passed, but took too long.
        res = 1;
        helper(1, n);
        return res;
    }
};