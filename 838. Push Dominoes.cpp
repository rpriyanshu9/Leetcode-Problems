class Solution
{
public:
    void doAll(int curr, int end, char x, string &res)
    {
        for (int i = curr + 1; i < end; i++)
        {
            res[i] = x;
        }
        return;
    }

    void calc(int curr, int end, char atCurr, char atEnd, string &res)
    {
        int len = end - curr - 1;
        if (len % 2 == 0)
        {
            for (int i = 0; i < len / 2; i++)
            {
                res[curr + i + 1] = atCurr;
                res[end - 1 - i] = atEnd;
            }
        }
        else
        {
            len = (len - 1) / 2;
            for (int i = 0; i < len; i++)
            {
                res[curr + i + 1] = atCurr;
                res[end - 1 - i] = atEnd;
            }
        }
    }

    string pushDominoes(string dom)
    {
        int end = -1;
        char prev = '-';
        int curr = dom.size() - 1;
        while (curr >= 0)
        {
            if (curr == 0 && dom[curr] == '.')
            {
                if (prev == 'L')
                {
                    dom[curr] = 'L';
                    doAll(curr, end, 'L', dom);
                }
            }
            else if (dom[curr] == 'L')
            {
                if (prev == 'L')
                {
                    doAll(curr, end, 'L', dom);
                }
                prev = 'L';
                end = curr;
            }
            else if (dom[curr] == 'R')
            {
                if (end == -1)
                {
                    doAll(curr, dom.size(), 'R', dom);
                }
                else if (prev == 'R')
                {
                    doAll(curr, end, 'R', dom);
                }
                else if (prev == 'L')
                {
                    calc(curr, end, 'R', 'L', dom);
                }
                prev = 'R';
                end = curr;
            }
            curr--;
        }
        return dom;
    }
};