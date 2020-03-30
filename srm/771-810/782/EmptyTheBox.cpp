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

double dp[1<<12]={};
int sum[1<<12];
double P[13];

class EmptyTheBox {
	public:
	double minExpectedPenalty(int D, int T) {
		ll ret=0;
		while(T>2*D) ret+=T, T--;
		
		int i,j;
		FOR(i,1<<12) {
			sum[i]=0;
			FOR(j,12) if(i&(1<<j)) sum[i]+=j+1;
		}
		
		int x,y;
		FOR(i,13) P[i]=0;
		for(x=1;x<=D;x++) {
			for(y=1;y<=D;y++) {
				P[x+y]+=1.0/(D*D);
			}
		}
		
		int mask;
		dp[0]=ret;
		for(mask=1;mask<(1<<T);mask++) {
			double Q[13];
			FOR(i,2*D+1) Q[i]=ret+sum[mask];
			for(int sm=mask-1; sm>=0; sm--) {
				sm&=mask;
				if(2<=sum[mask]-sum[sm] && sum[mask]-sum[sm]<=2*D) Q[sum[mask]-sum[sm]]=min(Q[sum[mask]-sum[sm]],dp[sm]);
			}
			dp[mask]=0;
			for(i=2;i<=2*D;i++) dp[mask] += P[i]*Q[i];
		}
		
		return dp[(1<<T)-1];
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; double Arg2 = 1.25; verify_case(0, Arg2, minExpectedPenalty(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 2; double Arg2 = 2.777777777777778; verify_case(1, Arg2, minExpectedPenalty(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 10; double Arg2 = 16.64572136166177; verify_case(2, Arg2, minExpectedPenalty(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 10; double Arg2 = 33.489906787872314; verify_case(3, Arg2, minExpectedPenalty(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EmptyTheBox ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

