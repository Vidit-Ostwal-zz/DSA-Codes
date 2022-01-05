class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_number;
	    ugly_number.push_back(1);
	    
	    int index2 = 0;
	    int index3 = 0;
	    int index5 = 0;
	    
	    int next2;
	    int next3;
	    int next5;
	    int minimum_multiple = 0;
	    for (int i =0 ;i < n-1 ; i++)
	    {
	    next2 = ugly_number[index2]*2;
	    next3 = ugly_number[index3]*3;
	    next5 = ugly_number[index5]*5;
	    
	    if (next2 < next3)
	    {
	        if (next5 < next2)
	        {
	            minimum_multiple = next5;
	        }
	        else
	        {
	            minimum_multiple = next2;
	        }
	    }
	    else
	    {
	        if (next5 < next3)
	        {
	            minimum_multiple = next5;
	        }
	        else
	        {
	            minimum_multiple = next3;
	        }
	    }
	    cout << minimum_multiple << endl;
	    ugly_number.push_back(minimum_multiple);
	    
	    if (minimum_multiple == next2)
	    {
	        index2++;
	    }
	    if (minimum_multiple == next3)
	    {
	        index3++;
	    }
	    if (minimum_multiple == next5)
	    {
	        index5++;
	    }
	    
	    }
	    return ugly_number[n-1];
    }
};