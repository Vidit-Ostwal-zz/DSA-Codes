class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1)
          return 1;
      
      unordered_map<long,long> map;
      vector<long> answer;
      priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> pq;
      
      for (int i = 0; i < primes.size(); i++)
      {
        pq.push(make_pair(primes[i],primes[i]));
        map[primes[i]] = 1;
      }
      
      answer.push_back(1);
      while (answer.size() != n)
      {
        auto it = pq.top();
        pq.pop();
        
        if (answer[answer.size()-1] != it.first)
          answer.push_back(it.first);
        pq.push(make_pair(it.second*answer[map[it.second]],it.second));
        map[it.second]++;
        
        // cout << answer[answer.size()-1] << "  " ;
      }
      
      return answer[answer.size()-1];
    }
};