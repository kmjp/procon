#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int NUM_=1000005;
ll inv[NUM_+1];

vector<int> E[1010101];
int par[1010101];
ll dp[1010101],tot[1010101];
ll mo=1000000007;

class BearAttacks {
	public:
	int root;
	ll ret;
	
	void dfs(int cur,ll sc) {
		(ret += 2*sc*inv[cur+1])%=mo;
		FORR(t,E[cur]) {
			tot[cur]+=mo-dp[t];
			ll sc2=(sc+tot[cur]+mo)%mo*inv[cur+1]%mo;
			dfs(t,sc2);
		}
	}

	int expectedValue(int N, int R0, int A, int B, int M, int LOW, int HIGH) {
		int i;
		
		inv[1]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		FOR(i,N) E[i].clear();
		
		ll R = R0;
		ll BILLION = 1000000000;
		for(i=1;i<=N-1;i++) {
			R = (A * R + B) % M;
			ll MIN = (1LL*(i-1) * LOW)  / BILLION;
			ll MAX = (1LL*(i-1) * HIGH) / BILLION;
			par[i]= MIN + (R % (MAX-MIN+1));
			E[par[i]].push_back(i);
		}
		ZERO(dp);
		ZERO(tot);
		
		ret=0;
		for(i=N-1;i>=0;i--) {
			tot[i]++;
			tot[i]%=mo;
			dp[i]=tot[i]*inv[i+1]%mo;
			if(i) tot[par[i]] += dp[i];
			
			(ret += inv[i+1])%=mo;
		}
		
		dfs(0,0);
		for(i=1;i<=N;i++) ret = ret*i%mo;
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 2; int Arg3 = 3; int Arg4 = 100; int Arg5 = 938593850; int Arg6 = 1000000000; int Arg7 = 21; verify_case(0, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; int Arg7 = 23; verify_case(1, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 303840291; int Arg2 = 848660283; int Arg3 = 395739574; int Arg4 = 950123456; int Arg5 = 0; int Arg6 = 1000000000; int Arg7 = 3856; verify_case(2, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; verify_case(3, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 19; int Arg1 = 384038999; int Arg2 = 938592393; int Arg3 = 692854433; int Arg4 = 1000000000; int Arg5 = 300000000; int Arg6 = 600000000; int Arg7 = 473263988; verify_case(4, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearAttacks ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
