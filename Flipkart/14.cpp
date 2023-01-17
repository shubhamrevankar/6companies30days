// 791. Custom Sort String
class Solution {
public:
    unordered_map<char,int> m;
    string customSortString(string order, string s) {
        for(int i=0;i<order.length();i++){
            m[order[i]] = i;
        }
        bool sorted=false;
        while(!sorted){
            sorted=true;
            for(int i=0;i<s.length()-1;i++){
                if(m[s[i]]>m[s[i+1]]){
                    swap(s[i],s[i+1]);
                    sorted=false;
                }
            }
        }
        return s;
    }
};