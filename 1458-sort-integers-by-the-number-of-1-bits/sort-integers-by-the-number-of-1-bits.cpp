class Solution {
public:
    map<int,map<int,int>>m;
    bool isPerfect(int num)
    {
        return !(num & num-1);
    }
    void convert(int num)
    {
        if(isPerfect(num))
        {
            m[1][num]++;
            return;
        }

        int temp = num;
        int count = 0;
        while(num)
        {
            if(num%2==1)
            {
                count++;
            }
            num=num/2;
        }

        m[count][temp]++;
    }
    vector<int> sortByBits(vector<int>& arr) 
    {
        for(auto val: arr)
        {
            convert(val);
        }
        vector<int>ans;
        for(auto it=m.begin();it!=m.end();it++)
        {
            for(auto it1=it->second.begin();it1!=it->second.end();it1++)
            {
                while(it1->second--)
                {
                    ans.push_back(it1->first);
                }
            }
        }
        return ans;
    }
};