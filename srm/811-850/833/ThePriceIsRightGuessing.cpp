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

class ThePriceIsRightGuessing {
	public:
	long long guess(vector<long long> G, long long MAX) {
		G.push_back(0);
		G.push_back(MAX+1);
		sort(ALL(G));
		ll ma=0;
		int i;
		FOR(i,G.size()-1) ma=max(ma,G[i+1]-G[i]);
		FOR(i,G.size()-1) if(G[i+1]-G[i]==ma) return G[i]+1;
		return 0;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {1, 3, 5, 7, 9}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 10LL; long long Arg2 = 2LL; verify_case(0, Arg2, guess(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 47LL; long long Arg2 = 1LL; verify_case(1, Arg2, guess(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {100000000000, 300000000000, 500000000000, 700000000000, 900000000000}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1000000000000LL; long long Arg2 = 100000000001LL; verify_case(2, Arg2, guess(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {1, 9, 5, 2, 4, 10, 7, 3, 8}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 10LL; long long Arg2 = 6LL; verify_case(3, Arg2, guess(Arg0, Arg1)); }
	void test_case_4() { long Arr0[] = {1, 10}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 20LL; long long Arg2 = 11LL; verify_case(4, Arg2, guess(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ThePriceIsRightGuessing ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

