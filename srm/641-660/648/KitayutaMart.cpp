#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class KitayutaMart {
	public:
	ll NN,KK;
	ll sum(ll v) {
		ll tot=0;
		int i;
		FOR(i,v) {
			ll t=min(KK,(1LL<<(i+1))-1);
			tot+=t;
			if(tot>=1LL<<40) return tot;
			if(t==KK) return tot+(v-i-1)*KK;
		}
		return tot;
	}
	
	int lastPrice(int N, int K) {
		int i,x;
		NN=N,KK=K;
		if(N==1) return 1;
		ll L=0;
		for(i=29;i>=0;i--) if(sum(L+(1<<i))<N) L+=1<<i;
		N-=sum(L);
		
		x=0;
		while(1<<(x+1) <= K) x++;
		x=min(x,(int)L);
		if(L<29) K=min(K,(1<<(L+1))-1);
		for(int y=1<<x;;y++) {
			int r=y;
			while(r%2==0) r/=2;
			while(r<=K) {
				if(--N<=0) return modpow(2,L-x)*y%mo;
				r*=2;
			}
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, lastPrice(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; verify_case(1, Arg2, lastPrice(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 4; verify_case(2, Arg2, lastPrice(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 1; int Arg2 = 570312504; verify_case(3, Arg2, lastPrice(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 987654321; int Arg1 = 876543210; int Arg2 = 493827168; verify_case(4, Arg2, lastPrice(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 
/*
int main(int argc,char** argv) {
  KitayutaMart ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
*/
