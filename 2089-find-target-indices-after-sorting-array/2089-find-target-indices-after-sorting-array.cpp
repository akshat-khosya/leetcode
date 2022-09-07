class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(end>=start){
            int mid=(end-start)/2 +start;
            
            if(nums[mid]==target){
                
                v.push_back(mid);
                if(mid+1<n && nums[mid+1]==target){
                    for(int j=mid+1;j<n && nums[j]==target;j++){
                        v.push_back(j);
                    }
                }
                if(mid-1>=0 && nums[mid-1]==target){
                    for(int j=mid-1;j>=0 && nums[j]==target;j--){
                        v.push_back(j);
                    }
                }
                
                break ;
            }else if(target>nums[mid]){
               
                start=mid+1;
                
            }else{
                end=mid-1;
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};