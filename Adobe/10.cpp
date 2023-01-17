// 1975. Maximum Matrix Sum
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int neg=0;
        bool is_zero=false;
        long long abssum=0;
        int most_neg=-INT_MAX;
        int least = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){neg++;most_neg = max(most_neg,matrix[i][j]);}
                else if(matrix[i][j]==0){is_zero=true;}
                else least = min(least,matrix[i][j]);
                abssum += abs(matrix[i][j]);
            }
        }
        if(is_zero || neg%2==0) return abssum;
        if(abs(least)<abs(most_neg)){
            abssum -= 2*least;
        }
        else
            abssum += 2*most_neg;
        return abssum;
    }
};