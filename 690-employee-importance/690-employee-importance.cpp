/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> u1;
      
      for (int i = 0; i < employees.size(); i++)
        u1[employees[i] -> id] = employees[i];
      
      queue<Employee*> q;
      q.push(u1[id]);
      
      int sum = 0;
      while (!q.empty())
      {
        Employee* root = q.front();
        q.pop();
        
        sum += root -> importance;
        
        for (int i = 0 ; i < root -> subordinates.size(); i++)
          q.push(u1[root -> subordinates[i]]);
      }
      
      return sum;
    }
};