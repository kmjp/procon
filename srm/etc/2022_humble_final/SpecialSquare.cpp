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

ll num[3030];

class SpecialSquare {
	public:
	string substring(int N, int C, int A, int B) {
		int i;
		FOR(i,3000) {
			int x=A+i;
			if(x<=N) num[i]=1LL*x*C;
			else num[i]=max(0LL,1LL*(2*N-x)*C);
		}
		for(i=2999;i>=0;i--) {
			if(i) num[i-1]+=num[i]/10;
			num[i]%=10;
		}
		string S;
		FOR(i,B-A+1) S+='0'+num[i];
		return S;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; string Arg4 = "12321"; verify_case(0, Arg4, substring(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 2; int Arg3 = 5; string Arg4 = "2321"; verify_case(1, Arg4, substring(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 4; string Arg4 = "1232"; verify_case(2, Arg4, substring(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 2; int Arg2 = 7; int Arg3 = 7; string Arg4 = "5"; verify_case(3, Arg4, substring(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 9; int Arg3 = 12; string Arg4 = "0098"; verify_case(4, Arg4, substring(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 2; int Arg3 = 7; string Arg4 = "407259"; verify_case(5, Arg4, substring(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 18; int Arg1 = 3; int Arg2 = 12; int Arg3 = 32; string Arg4 = "037036962962962962962"; verify_case(6, Arg4, substring(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SpecialSquare ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

