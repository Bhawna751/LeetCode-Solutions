class Solution {
public:
    static bool comparator(pair<int,char> p1, pair<int,char> p2){
        if(p1.first > p2.first) return true;
        if(p1.first < p2.first) return false;
        return p1.second < p2.second;
    }

    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char ch : s){
            freq[ch]++;
        }

        vector<pair<int,char>> arr;
        for(auto &it : freq){
            arr.push_back({it.second, it.first});
        }

        sort(arr.begin(), arr.end(), comparator);

        string ans="";
        for(auto &p : arr){
            ans.append(p.first, p.second); 
        }
        return ans;
    }
};
