class KthLargest {
    priority_queue<int>pq;
    vector<int>curentList;
    int k;
public:
    KthLargest(int k, vector<int>& nums) 
    {
        this->k = k;
        for(const auto &iter : nums )
        {
            pq.push(iter * -1);
            if (pq.size() > k) 
            {
                pq.pop();
            }
        }
        
    }
    
    int add(int val) 
    {
        pq.push(val * -1);
        if(pq.size() > this->k)
        {
            pq.pop();
        }
        return pq.top() * -1;
    }
};
