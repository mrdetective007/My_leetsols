class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            auto it=lower_bound(nums2.rbegin(),nums2.rend(),nums1[i]);
            int index=it-nums2.rbegin();
            int ind=nums2.size()-index-1;
            maxi=max(maxi,ind-i);
        }
        return maxi;
    }
};