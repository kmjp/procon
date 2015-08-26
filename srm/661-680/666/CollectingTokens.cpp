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

int N;
int dp[101][101][2];
int T[101];
vector<int> E[101];

class CollectingTokens {
	public:
	
	void dfs(int cur,int pre,int L) {
		dp[cur][0][0]=dp[cur][0][1]=T[cur];
		int i,x;
		
		FORR(r,E[cur]) if(r!=pre) {
			dfs(r,cur,L);
			
			for(x=L;x>=0;x--) {
				for(i=L;i>=0;i--) {
					if(x+1+i<=L) dp[cur][x+1+i][1] = max(dp[cur][x+1+i][1],dp[cur][x][0]+dp[r][i][1]);
					if(x+2+i<=L) dp[cur][x+2+i][1] = max(dp[cur][x+2+i][1],dp[cur][x][1]+dp[r][i][0]);
					if(x+2+i<=L) dp[cur][x+2+i][0] = max(dp[cur][x+2+i][0],dp[cur][x][0]+dp[r][i][0]);
				}
			}
		}
	}
	
	int maxTokens(vector <int> A, vector <int> B, vector <int> tokens, int L) {
		MINUS(dp);
		int i;
		N=A.size()+1;
		FOR(i,N) E[i].clear(), T[i]=tokens[i];
		FOR(i,N-1) E[A[i]-1].push_back(B[i]-1),E[B[i]-1].push_back(A[i]-1);
		
		dfs(0,-1,L);
		int ma=0;
		FOR(i,L+1) ma=max(ma,dp[0][i][1]);
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = 8; verify_case(0, Arg4, maxTokens(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 14; verify_case(1, Arg4, maxTokens(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1,2,5,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,1,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,1,6,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 16; verify_case(2, Arg4, maxTokens(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {9,1,7,10,5,8,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,6,9,6,6,1,1,6,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,2,1,6,3,7,8,5,2,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; int Arg4 = 26; verify_case(3, Arg4, maxTokens(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {25,22,35,42,40,9,32,12,37,44,23,1,24,28,20,4,26,33,11,48,34,6,16,50,46,17,8,43,18,30,31,36,39,13,
10,45,3,47,15,2,29,19,7,14,41,49,38,27,21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,25,25,25,42,25,40,5,35,25,32,42,9,32,23,40,25,20,33,26,37,12,1,48,24,22,25,11,24,48,34,18,9,50,42,16,40,1,
10,47,22,48,44,48,1,4,46,47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,9,4,9,5,8,6,4,4,1,4,8,3,4,5,8,5,6,4,9,7,9,7,9,5,2,7,2,7,7,5,9,5,8,5,7,1,9,3,9,3,6,4,5,5,4,7,9,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 48; int Arg4 = 194; verify_case(4, Arg4, maxTokens(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CollectingTokens ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
