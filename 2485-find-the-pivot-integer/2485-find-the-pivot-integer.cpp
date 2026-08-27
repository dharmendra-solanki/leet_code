class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return n;
        int left = 1 , right = n;
        int leftSum = 1 , rightSum = n;
        while(left < right){
            if(leftSum < rightSum) {
                left++;
                leftSum += left;
            }
            else{
                right--;
                rightSum += right;
            }
        }
        return (leftSum == rightSum) ? left : -1;
    }
};