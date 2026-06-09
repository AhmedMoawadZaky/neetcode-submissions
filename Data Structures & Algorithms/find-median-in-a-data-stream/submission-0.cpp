class MedianFinder {
    priority_queue<int>pqMaxH;
    priority_queue<int,vector<int>,greater<int>>pqMinH;
public:
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        pqMaxH.push(num);
        if(!pqMaxH.empty() && !pqMinH.empty() && pqMaxH.top() > pqMinH.top())
        {
            pqMinH.push(pqMaxH.top());
            pqMaxH.pop();
        }
        if(pqMaxH.size() > 1 + pqMinH.size())
        {
            pqMinH.push(pqMaxH.top());
            pqMaxH.pop();
        }
        if(pqMinH.size()  > 1 + pqMaxH.size())
        {
            pqMaxH.push(pqMinH.top());
            pqMinH.pop();
        }
    }
    
    double findMedian() 
    {
        if(pqMaxH.size() > pqMinH.size())
        {
            return pqMaxH.top();
        }
        if(pqMinH.size() > pqMaxH.size())
        {
            return pqMinH.top();
        }
        return (pqMinH.top() + pqMaxH.top()) / 2.0;
    }
};
