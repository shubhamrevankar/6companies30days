// 1054. Distant Barcodes
class Solution {
public:
    static class comp{
        public:
            bool operator()(const pair<int,int> &a,const pair<int,int> &b){
                return a.second<b.second;
            }
    };
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> m;
        for(auto x:barcodes) m[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        for(auto x:m) pq.push(x);
        vector<int> res;int p=-1;
        while(!pq.empty()){
            if(p!=pq.top().first){
                pair<int,int> t = pq.top();
                pq.pop();
                res.push_back(t.first);
                p = t.first;
                t.second--;
                if(t.second)
                    pq.push(t);
            }
            else{
                pair<int,int> pre = pq.top();
                pq.pop();
                pair<int,int> t = pq.top();
                pq.pop();
                res.push_back(t.first);
                p = t.first;
                t.second--;
                if(t.second)
                    pq.push(t);
                pq.push(pre);
            }
        }
        return res;
    }
};