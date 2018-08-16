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

string NONE="NONE";
string AL="ALL";
string SOME="SOME";

class MinDegreeSubgraph {
	public:
	string exists(int n, long long m, int k) {
		
		ll N=n,M=m,K=k;
		if(K==0) return AL;
		// can create
		if(N<K+1) return NONE;
		if(M<K*(K+1)/2) return NONE;
		
		ll t=K*(K-1)/2;
		t+=(K-1)*(N-K);
		if(M<=t) return SOME;
		return AL;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 3LL; int Arg2 = 2; string Arg3 = "ALL"; verify_case(0, Arg3, exists(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; long long Arg1 = 3LL; int Arg2 = 2; string Arg3 = "SOME"; verify_case(1, Arg3, exists(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; long long Arg1 = 10LL; int Arg2 = 3; string Arg3 = "ALL"; verify_case(2, Arg3, exists(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; long long Arg1 = 15LL; int Arg2 = 4; string Arg3 = "ALL"; verify_case(3, Arg3, exists(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 17; long long Arg1 = 53LL; int Arg2 = 11; string Arg3 = "NONE"; verify_case(4, Arg3, exists(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MinDegreeSubgraph ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

