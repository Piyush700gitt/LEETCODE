class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>>mpp;
        for(auto &x:reservedSeats){
            mpp[x[0]].push_back(x[1]);
        }
        int ans=(n-mpp.size())*2;
        for(auto &it:mpp){
            auto row=it.first;
            auto seat=it.second;
            bool av1=true;
            bool av2=true;
            bool av3=true;
            for(auto &x:seat){
                if(x>=2 && x<=5){
                    av1=false;
                }
                if(x>=4 && x<=7){
                    av2=false;
                }
                if(x>=6 && x<=9){
                    av3=false;
                
                }}
                if(av1 && av3){
                    ans+=2;
                }
                else if(av1 || av2|| av3){
                    ans+=1;
                
                }
            }

        
        return ans;

    }
};