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

int L0,L1,L;
int A[5050];
int B[5050];
ll SA[5050];
ll SB[5050];
int dp[5050][5050];

class TwoMonthScheduling {
	public:
	int minimumMonths(int workers, vector <int> firstMonth0, vector <int> firstMonth1, vector <int> secondMonth0, vector <int> secondMonth1) {
		L0 = firstMonth0.size();
		L1 = firstMonth1.size();
		int i0,i1,i;
		FOR(i1,L1) FOR(i0,L0) {
			A[i1*L0+i0+1]=min(workers, firstMonth0[i0]^firstMonth1[i1]);
			B[i1*L0+i0+1]=min(workers, secondMonth0[i0]^secondMonth1[i1]);
			SA[i1*L0+i0+1]=SA[i1*L0+i0]+A[i1*L0+i0+1];
			SB[i1*L0+i0+1]=SB[i1*L0+i0]+B[i1*L0+i0+1];
		}
		int N=L0*L1;
		int x,y,W=workers;
		FOR(x,N+2) FOR(y,N+2) dp[x][y]=101010;
		int mi=101010;
		dp[1][0]=0;
		int L,R,R2;
		for(L=1;L<=N;L++) {
			int R2=0;
			for(R=N;R>=L;R--) dp[L][R]=min(dp[L][R],dp[L][R+1]);
			for(R=L;R<=N;R++) if(SA[R]-SA[L-1]<=W && SB[R]-SB[L-1]<=W) {
				//completely new
				dp[L][R]=min(dp[L][R],dp[L][0]+2);
				//fin
				dp[R+1][0]=min(dp[R+1][0],dp[L][R]);
				for(R2=max(R+1,R2);R2<=N;R2++) {
					if(SB[R]-SB[L-1]+SA[R2]-SA[R]>W || SB[R2]-SB[R]>W) break;
				}
				while(R2>R && (SB[R]-SB[L-1]+SA[R2]-SA[R]>W || SB[R2]-SB[R]>W)) R2--;
				dp[R+1][R2]=min(dp[R+1][R2],dp[L][R]+1);
			}
			mi=min(mi,dp[L][N]);
		}
		mi=min(mi,dp[N+1][0]);
		
		return mi;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1000; int Arr1[] = {900, 150, 300, 200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {400, 300, 600, 150}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 4; verify_case(0, Arg5, minimumMonths(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 1000; int Arr1[] = {900, 150, 300, 200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {400, 600, 300, 150}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; verify_case(1, Arg5, minimumMonths(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1000; int Arr1[] = {350, 172, 24}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {998, 54}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {513, 119, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {24, 118}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 7; verify_case(2, Arg5, minimumMonths(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 47; int Arr1[] = {0,0,0,0,0,0,1,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0,0,0,0,0,0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0,0,0,0,0,0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,0,0,0,0,0,1,0,0,0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(3, Arg5, minimumMonths(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TwoMonthScheduling ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

