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

class FridayTheThirteenth {
	public:
	vector <int> count(int firstDay, int isLeap) {
		vector<int> ret(12);
		vector<int> A={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		A[1]+=isLeap;
		int i,j;
		FOR(i,12) {
			FOR(j,A[i]) {
				if(j==12&&firstDay%7==5) ret[i]=1;
				firstDay++;
			}
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 0; int Arr2[] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arr2[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arr2[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FridayTheThirteenth ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

