class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()<=1)
            return;
        int leftIx=0, rightIx=nums.size()-1;
        for(int i=0;i<=rightIx;){
            if(nums[i]==2){
                swap(nums[i],nums[rightIx]);
                rightIx--;
            }
            else if(nums[i]==1){
                i++;
            }
            else{
                swap(nums[leftIx++],nums[i++]);
            }
        }
    }
};