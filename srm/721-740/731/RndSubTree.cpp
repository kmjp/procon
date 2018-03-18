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

ll mo=1000000007;

ll dp[2020][2020];
ll p2[2020];
ll r2[2020];

class RndSubTree {
	public:
	int count(int k) {
		int i,j,x;
		
		p2[0]=r2[0]=1;
		for(i=1;i<=2010;i++) {
			p2[i]=p2[i-1]*2%mo;
			r2[i]=r2[i-1]*((mo+1)/2)%mo;
		}
		
		ZERO(dp);
		dp[0][0]=1;
		ll ret=0;
		for(i=1;i<=k;i++) { // num
			for(x=0;x<=i;x++) {
				(dp[i][x]+=dp[i-1][x]*(mo+1-r2[x]))%=mo;
				(dp[i][x+1]+=dp[i-1][x]*r2[x])%=mo;
				
				// left
				ll add=0;
				(add += (dp[i-1][x]*r2[x])%mo*((((k-i)*(k-i-1)*r2[x+1])%mo*((mo+1-r2[x+1])%mo))%mo))%=mo;
				(add += (dp[i-1][x]*r2[x])%mo*(((k-i)*r2[x+1]%mo*i)%mo))%=mo;
				(ret += add*p2[x+1])%=mo;
			}
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 875000016; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 531250023; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RndSubTree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

