class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(!(p & 1) && !(q & 1)) p /= 2, q /= 2;
        /* This is because the effect of 4 and 2 will be same as 2 and 1
         hence removing all the powers of two untill atleast one get get rid of power of 2 */
        
        if(!(p & 1) && (q & 1)) return 2;
        if((p & 1) && (q & 1)) return 1;
        return 0;
    }
};