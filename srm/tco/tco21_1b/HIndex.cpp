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

class HIndex {
	public:
	int cheat(vector <int> realCitations, int budget, int citationPrice) {
		int num=budget/citationPrice;
		int ma=0;
		sort(ALL(realCitations));
		reverse(ALL(realCitations));
		int i,j;
		for(i=1;i<=realCitations.size();i++) {
			int need=0;
			FOR(j,i) if(realCitations[j]<i) need+=i-realCitations[j];
			if(need<=num) ma=max(ma,i);
		}
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {25, 3, 5, 3, 8, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 447; int Arg2 = 1000; int Arg3 = 3; verify_case(0, Arg3, cheat(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {25, 3, 5, 3, 8, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1447; int Arg2 = 1000; int Arg3 = 4; verify_case(1, Arg3, cheat(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 140000; int Arg2 = 10000; int Arg3 = 4; verify_case(2, Arg3, cheat(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999999; int Arg2 = 1000000000; int Arg3 = 0; verify_case(3, Arg3, cheat(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HIndex ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

