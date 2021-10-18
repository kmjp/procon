typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


class Bank {
public:
	vector<ll> B;
    Bank(vector<long long>& balance) {
		B=balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
		account1--;
		if(account1<0||account1>=B.size()) return 0;
		account2--;
		if(account2<0||account2>=B.size()) return 0;
		if(B[account1]<money) return 0;
		B[account1]-=money;
		B[account2]+=money;
        return 1;
    }
    
    bool deposit(int account, long long money) {
		account--;
		if(account<0||account>=B.size()) return 0;
		B[account]+=money;
		return 1;
        
    }
    
    bool withdraw(int account, long long money) {
		account--;
		if(account<0||account>=B.size()) return 0;
		if(B[account]<money) return 0;
		B[account]-=money;
		return 1;
        
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
 