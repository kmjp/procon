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

ll p[12];

class StringsBetween {
	public:
	
	ll hoge(int L,string S) {
		ll ret=0;
		int x,i;
		FOR(i,S.size()) {
			ret++;
			FOR(x,S[i]-'a') ret+=p[L-1-i];
		}
		return ret;
	}
	
	long long count(int L, string A, string B) {
		
		p[0]=1;
		int i;
		FOR(i,10) p[i+1]=p[i]*26+1;
		
		return hoge(L,B)-hoge(L,A)-1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = ""; string Arg2 = "d"; long long Arg3 = 3LL; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "ay"; string Arg2 = "c"; long long Arg3 = 28LL; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; string Arg1 = "ay"; string Arg2 = "cb"; long long Arg3 = 30LL; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; string Arg1 = "bulldog"; string Arg2 = "bulldozers"; long long Arg3 = 350592LL; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; string Arg1 = "bx"; string Arg2 = "fad"; long long Arg3 = 57028LL; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 4; string Arg1 = "pier"; string Arg2 = "pies"; long long Arg3 = 0LL; verify_case(5, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 10; string Arg1 = ""; string Arg2 = "zzzzzzzzzz"; long long Arg3 = 146813779479509LL; verify_case(6, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  StringsBetween ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

