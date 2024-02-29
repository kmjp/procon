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

int D[5050];

class FrequentSubstring {
	public:
	int maximize(string needle, int H) {
		int N=needle.size();
		int i;
		int ret=H/N;
		for(i=1;i<N;i++) if(H-N>=N-i&&needle.substr(0,i)==needle.substr(N-i)) {
			ret=max(ret,1+(H-N)/(N-i));
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abc"; int Arg1 = 5; int Arg2 = 1; verify_case(0, Arg2, maximize(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aaa"; int Arg1 = 5; int Arg2 = 3; verify_case(1, Arg2, maximize(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "abracadabra"; int Arg1 = 28; int Arg2 = 3; verify_case(2, Arg2, maximize(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "toot"; int Arg1 = 8; int Arg2 = 2; verify_case(3, Arg2, maximize(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "abracadabra"; int Arg1 = 3; int Arg2 = 0; verify_case(4, Arg2, maximize(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FrequentSubstring ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

