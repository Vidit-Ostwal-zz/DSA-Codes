class ATM {
  unordered_map<int,long long> u1;
public:
    ATM() {
    }
    
    void deposit(vector<int> bN) {
      u1[20] += bN[0];
      u1[50] += bN[1];
      u1[100] += bN[2];
      u1[200] += bN[3];
      u1[500] += bN[4];
    }
    
    vector<int> withdraw(int amount) {
        vector<int> answer(5,0);
      
      long long re5 = 0,re2 = 0,re1 = 0, re = 0,r = 0;
      if (u1[500] > 0)
        re5 = min(u1[500],(long long)amount/500);
      
      answer[4] = re5;
      amount -= re5*500;
      
      if (u1[200] > 0)
        re2 = min(u1[200],(long long)amount/200);
      
      answer[3] = re2;
      amount -= re2*200;
      
      if (u1[100] > 0)
        re1 = min(u1[100],(long long)amount/100);
      
      answer[2] = re1;
      amount -= re1*100;
      
      if (u1[50] > 0)
        re = min(u1[50],(long long)amount/50);
      
      answer[1] = re;
      amount -= re*50;
      
      if (u1[20] > 0)
        r = min(u1[20],(long long)amount/20);
      
      answer[0] = r;
      amount -= r*20;
      
      if (amount != 0)
        return {-1};
      
      u1[20] -= r;
      u1[50] -= re;
      u1[100] -= re1;
      u1[200] -= re2;
      u1[500] -= re5;
      
      return answer;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */