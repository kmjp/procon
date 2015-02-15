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

class NumberGameAgain {
	public:
	long long solve(int k, vector<long long> table) {
		int N=table.size();
		int ng[30]={},msb[30]={},i,j;
		
		sort(table.begin(),table.end());
		FOR(i,N) while(1LL<<(1+msb[i])<=table[i]) msb[i]++;
		FOR(i,N) for(j=i+1;j<N;j++) if((table[j]>>(msb[j]-msb[i]))==table[i]) ng[j]++;
		
		ll ret=(1LL<<k)-2;
		FOR(i,N) if(ng[i]==0) ret -= (1LL<<(k-msb[i]))-1;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; ll Arr1[] = {2,4,6}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; ll Arr1[] = {2,3}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; ll Arr1[] = {}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 30LL; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 40; ll Arr1[] = {2,4,8,16,32141531,2324577,1099511627775LL,2222222222LL,33333333333LL,4444444444LL,2135}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 549755748288LL; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 40; ll Arr1[] = {}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1099511627774LL; verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

	
};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NumberGameAgain ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
