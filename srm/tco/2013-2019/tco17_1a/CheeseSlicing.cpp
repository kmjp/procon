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

int memo[101][101][101];

class CheeseSlicing {
	public:
	int S;
	int hoge(int a,int b,int c) {
		if(a<S) return 0;
		if(b<S) return 0;
		if(c<S) return 0;
		if(a<b) swap(a,b);
		if(b<c) swap(b,c);
		if(a<b) swap(a,b);
		if(memo[a][b][c]>=0) return memo[a][b][c];
		memo[a][b][c]=a*b;
		
		int x;
		for(x=S;a-x>=S;x++) memo[a][b][c]=max(memo[a][b][c],hoge(x,b,c)+hoge(a-x,b,c));
		for(x=S;b-x>=S;x++) memo[a][b][c]=max(memo[a][b][c],hoge(a,x,c)+hoge(a,b-x,c));
		for(x=S;c-x>=S;x++) memo[a][b][c]=max(memo[a][b][c],hoge(a,b,x)+hoge(a,b,c-x));
		
		
		return memo[a][b][c];
	}
	
	int totalArea(int A, int B, int C, int S) {
		MINUS(memo);
		this->S=S;
		return hoge(A,B,C);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 3; int Arg3 = 2; int Arg4 = 0; verify_case(0, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 5; int Arg3 = 3; int Arg4 = 25; verify_case(1, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 5; int Arg3 = 2; int Arg4 = 58; verify_case(2, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 49; int Arg1 = 92; int Arg2 = 20; int Arg3 = 3; int Arg4 = 30045; verify_case(3, Arg4, totalArea(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CheeseSlicing ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

