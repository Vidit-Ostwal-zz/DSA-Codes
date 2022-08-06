class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
      long long time = 1;
      unordered_map<int,long long> map1;
      
      for (int i = 0; i < tasks.size(); i++)
      {
        time = max(time,map1[tasks[i]]);
        map1[tasks[i]] = time + space + 1;
        time++;
      }
      return time-1;
    }
};