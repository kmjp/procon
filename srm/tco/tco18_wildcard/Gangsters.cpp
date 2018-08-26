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
ll memo[160][160];

const int CN=401;
ll C[CN][CN];


class Gangsters {
	public:
	ll dfs(int P,int A) {
		if(A<1) return 0;
		if(A>P+1) return 0;
		if(P<=1) return A==1;
		if(memo[P][A]>=0) return memo[P][A];
		ll ret=0;
		
		for(int i=1;i<=P;i++) {
			if(i==1) {
				ret+=(P-1)*dfs(P-2,A-1)%mo;
			}
			else if(i==P) {
				ret+=dfs(P-1,A);
			}
			else {
				int x,y;
				ll tmp=0;
				for(x=0;x<=A;x++) {
					y=A-x;
					tmp+=dfs(i-1,x)*dfs(P-(i+1),y)%mo;
				}
				ret+=(P-1)*(tmp%mo)%mo*C[P-2][i-1]%mo;
			}
		}
		
		return memo[P][A]=ret%mo;
	}
	
	int countOrderings(int people, int alive) {
		MINUS(memo);
		int i,j;
		FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
		
		return people*(people-1)*dfs(people-2,alive)%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 12; verify_case(0, Arg2, countOrderings(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 6; verify_case(1, Arg2, countOrderings(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 0; verify_case(2, Arg2, countOrderings(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 203616; verify_case(3, Arg2, countOrderings(Arg0, Arg1)); }
//	void test_case_3() { int Arg0 = 150; int Arg1 = 100; int Arg2 = 203616; verify_case(3, Arg2, countOrderings(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Gangsters ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

