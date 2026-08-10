class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxm=0;
        int l=0,r=heights.size()-1;
        while(l<r)
        {
            //cout<<l<<" "<<r<<endl;
            int temp=min(heights[l],heights[r])*(r-l);
            maxm=max(temp,maxm);
            if(heights[l]>heights[r])
            r--;
            else 
            l++;
        }
        return maxm;
    }
};
