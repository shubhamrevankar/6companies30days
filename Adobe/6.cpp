//688. Knight Probability in Chessboard
class Solution {
public:
    // long long success=0;
    // void move(int n,int k,int row,int column){
    //     if(k==0){
    //         success++;
    //         return;
    //     }
        // if(row-2>=0){
        //     if(column-1>=0){
        //         move(n,k-1,row-2,column-1);
        //     }
        //     if(column+1<n){
        //         move(n,k-1,row-2,column+1);
        //     }
        // }
        // if(row-1>=0){
        //     if(column-2>=0){
        //         move(n,k-1,row-1,column-2);
        //     }
        //     if(column+2<n){
        //         move(n,k-1,row-1,column+2);
        //     }
        // }
        // if(row+1<n){
        //     if(column-2>=0){
        //         move(n,k-1,row+1,column-2);
        //     }
        //     if(column+2<n){
        //         move(n,k-1,row+1,column+2);
        //     }
        // }
        // if(row+2<n){
        //     if(column-1>=0){
        //         move(n,k-1,row+2,column-1);
        //     }
        //     if(column+1<n){
        //         move(n,k-1,row+2,column+1);
        //     }
        // }
    // }
    double fun (vector<vector<double>> &v,int n, int row, int column){
        double success=0;
        if(row-2>=0){
            if(column-1>=0) success+=v[row-2][column-1]*(0.125);
            if(column+1<n) success+=v[row-2][column+1]*(0.125);
        }
        if(row-1>=0){
            if(column-2>=0) success+=v[row-1][column-2]*(0.125);
            if(column+2<n) success+=v[row-1][column+2]*(0.125);
        }
        if(row+1<n){
            if(column-2>=0) success+=v[row+1][column-2]*(0.125);
            if(column+2<n) success+=v[row+1][column+2]*(0.125);
        }
        if(row+2<n){
            if(column-1>=0) success+=v[row+2][column-1]*(0.125);
            if(column+1<n) success+=v[row+2][column+1]*(0.125);
        }
        return success;
    }
    double knightProbability(int n, int k, int row, int column) {
        if(k==0) return 1;
        vector<vector<double>> temp(n,vector<double>(n,1));
        vector<vector<double>> v(n,vector<double>(n,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v[i][j] = fun(temp,n,i,j);
            }
        }
        k--;
        if(k==0) return v[row][column];
        
        while(k){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp[i][j] = fun(v,n,i,j);
                }
            }

            k--;
            if(k==0) return temp[row][column];

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    v[i][j] = fun(temp,n,i,j);
                }
            }
            k--;
        }
        return v[row][column];
    }
};