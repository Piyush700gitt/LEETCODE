class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string>ans(numRows);
        int row=0;
        bool down=true;
        for(auto ch:s){
            ans[row]+=ch;
            if(row==0){
                down=true;
            }
            if(row==numRows-1){
                down=false;
            }
            if(down)row++;
            if(!down)row--;
        }
        string final="";
        for(auto x:ans){
            final+=x;
        }
        return final;
        
    }
};