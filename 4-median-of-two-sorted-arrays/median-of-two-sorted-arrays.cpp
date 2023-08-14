class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        int l=0,r=0;
        int val1=-1,val2=-1;
        int temp=0;
        while(temp<=(len/2)){
            if(l<nums1.size() && r<nums2.size()){
                if(nums1[l]<nums2[r]){
                    val2=val1;
                    val1=nums1[l];
                    l++;
                }
                else{
                    val2=val1;
                    val1=nums2[r];
                    r++;
                }
            }
            else{
                if(l<nums1.size()){
                    val2=val1;
                    val1=nums1[l];
                    l++;
                }
                else{
                    val2=val1;
                    val1=nums2[r];
                    r++;
                }
            }
            temp++;
        }
        if(len%2!=0){
            return (double)val1;
        }
        double a=val1+val2;
        a=a/2.0;
        return a;
    }
};