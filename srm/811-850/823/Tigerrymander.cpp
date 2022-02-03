#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

vector<ll> C;
map<ll,int> M;
ll dp[100000];
ll T,O;
class Tigerrymander {
	public:
	ll dfs(ll n) {
		if(dp[M[n]]>=0) return dp[M[n]];
		
		ll mi=(n*O+T+O)/(T+O);
		int i;
		FOR(i,C.size()) if(n%C[i]==0) {
			if(n==C[i]) break;
			ll w=dfs(C[i]);
			ll t=w*((n/C[i]*O+T+O)/(T+O));
			mi=min(mi,t);
			
		}
		
		return dp[M[n]]=mi;
		
	}
	
	long long minTigers(long long N, int TV, int OV) {
		C.clear();
		for(ll i=1;i*i<=N;i++) if(N%i==0) {
			C.push_back(i);
			if(i*i!=N) C.push_back(N/i);
		}
		sort(ALL(C));
		M.clear();
		int i;
		FOR(i,C.size()) M[C[i]]=i;
		T=TV,O=OV;
		
		MINUS(dp);
		return dfs(N);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; int Arg1 = 1; int Arg2 = 1; long long Arg3 = 3LL; verify_case(0, Arg3, minTigers(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 13LL; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 5LL; verify_case(1, Arg3, minTigers(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 12LL; int Arg1 = 7; int Arg2 = 7; long long Arg3 = 6LL; verify_case(2, Arg3, minTigers(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 28LL; int Arg1 = 3; int Arg2 = 1; long long Arg3 = 2LL; verify_case(3, Arg3, minTigers(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 21LL; int Arg1 = 1; int Arg2 = 10; long long Arg3 = 20LL; verify_case(4, Arg3, minTigers(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Tigerrymander ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

