class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string result = "";
        for(const auto &str : strs)
        {
            result += to_string(str.size()) + "$" + str;
        }
        return result;
    }

    vector<string> decode(string s) 
    {
        vector<string>result;
        int iter = 0;
        while(!s.empty())
        {
            int idxofDelemeter = s.find("$");
            string temp = s.substr(0,idxofDelemeter);
            int length = stoi(temp);
            result.push_back(s.substr(idxofDelemeter + 1,length));
            cout<<result[result.size() - 1]<<endl;
            cout<<length<<endl;
            s = s.substr(idxofDelemeter + length + 1, s.size());
        }
        return result;
    }
};
