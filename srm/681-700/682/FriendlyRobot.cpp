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

int sum[4][303];
int mc[303][303];
int dp[303][303];


class FriendlyRobot {
	public:
	int getcost(int U,int D,int L,int R) {
		if((U+D+L+R)%2) return 1000;
		U=abs(U-D);
		L=abs(L-R);
		return U/2+L/2+U%2;
	}
	int findMaximumReturns(string instructions, int changesAllowed) {
		int i,j,k,x;
		int N=instructions.size();
		int ma=0;
		
		ZERO(sum);
		FOR(i,N) {
			sum[0][i+1]=sum[0][i]+(instructions[i]=='U');
			sum[1][i+1]=sum[1][i]+(instructions[i]=='D');
			sum[2][i+1]=sum[2][i]+(instructions[i]=='L');
			sum[3][i+1]=sum[3][i]+(instructions[i]=='R');
		}
		
		FOR(j,N+1) FOR(i,j) mc[i][j]=getcost(sum[0][j]-sum[0][i],sum[1][j]-sum[1][i],sum[2][j]-sum[2][i],sum[3][j]-sum[3][i]);
		
		FOR(i,N+1) FOR(j,N+1) dp[i][j]=1000;
		dp[0][0]=0;
		for(i=0;i<N;i++) {
			for(j=i+1;j<=N;j++) if(mc[i][j]<1000) {
				FOR(x,N) {
					dp[j][x+1]=min(dp[j][x+1],dp[i][x]+mc[i][j]);
					if(dp[j][x+1]<=changesAllowed) ma=max(ma,x+1);
				}
			}
		}
		
		
		
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "UULRRLLL"; int Arg1 = 1; int Arg2 = 3; verify_case(0, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ULDR"; int Arg1 = 0; int Arg2 = 1; verify_case(1, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ULDR"; int Arg1 = 2; int Arg2 = 2; verify_case(2, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ULDRRLRUDUDLURLUDRUDL"; int Arg1 = 4; int Arg2 = 8; verify_case(3, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LRLDRURDRDUDDDDRLLRUUDURURDRRDRULRDLLDDDDRLRRLLRRDDLRURLRULLLLLRRRDULRULULRLRDLLDDLLRDLUUDUURRULUDUDURULULLDRUDUUURRRURUULRLDLRRRDLLDLRDUULUURUDRURRLURLDLDDUUURRURRLRDLDDULLUDLUDULRDLDUURLUUUURRLRURRDLRRLLLRDRDUUUDRRRDLDRRUUDUDDUDDRLUDDULRURRDRUDLDLLLDLUDDRLURLDUDRUDDDDURLUUUDRLURDDDDLDDRDLUDDLDLURR"; int Arg1 = 47; int Arg2 = 94; verify_case(4, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU"; int Arg1 = 300; int Arg2 = 150; verify_case(5, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "UD"; int Arg1 = 1; int Arg2 = 1; verify_case(6, Arg2, findMaximumReturns(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FriendlyRobot ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
