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

class OverlappingRectangles {
	public:
	vector <int> design(int N, int P) {
		vector<int> V;
		int i;
		for(i=N-1;i>=0;i--) {
			int lef=N-1-i;
			int x=min(lef,P);
			V.push_back(i);
			V.push_back(0);
			V.push_back(i+x+1);
			V.push_back(1);
			P-=x;
		}
		assert(P==0);
		return V;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arr2[] = {1, 1, 2, 2, 2, 2, 4, 3, 3, 3, 7, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, design(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arr2[] = {1, 0, 101, 2, 0, 1, 2, 101, 100, 1, 102, 101, 1, 100, 101, 102 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, design(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 10; int Arr2[] = {2, 3, 4, 7, 2, 3, 4, 7, 2, 3, 4, 7, 2, 3, 4, 7, 2, 3, 4, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, design(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OverlappingRectangles ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

