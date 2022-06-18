// 54. Spiral Matrix

// Given an m x n matrix, return all elements of the matrix in spiral order.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int row=matrix.size(), col=matrix[0].size();
        int c=row*col;
        int rs=0,re=row-1,cs=0,ce=col-1;
        
        while(c>0){
            for(int i=cs; i<=ce; i++){
                output.push_back(matrix[rs][i]);
                c--;
            }
            if(c<=0)
                break;
            rs++;
            for(int i=rs; i<=re; i++){
                output.push_back(matrix[i][ce]);
                c--;
            }
            if(c<=0)
                break;
            ce--;
            for(int i=ce; i>=cs; i--){
                output.push_back(matrix[re][i]);
                c--;
            }
            if(c<=0)
                break;
            re--;
            for(int i=re; i>=rs; i--){
                output.push_back(matrix[i][cs]);
                c--;
            }
            cs++;
        }
        return output;
    }
};