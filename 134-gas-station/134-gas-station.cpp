class Solution {
  void show_vector(vector<int> vect)
  {
    for (auto &it: vect)
    {
      cout << it << " ";
    }
    cout << endl;
  }

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       
      int n = gas.size();
      vector<int> starting(n,0);
      int curr_gas = 0;
      
      for (int i = 0; i < n; i++)
      {
        curr_gas += gas[i];
        curr_gas -= cost[i];
        
        if (curr_gas >= 0)
        {
          if (i)
            starting[i] = starting[i-1];
          else
            starting[i] = 0;
        }
        else
        {
          if (i)
            starting[i] = max(starting[i-1],abs(curr_gas));
          else 
            starting[i] = abs(curr_gas);
        }
      }
      
      vector<int> ending(n,0);
      vector<int> fuel_left(n,0);
      curr_gas = 0;
      
      for (int i = n-1; i >= 0; i--)
      {
        curr_gas += gas[i];
        curr_gas -= cost[i];
        
        fuel_left[i] = curr_gas;
        
        int temp = gas[i] - cost[i];
        
        if (temp >= 0)
        {
          if (i == n-1)
            ending[i] = 0;
          else
            ending[i] = max(0,ending[i+1] - temp);
        }
        else
        {
          if (i == n-1)
            ending[i] = abs(temp);
          else
            ending[i] = abs(temp) + ending[i+1];
        }
      }
      
      show_vector(starting);
      show_vector(ending);
      show_vector(fuel_left);
      
      for (int i = 0; i < n; i++)
      {
        if (i == 0)
        {
          if (ending[i] == 0)
            return i;
        }
        else
        {
          if (ending[i] == 0 && fuel_left[i] >= starting[i-1])
            return i;
        } 
      }
      return -1;
    }
};