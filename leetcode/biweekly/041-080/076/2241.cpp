#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int D[5]={20,50,100,200,500};
ll V[5];
class ATM {
public:
    ATM() {
        ZERO(V);
        
    }
    
    void deposit(vector<int> banknotesCount) {
        int i;
        FOR(i,5) V[i]+=banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
		int i;
		vector<int> A;
		for(i=4;i>=0;i--) {
			ll m=min((ll)amount/D[i],V[i]);
			amount -= m*D[i];
			A.push_back(m);
		}
        if(amount) return {-1};
        reverse(ALL(A));
        FOR(i,5) V[i]-=A[i];
        return A;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
 