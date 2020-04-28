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

int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

class Knishop {
	public:
	
	int getShortestPath(int x1, int y1, int x2, int y2) {
		x2-=x1;
		y2-=y1;
		if(x2==0 && y2==0) return 0;
		
		int i,j;
		if(abs(x2)==abs(y2)) return 1;
		FOR(i,8) if(x2==dx[i] && y2==dy[i]) return 1;
		
		if((abs(x2)+abs(y2))%2==0) return 2;
		FOR(i,8) {
			x1=x2+dx[i];
			y1=y2+dy[i];
			if(abs(x1)==abs(y1)) return 2;
			FOR(j,8) if(x1==dx[j] && y1==dy[j]) return 2;
		}
		return 3;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 2; int Arg3 = 3; int Arg4 = 2; verify_case(0, Arg4, getShortestPath(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 7; int Arg3 = 0; int Arg4 = 1; verify_case(1, Arg4, getShortestPath(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 918273645; int Arg1 = 987654321; int Arg2 = 123456789; int Arg3 = 123456798; int Arg4 = 3; verify_case(2, Arg4, getShortestPath(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 42; int Arg1 = 47; int Arg2 = 42; int Arg3 = 47; int Arg4 = 0; verify_case(3, Arg4, getShortestPath(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 14; int Arg3 = 8; int Arg4 = 2; verify_case(4, Arg4, getShortestPath(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Knishop ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

