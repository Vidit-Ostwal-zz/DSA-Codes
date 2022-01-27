class Solution {
public:
    vector<int> sortedSquares(vector<int>&A){
        vector<int> negative;
    int i = 0;
    while (i < A.size() && A[i] < 0 )
    {
        negative.insert(negative.begin(),-1*A[i]);
        i++;
    }
    /*i points to the first positive number*/
    int j = 0; 
    vector<int> final_vector;
      
    while (i < A.size() && j < negative.size())
    {
        if (A[i] < negative[j])
        {
            final_vector.push_back(A[i]*A[i]);
            i++;
        }
        else 
        {
            final_vector.push_back(negative[j]*negative[j]);
            j++;
        }
    }

    while (j < negative.size())
    {
         final_vector.push_back(negative[j]*negative[j]);
        j++;
    }
    
    while (i < A.size())
    {
        final_vector.push_back(A[i]*A[i]);
        i++;
    }
    return final_vector;
    }
};