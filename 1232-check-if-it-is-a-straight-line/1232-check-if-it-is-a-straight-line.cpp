class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        for(int i=1;i<n-1;i++){
            int x2=coordinates[i][0];
            int x1=coordinates[i-1][0];
            int y2=coordinates[i][1];
            int y1=coordinates[i-1][1];
            int x3=coordinates[i+1][0];
            int y3=coordinates[i+1][1];

            
                if((y2-y1)*(x3-x2)!=(y3-y2)*(x2-x1)){
                    return false;
                }
            
        }
            return true;

        
        
    }
};