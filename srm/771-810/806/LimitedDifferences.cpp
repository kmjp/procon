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

class LimitedDifferences {
	public:
	vector <int> arrange(int N, int V) {
		vector<int> ret;
		for(int i=N;i>=V+1;i--) ret.push_back(i);
		for(int a=V;a>=1;a--) {
			if((V-a)%2==0) ret.push_back(ret.back()-a);
			else ret.push_back(ret.back()+a);
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 1; int Arr2[] = {7, 6, 5, 4, 3, 2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, arrange(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 2; int Arr2[] = {1, 5, 6, 7, 8, 4, 3, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, arrange(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {2, 4, 1, 3, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, arrange(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 5; int Arr2[] = {11, 14, 12, 10, 8, 3, 7, 4, 2, 6, 1, 9, 5, 13, 15 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, arrange(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = {1, 3, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, arrange(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LimitedDifferences ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

