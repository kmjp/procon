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

class ChristmasCrackers {
	public:
	vector <int> crack(int N, int K) {
		vector<int> V,R;
		int i,j;
		FOR(i,N) FOR(j,K) V.push_back(i);
		if(V.size()%2) V.push_back(N-1);
		
		FOR(i,V.size()/2) R.push_back(V[i]),R.push_back(V[i+V.size()/2]);
		return R;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {0, 1, 0, 1, 0, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, crack(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arr2[] = {0, 3, 1, 2, 1, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, crack(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {0, 1, 0, 1, 0, 2, 0, 2, 1, 2, 2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, crack(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChristmasCrackers ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

