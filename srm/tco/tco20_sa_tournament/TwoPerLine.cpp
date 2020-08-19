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

ll from[202][202];
ll to[202][202];

const ll mo=1000000007;

class TwoPerLine {
	public:
	int count(int N, int T) {
		ZERO(from);
		from[N][0]=1;
		int i,x,y;
		FOR(i,N) {
			ZERO(to);
			FOR(x,N+1) FOR(y,N+1) if(x+y<=N) {
				int nc=y+(N-x-y)*2;
				if(nc<=T) {
					(to[x][y]+=from[x][y])%=mo;
				}
				if(nc+1<=T) {
					if(x) (to[x-1][y+1]+=x*from[x][y])%=mo;
					if(y) (to[x][y-1]+=y*from[x][y])%=mo;
				}
				if(nc+2<=T) {
					if(x>=2) (to[x-2][y+2]+=x*(x-1)/2*from[x][y])%=mo;
					if(y>=2) (to[x][y-2]+=y*(y-1)/2*from[x][y])%=mo;
					if(x&&y) (to[x-1][y]+=x*y*from[x][y])%=mo;
				}
			}
			swap(from,to);
		}
		
		ll ret=0;
		FOR(x,N+1) FOR(y,N+1) if(x+y<=N) {
			int nc=y+(N-x-y)*2;
			if(nc==T) ret+=from[x][y];
		}
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 6; int Arg2 = 6; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 0; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 3; int Arg2 = 584328838; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 4; int Arg2 = 51525; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TwoPerLine ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

