// 692. Top K Frequent Words
class Solution {
public:
    static bool comp(const pair<string,int> &a,const pair<string,int> &b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto x:words){
            m[x]++;
        }
        vector<pair<string,int>> v;
        for(auto x:m){
            v.push_back({x.first,x.second});
        }
        sort(v.begin(),v.end(),comp);
        vector<string> res;
        for(int i=0;i<k;i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};