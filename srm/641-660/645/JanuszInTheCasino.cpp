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

map<ll,double> memo[51];

class JanuszInTheCasino {
	public:
	int M,K;
	
	double dodo(ll n,int k) {
		if(n<=0) return 0;
		if(k==0) return 1;
		if(memo[k].count(n)) return memo[k][n];
		double ret=0;
		
		if(n%M==0 || k<K-50) ret=dodo(n-n/M,k-1);
		else {
			ret=dodo(n-n/M,k-1)*(M-n%M)/M + dodo(n-(n/M+1),k-1)*(n%M)/M;
		}
		
		return memo[k][n]=ret;
	}
	
	double findProbability(long long n, int m, int k) {
		int i,j;
		FOR(i,51) memo[i].clear();
		M=m;
		K=k;
		return dodo(n,k);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; int Arg1 = 2; int Arg2 = 2; double Arg3 = 0.75; verify_case(0, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1LL; int Arg1 = 3; int Arg2 = 3; double Arg3 = 0.2962962962962962; verify_case(1, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 4LL; int Arg1 = 3; int Arg2 = 2; double Arg3 = 1.0; verify_case(2, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 5LL; int Arg1 = 4; int Arg2 = 5; double Arg3 = 0.87109375; verify_case(3, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 1000000000000LL; int Arg1 = 2; int Arg2 = 40; double Arg3 = 0.9094947017729282; verify_case(4, Arg3, findProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  JanuszInTheCasino ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
