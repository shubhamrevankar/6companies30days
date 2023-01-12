//1169. Invalid Transactions
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<string> name,city;
        vector<int> time,amount;
        for(auto s:transactions){
            string tmp="";
            int i=0,ns=s.length();
            while(s[i]!=','){
                tmp += s[i++];
            }i++;
            name.push_back(tmp);
            tmp = "";
            while(s[i]!=','){
                tmp += s[i++];
            }i++;
            time.push_back(stoi(tmp));
            tmp = "";
            while(s[i]!=','){
                tmp += s[i++];
            }i++;
            amount.push_back(stoi(tmp));
            tmp = "";
            while(i<ns){
                tmp += s[i++];
            }
            city.push_back(tmp);
        }
        vector<string> res;
        for(int i=0;i<n;i++){
            if(amount[i]>1000){
                res.push_back(name[i]+","+to_string(time[i])+","+to_string(amount[i])+","+city[i]);
            }
            else{
                for(int j=0;j<n;j++){
                    if(i!=j && name[i]==name[j] && city[i]!=city[j] && abs(time[i]-time[j])<=60){
                        res.push_back(name[i]+","+to_string(time[i])+","+to_string(amount[i])+","+city[i]);
                        break;
                    }
                }
            }
        }
        return res;
    }
};