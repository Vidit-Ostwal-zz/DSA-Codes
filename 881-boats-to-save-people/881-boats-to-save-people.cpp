class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
      int st = 0;
      int ed = people.size() -1;
      int curr  = 0;
      int count=  0;
      while (st <= ed)
      {
        curr = people[ed];
        ed--;
        if (st <= ed && curr + people[st] <= limit)
        {
          st++;
        }
        curr = 0;
        count++;
      }
      
      return count;
    }
};