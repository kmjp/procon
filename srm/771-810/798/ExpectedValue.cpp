#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const ll mo=1000000007;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll memo[1515];
ll kan[1515];

class ExpectedValue {
	public:
	
	ll hoge(int N) {
		if(memo[N]>=0) return memo[N];
		if(N==1) return 0;
		if(N==0) return 0;
		ll ret=0;
		
		int num;
		for(num=2;num<=N;num++) (ret+=comb(N-1,num-1)*fact[num-1]%mo*((num-1)*kan[N-num]%mo+hoge(N-num)))%=mo;
		return memo[N]=ret;
	}
	
	int solve(int N) {
		int i;
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
		
		kan[0]=1;
		for(i=2;i<=N;i++) kan[i]=(kan[i-1]+kan[i-2])*(i-1)%mo;
		
		MINUS(memo);
		return hoge(N)*modpow(kan[N])%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 666666674; verify_case(2, Arg1, solve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ExpectedValue ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

