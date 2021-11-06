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

class GlobalWarmingCheck {
	public:
	vector <int> solve(int N, int M, int Y) {
		vector<ll> T,S;
		int i;
		S.push_back(0);
		int lo=0,hi=0;
		FOR(i,N) {
			ll v=S.back()+(1LL*i*i+4*i+7)%M;
			S.push_back(v);
			if(i+1>=Y) {
				if(S[i+1]-S[i+1-Y]<S[lo+Y]-S[lo]) lo=i+1-Y;
				if(S[i+1]-S[i+1-Y]>=S[hi+Y]-S[hi]) hi=i+1-Y;
			}
		}
		return {lo,hi};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 12; int Arg1 = 20; int Arg2 = 1; int Arr3[] = {8, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 20; int Arg2 = 4; int Arr3[] = {6, 2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 1; int Arg2 = 3; int Arr3[] = {0, 9 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 57000; int Arg1 = 997; int Arg2 = 23; int Arr3[] = {984, 56322 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GlobalWarmingCheck ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

