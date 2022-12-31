// 150. Evaluate Reverse Polish Notation
class Solution {
public:
    long long opr(long long a,long long b,string x){
        if(x=="+") return a+b;
        if(x=="-") return b-a;
        if(x=="*") return a*b;
        else return b/a;
    }
    long long evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for(auto x:tokens){
            if(x=="+"||x=="-"||x=="*"||x=="/"){
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(opr(a,b,x));
            }
            else{
                s.push(stoi(x));
            }
        }
        return s.top();
    }
};