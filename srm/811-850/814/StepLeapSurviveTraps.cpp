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

ll T[505050];
ll dp[505050];
class StepLeapSurviveTraps {
	public:
	long long minDamage(int N, int J, int seed, int M) {
		T[0] = 0;
		ll state = seed;
		int i;
		deque<int> D;
		D.push_back(0);
		dp[0]=0;
		
		for(i=1;i<=N;i++) {
			state = (state * 1103515245 + 12345) % (1LL<<31);
			T[i]=1+state%M;
			while(D.front()<i-J) D.pop_front();
			dp[i]=T[i]+dp[D.front()];
			while(D.size()&&dp[D.back()]>=dp[i]) D.pop_back();
			D.push_back(i);
		}
		return dp[N];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 3; int Arg2 = 47; int Arg3 = 10; long long Arg4 = 17LL; verify_case(0, Arg4, minDamage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 1; int Arg2 = 47; int Arg3 = 123456789; long long Arg4 = 5835166389LL; verify_case(1, Arg4, minDamage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 12345; int Arg3 = 54321; long long Arg4 = 46038LL; verify_case(2, Arg4, minDamage(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  StepLeapSurviveTraps ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

