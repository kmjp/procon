#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int dp[52][52];
int H[52];

class RevengeOfTheSith {
	public:
	
	int cost(int TH,int SP,int D) {
		int l=max(0,TH/SP-D);
		int r=max(0,TH/SP+1-D);
		int r2=TH%SP;
		int l2=SP-r2;
		
		return l*l*l2+r*r*r2;
		
	}
	
	int move(vector <int> steps, int T, int D) {
		int N=steps.size();
		int L,R,t;
		
		memset(dp,0x3e,sizeof(dp));
		FOR(t,N) H[t+1]=H[t]+steps[t];
		
		dp[0][T]=0;
		for(R=1;R<=N;R++) {
			for(t=0;t<=T;t++) {
				for(L=0;L<R;L++) {
					int mov=R-L-1;
					if(mov<=t) dp[R][t-mov]=min(dp[R][t-mov],dp[L][t]+cost(H[R]-H[L],R-L,D));
				}
			}
		}
		
		int mi=1<<30;
		FOR(t,T+1) mi=min(mi,dp[N][t]);
		return mi;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 19; verify_case(0, Arg3, move(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; int Arg3 = 17; verify_case(1, Arg3, move(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 30; verify_case(2, Arg3, move(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; int Arg3 = 0; verify_case(3, Arg3, move(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; verify_case(4, Arg3, move(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RevengeOfTheSith ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
