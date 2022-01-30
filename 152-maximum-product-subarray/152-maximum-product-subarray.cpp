class Solution {
public:
    int maxProduct(vector<int>& arr) {
        long long res = INT_MIN;
	    
	    long long l = 1;
	    long long r = 1;
	    
	    for (int i = 0; i < arr.size(); i++)
	    {
	        l = l * arr[i];
	        r = r * arr[arr.size()-1-i];
	        
	        res = max(res,max(l,r));
	        
	        if (l == 0) l = 1;
	        if (r == 0) r = 1;
	    }
	    return res;
    }
};