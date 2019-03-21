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

ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class WrongBase {
	public:
	int modlog(int g,int a) {  // return g^x=a mod a
		map<int,int> M;
		ll cur=1;
		int sq=sqrt(mo);
		int i;
		FOR(i,sq) {
			M[cur]=i;
			cur=cur*g%mo;
		}
		
		ll step=cur;
		cur=1;
		ll num=0;
		while(1) {
			ll x=a*modpow(cur)%mo;
			if(M.count(x)) return num+M[x];
			cur=cur*step%mo;
			num+=sq;
		}
	}
	
	int getSum(int g, int h, int a, int d, int n) {
		if(h==0) return 0;
		
		ll x=modlog(g,h);
		ll sum=0;
		int i;
		FOR(i,n) {
			sum+=modpow(a,x);
			a+=d;
		}
		return sum%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 3; int Arg3 = 3; int Arg4 = 5; int Arg5 = 754398841; verify_case(0, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WrongBase ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

