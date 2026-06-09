class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>PQ;
        vector<int>candy(ratings.size(),0);
        for(int i = 0 ; i < ratings.size() ; ++i)
        {
            PQ.push({ratings[i],i});
        }
        ratings.push_back(40005);
        while(!PQ.empty())
        {
            auto holder = PQ.top();
            PQ.pop();
            if(holder.first > ratings[holder.second + 1])
            {
                candy[holder.second] = candy[holder.second + 1] + 1;
            }
            else if(holder.first < ratings[holder.second + 1])
            {
                candy[holder.second] = candy[holder.second] + 1;
            }
            else
            {
                candy[holder.second] = candy[holder.second] + 1;
            }
            if(holder.second - 1 >= 0 && holder.first > ratings[holder.second - 1] && candy[holder.second] <=  candy[holder.second - 1])
            {
                candy[holder.second] = candy[holder.second - 1] + 1;
            }
        }
        return accumulate(candy.begin(), candy.end(), 0);
    }
};