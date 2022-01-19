class Solution {
public:
  /*Time Complexity = O(2^N) Recursive Tree
    Sapce Comlplexity = O(N) Height of recursion tree*/
    int recursive_solution (int left_weigth, vector<int> wt, int index)
    {
      if (!left_weigth)
        return 1;
        
      /*Base Condiditon*/
        if (index <0)
        return 0;
      
        /*Case when current weight is higher*/
        if (wt[index] > left_weigth)
        return recursive_solution(left_weigth,wt,index-1);
        
        else
        {
            return recursive_solution(left_weigth - wt[index],wt,index)+ recursive_solution(left_weigth,wt,index-1);
        }
    }
    
    /*Complexity Analysis: 
    Time Complexity: O(N*W).
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W).
    The use of 2-D array of size ‘N*W’.*/
    int memozization_solution (int left_weigth, vector<int> wt, int index,vector<vector<int>> &memozise)
    {
      if (!left_weigth)
        return 1;
        /*Base Condiditon*/
        if (index <0)
        return 0;
        
        /*Solution might be already calculated*/
        if (memozise[left_weigth][index] != -1)
        {
            return memozise[left_weigth][index];
        }
        
        /*Case when current weight is higher*/
        if (wt[index] > left_weigth)
        return memozise[left_weigth][index] = memozization_solution(left_weigth,wt,index-1,memozise);
        
        else
        {
            return memozise[left_weigth][index] = memozization_solution(left_weigth - wt[index],wt,index,memozise)+
              memozization_solution(left_weigth,wt,index-1,memozise);
        }
    }
    
    /*Top -Down Appraoch
    Complexity Analysis: 
    Time Complexity: O(N*W).
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W).
    The use of 2-D array of size ‘N*W’.
    Mostly both Memozization solution and top_down_solution will have same complexity.*/
    int top_down_solution (int W, vector<int> wt, int n)
    {
        vector<vector<int>> memozise(n+1,vector<int>(W+1));
       
       for (int a = 0; a <= n; a++)
       {
           for (int b = 0; b <= W;b++)
           {
               if (b == 0)
               memozise[a][b] = 1;
             
               else if (a == 0)
               memozise[a][b] = 0;
             
             
               
               else if (wt[a-1] <=  b)
               memozise[a][b] = memozise[a][b-wt[a-1]] + memozise[a-1][b];
               
               else
               memozise[a][b] = memozise[a-1][b];
           }
       }
       return memozise[n][W];
    }
  
  
    int change(int amount, vector<int>& coins) {
      /*used in memozization
      vector<vector<int>> memozise(amount+1,vector<int>(coins.size()+1,-1));
      */
      return top_down_solution(amount,coins,coins.size());
    }
};