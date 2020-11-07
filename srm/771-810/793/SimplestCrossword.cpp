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

class SimplestCrossword {
	public:
	vector <string> construct(string H, string V) {
		int x,y,x2,y2;
		FOR(x,H.size()) FOR(y,V.size()) {
			if(H[x]==V[y]) {
				vector<string> R;
				FOR(y2,V.size()) R.push_back(string(H.size(),'.'));
				R[y]=H;
				FOR(y2,V.size()) R[y2][x]=V[y2];
				return R;
			}
		}
		return {};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "TOP"; string Arg1 = "CODER"; string Arr2[] = {".C.", "TOP", ".D.", ".E.", ".R." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "CODER"; string Arg1 = "TOP"; string Arr2[] = {".T...", "CODER", ".P..." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AAAAA"; string Arg1 = "AAAAAA"; string Arr2[] = {"...A.", "...A.", "...A.", "AAAAA", "...A.", "...A." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, construct(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "CAT"; string Arg1 = "DOG"; string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SimplestCrossword ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

