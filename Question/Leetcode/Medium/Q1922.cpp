/*

[2,3,5,7] odd 4
[0,2,4,6,8] even 5
*/

/*
Helper Function basically a replica of pow function, with x as base to the power n;

*/
class Solution {
public:
    long long modified_power(int x,long long n,int m)
    {
        if (n == 1)
        {
            return x;
        }
        if (n == 0)
        {
            return 1;
        }
        
        long long temp = modified_power(x,n/2,m)%m;
        
        if (n%2)
        {
            return (temp*temp*x)%m;
        }
        return (temp*temp)%m;
    }
    
    int countGoodNumbers(long long n) {
        int m=1e9+7;
        if (n == 1)
            return 5;
        long long answer = ((modified_power(4,n/2,m)) * (modified_power(5,(n+1)/2,m)) %m);
        return answer;
    }
};
