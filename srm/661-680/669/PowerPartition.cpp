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

ll F[61][1000][61];
ll G[61][1000][61];
ll mo=1000000007;
int D[61];

class PowerPartition {
	public:
	int count(int M, long long X) {
		int dig=0;
		ZERO(F);
		ZERO(G);
		ZERO(D);
		
		while(X) D[dig++] = X % M, X /= M;
		
		int n,b,a,i;
		FOR(b,M) FOR(a,dig) F[0][b][a]=G[0][b][a]=1;
		for(n=1;n<dig;n++) for(b=1;b<=M;b++) FOR(a,dig) {
			ll& ne = F[n][b][a];
			if(b==1) FOR(i,min(n-1,a)+1) ne += F[n-1-i][1][a-i]*F[n-1][M-1][i] % mo;
			else FOR(i,min(n,a)+1) ne += F[n-i][1][a-i]*F[n][b-1][i] % mo;
			ne %= mo;
		}
		
		for(n=1;n<dig;n++) FOR(b,D[n]+1) FOR(a,dig) {
			ll& ne = G[n][b][a];
			if(b==0) ne = G[n-1][D[n-1]][a];
			else FOR(i,min(n,a)+1) ne += F[n-i][1][a-i]*G[n][b-1][i] % mo;
			ne %= mo;
		}
		
		return G[dig-1][D[dig-1]][dig-1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 4LL; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 17; long long Arg1 = 1LL; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000; long long Arg1 = 1000000007LL; int Arg2 = 500501002; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 841; long long Arg1 = 765346961765346961LL; int Arg2 = 89045497; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PowerPartition ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
