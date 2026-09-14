class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size=nums.size();
        vector<int>pos;
        vector<int>neg;
        
        for (int i=0 ;i<size;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]*nums[i]); // Square negative numbers immediately
            }
            else{
                pos.push_back(nums[i]*nums[i]); // Square positive numbers immediately
            }
        }
        
        // Reverse neg because squared negative numbers are in descending order
        reverse(neg.begin(), neg.end());

        if(pos.size()==0){
            return neg; // Return entire squared & reversed vector directly
        }
        if(neg.size()==0){
            return pos; // Return entire squared vector directly
        }
        
        int i=0,j=0,id=0;
        int n=neg.size();
        int p=pos.size();
        vector<int> result(size);
        
        while(i<n and j<p){
            if(neg[i]<pos[j]){
                result[id]=neg[i];
                id++;
                i++;
            }
            else{
                result[id]=pos[j];
                id++;
                j++;
            }
        }
        
        // Use result[id] assignment instead of push_back to prevent extra zeros
        while(i<n){
            result[id]=neg[i];
            id++;
            i++;
        }
        while(j<p){
            result[id]=pos[j];
            id++;
            j++;
        }
        
        return result;
    }
};