// 166. Fraction to Recurring Decimal
class Solution {
public:
    string fractionToDecimal(int n, int d) {
        long long numerator=n,denominator=d;
        if(numerator==0) return "0";
        string s = "";
        if(numerator<0 && denominator<0){
            numerator = -numerator;
            denominator = -denominator;
        }
        else if(numerator<0 && denominator>0){
            numerator = -numerator;
            s+= "-";
        }
        else if(denominator<0 && numerator>0){
            denominator = -denominator;
            s+= "-";
        }
        long long integer_part = numerator/denominator;
        numerator = numerator%denominator;
        
        s += to_string(integer_part);
        if(numerator==0){
            return s;
        }
        s += ".";
        numerator *=10;
        while(numerator<denominator){
            numerator *=10;
            s += '0';
        }
        unordered_map<long long,long long> m;
        bool recur = false;char rec_d;
        while(numerator!=0){
            int dec = numerator/denominator;
            if(m[numerator]==0){
                m[numerator]++;s += to_string(dec);
            }
            else{
                recur = true;
                rec_d = dec+'0';
                break;
            }
            numerator = numerator%denominator;
            numerator *= 10;
        }

        if(recur){
            long long n = s.length(),i;
            bool pon=false;
            for(i=0;i<n;i++){
                if(s[i]=='.') pon=true;
                if(s[i]==rec_d && pon) break;
            }
            s = s.substr(0,i)+"("+s.substr(i,n-i)+")";
        }
        return s;
    }
};