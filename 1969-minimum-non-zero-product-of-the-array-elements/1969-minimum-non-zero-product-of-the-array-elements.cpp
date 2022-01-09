class Solution {
public:
    long long helper (long long  x,long long n,int m)
    {
        cout << x << "x" << " " << n << "n" << endl;
        if (n == 1)
        {
            return x;
        }
        if (n == 0)
        {
            return 1;
        }
        
        long long temp = helper(x,n/2,m)%m;
        cout << n << endl;
        temp = temp%m;
        if (n%2)
        {
            return (((temp*temp)%m)*(x%m))%m;
        }
        return (temp*temp)%m;
    }
    
    int minNonZeroProduct(int p) {
        int m=1e9+7;
        long long range = (long long)pow(2,p) - 1;
        return (helper(range-1,range/2,m)*(range%m))%m;
    }
};