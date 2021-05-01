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

const ll mo=1000000007;


class Antiqueen {
	public:
	int countPaths(int R, int C, int N) {
		ll from[202][202]={};
		int y,x;
		FOR(y,R) FOR(x,C) from[y][x]=1;
		while(N--) {
			ll LR[202]={};
			ll UD[202]={};
			ll RD[402]={};
			ll RU[402]={};
			ll S=0;
			FOR(y,R) FOR(x,C) {
				(S+=from[y][x])%=mo;
				(LR[y]+=from[y][x])%=mo;
				(UD[x]+=from[y][x])%=mo;
				(RD[y-x+200]+=from[y][x])%=mo;
				(RU[y+x]+=from[y][x])%=mo;
			}
			FOR(y,R) FOR(x,C) {
				from[y][x]=(S-LR[y]-UD[x]-RD[y-x+200]-RU[y+x]+3*from[y][x]+4*mo)%mo;
			}
		}
		
		ll ret=0;
		FOR(y,R) FOR(x,C) ret+=from[y][x];
		return ret%mo;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 16; verify_case(0, Arg3, countPaths(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 100; int Arg3 = 4; verify_case(1, Arg3, countPaths(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 100; int Arg3 = 9613417; verify_case(2, Arg3, countPaths(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 8; int Arg2 = 2; int Arg3 = 64904; verify_case(3, Arg3, countPaths(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Antiqueen ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

