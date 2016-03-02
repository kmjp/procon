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

ll A[101010];
vector<int> E[101010];
ll pat[101010];
ll tot[101010];

ll ret;
ll mo=1000000007;

class SubtreesCounting {
	public:
	void dfs(int cur,int pre) {
		pat[cur]=tot[cur]=1;
		FORR(r,E[cur]) if(r!=pre) {
			dfs(r,cur);
			(tot[cur] = tot[cur]*(pat[r]+1)+pat[cur]*tot[r])%=mo;
			(pat[cur]*=(1+pat[r]))%=mo;
		}
		ret+=tot[cur];
	}
	
	int sumOfSizes(int n, int a0, int b, int c, int m) {
		int i,j;
		A[0]=a0;
		for(i=1;i<=n-2;i++) A[i]=(b*A[i-1]+c)%m;
		
		FOR(i,n) E[i].clear();
		for(i=1;i<n;i++) {
			j=A[i-1]%i;
			E[i].push_back(j);
			E[j].push_back(i);
		}
		ret=0;
		dfs(0,-1);
		return ret%=mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 10; verify_case(0, Arg5, sumOfSizes(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; int Arg3 = 3; int Arg4 = 100; int Arg5 = 52; verify_case(1, Arg5, sumOfSizes(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; verify_case(2, Arg5, sumOfSizes(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 6; int Arg3 = 7; int Arg4 = 8; int Arg5 = 4; verify_case(3, Arg5, sumOfSizes(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 123; int Arg2 = 46645; int Arg3 = 4564579; int Arg4 = 1000000000; int Arg5 = 769840633; verify_case(4, Arg5, sumOfSizes(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SubtreesCounting ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
