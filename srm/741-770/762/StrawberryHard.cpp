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

ll mo=1000000007;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll from[14001];
__int128 to[14001];

class StrawberryHard {
	public:
	int competitive(int n, int k, int Arange, int Brange, int seed) {
		vector<ll> A,B;
		ll AS=0,BS=0;
		ll state=seed;
		int i,j,x;
		FOR(i,2*k+1) {
			state = (1103515245 * state + 12345);
			state %= 1LL<<31;
			A.push_back(state%Arange);
			AS+=A.back();
			state = (1103515245 * state + 12345);
			state %= 1LL<<31;
			B.push_back(state%Brange);
			BS+=B.back();
		}
		AS=modpow(AS%mo);
		BS=modpow(BS%mo);
		FORR(a,A) a=a*AS%mo;
		FORR(b,B) b=b*BS%mo;
		
		ZERO(from);
		from[7000]=1;
		FOR(x,n) {
			ZERO(to);
			if(x%2==0) {
				for(i=-k;i<=k;i++) {
					for(j=0;j<=2*k;j++) if(i+j<=k) (to[(i+j)+7000]+=from[i+7000]*A[j]);
				}
			}
			else {
				for(i=-k;i<=k;i++) {
					for(j=0;j<=2*k;j++) if(i-j>=-k) (to[(i-j)+7000]+=from[i+7000]*B[j]);
				}
			}
			for(i=-k;i<=k;i++) from[i+7000]=to[i+7000]%mo;
		}
		ll ret=0;
		for(i=-k;i<=k;i++) ret+=from[i+7000];
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 2; int Arg3 = 7; int Arg4 = 0; int Arg5 = 571428576; verify_case(0, Arg5, competitive(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 3; int Arg3 = 3; int Arg4 = 740562; int Arg5 = 1; verify_case(1, Arg5, competitive(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 3; int Arg2 = 3; int Arg3 = 3; int Arg4 = 740562; int Arg5 = 753086426; verify_case(2, Arg5, competitive(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 5; int Arg2 = 11; int Arg3 = 13; int Arg4 = 47; int Arg5 = 931930680; verify_case(3, Arg5, competitive(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  StrawberryHard ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

