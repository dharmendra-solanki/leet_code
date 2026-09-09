class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> list;
        for (int i = left; i <= right; i++) {
            int num = i;
            int selfDividing = true;
            while (num > 0) {
                int digit = num % 10;
                if ( digit == 0 || i % digit != 0) {
                    selfDividing = false;
                    break;
                }
                num = num / 10;
            }
            if(selfDividing){
                list.push_back(i);
            }
        }
        return list;
    }
};