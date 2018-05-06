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

ll from[3][4],to[3][4];

ll mo=1000000007;


class ThreeSameLetters {
	public:
	int countStrings(int L, int S) {
		ZERO(from);
		from[0][0]=1;
		while(L--) {
			ZERO(to);
			
			int x,y;
			(to[0][1]=from[0][0]*S)%=mo;
			(to[0][1]+=from[0][1]*(S-1))%=mo;
			(to[0][2]+=from[0][1])%=mo;
			(to[0][1]+=from[0][2]*(S-1))%=mo;
			(to[0][3]+=from[0][2])%=mo;
			(to[2][0]+=from[0][3])%=mo;
			(to[1][1]+=from[0][3]*(S-1))%=mo;
			(to[1][1]+=from[1][1]*(S-1))%=mo;
			(to[1][2]+=from[1][1])%=mo;
			(to[1][1]+=from[1][2]*(S-1))%=mo;
			(to[2][0]+=from[1][2])%=mo;
			(to[2][0]+=from[2][0]*S)%=mo;
			
			
			swap(to,from);
		}
		
		return (from[0][3]+from[1][1]+from[1][2])%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 7; verify_case(0, Arg2, countStrings(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 4; verify_case(1, Arg2, countStrings(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 17; int Arg2 = 0; verify_case(2, Arg2, countStrings(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 11; int Arg2 = 410199993; verify_case(3, Arg2, countStrings(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ThreeSameLetters ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

