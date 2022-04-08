class Bank {
  vector<long long> temp;
public:
    Bank(vector<long long>& balance) {
        temp = vector<long long>(balance.begin(),balance.end());
    }
    
    bool transfer(int account1, int account2, long long money) {
      account1--;
      account2--;
        if (account1 < 0 || account2  < 0 || account1 >= temp.size() || account2 >= temp.size())
          return false;
      
      if (temp[account1] < money)
        return false;
      
      temp[account1] -= money;
      temp[account2] += money;
      return true;
    }
    
    bool deposit(int account, long long money) {
      account--;
        if (account < 0 || account >= temp.size())
          return false;
      
      temp[account] += money;
      return true;
      
    }
    
    bool withdraw(int account, long long money) {
      account--;
      if (account < 0 || account >= temp.size())
          return false;
      
      if (temp[account] < money)
        return false;
      
      temp[account] -= money;
      return true;
        
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */