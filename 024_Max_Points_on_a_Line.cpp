// 149. Max Points on a Line

// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
// return the maximum number of points that lie on the same straight line.

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2)
            return points.size();
        
        int maxpt=2;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int currpt=2;
                for(int k=0;k<points.size();k++){
                    if(k!=i&&k!=j){
                        if((points[j][1]-points[i][1])*(points[i][0]-points[k][0])==(points[i][1]-points[k][1])*(points[j][0]-points[i][0])){
                            currpt++;
                        }
                    }
                }
                maxpt=max(maxpt,currpt);
            }
            
        }
        return maxpt;
    }
};