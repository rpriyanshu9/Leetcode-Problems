class MedianFinder
{
    multiset<int> ms;
    multiset<int>::iterator it;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (ms.size() == 0)
        {
            ms.insert(num);
            it = ms.begin();
        }
        else if (ms.size() % 2 != 0)
        {
            if (num < *it)
            {
                ms.insert(num);
                it--;
            }
            else
            {
                ms.insert(num);
            }
        }
        else
        {
            if (num < *it)
            {
                ms.insert(num);
            }
            else
            {
                ms.insert(num);
                it++;
            }
        }
        // for(auto i: ms) cout<<i<<" ";
        // cout<<"\n "<<*it<<endl;
    }

    double findMedian()
    {
        if (ms.size() % 2)
        {
            return *(it)*1.0;
        }
        else
        {

            int a = *(it);
            ++it;
            int b = *(it);
            // cout<<a<<" "<<b<<endl;
            --it;
            // cout<<a+b<<endl;
            return 1.0 * (a + b) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */