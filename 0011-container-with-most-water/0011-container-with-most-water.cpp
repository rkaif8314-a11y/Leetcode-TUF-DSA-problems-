class Solution {
public:
    int maxArea(vector<int>& height) {
        int Maxans = 0;
        int lp = 0, rp = height.size() - 1;
        while(lp<rp){
            int wd = rp -lp;

            int ht  = min(height[lp],height[rp]);
            int currans= wd*ht;
             Maxans = max(Maxans,currans);
            
            height[lp]<height[rp] ? lp++ : rp--;
        }
        return Maxans;

        
    }
};