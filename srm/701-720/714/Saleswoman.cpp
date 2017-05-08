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

int dp[555][555][2];
int PS[555],NS[555];

class Saleswoman {
	public:
	int minMoves(vector <int> pos, vector <int> delta) {
		
		int i,x,y;
		int N=pos.size();
		FOR(x,500) FOR(y,500) dp[x][y][0]=dp[x][y][1]=1<<30;
		dp[0][0][0]=pos[0];
		
		for(i=0;i<N;i++) {
			PS[i]=(i?PS[i-1]:0)+max(delta[i],0);
			NS[i]=(i?NS[i-1]:0)-min(delta[i],0);
		}
		
		FOR(y,N) FOR(x,y+1) {
			if(x==y) {
				if(y==N-1) continue;
				if(PS[x]>=NS[x]) {
					dp[x+1][y+1][1]=min(dp[x+1][y+1][1],min(dp[x][y][0],dp[x][y][1])+pos[y+1]-pos[y]);
				}
				else {
					dp[x][y+1][0]=min(dp[x][y+1][0],min(dp[x][y][0],dp[x][y][1])+pos[y+1]-pos[y]);
				}
			}
			else {
				if(PS[y]>=NS[x]) dp[x][y][1]=min(dp[x][y][1],dp[x][y][0]+pos[y]-pos[x]);
				if(NS[x+1]<=PS[y]) dp[x+1][y][1]=min(dp[x+1][y][1],dp[x][y][1]+pos[x+1]-pos[x]);
				
				if(y<N-1) {
					dp[x][y+1][0]=min(dp[x][y+1][0],dp[x][y][0]+pos[y+1]-pos[y]);
					dp[x][y+1][0]=min(dp[x][y+1][0],dp[x][y][1]+pos[y+1]-pos[x]);
				}
			}
		}
		
		return min(dp[N-1][N-1][0],dp[N-1][N-1][1]);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,14,15,92,101}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-3,2,3,-3,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 143; verify_case(0, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,4,8,16,32,64,128}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 382; verify_case(1, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100000; verify_case(2, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100,200,300,400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,-3,-5,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 400; verify_case(3, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,2,3,5,8,13,21,34,55,89}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,1,-1,1,-1,1,-1,1,-1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 199; verify_case(4, Arg2, minMoves(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,2,3,6,10,15,21,28,36,45,55}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-3,-5,10,-2,-6,-7,3,-2,8,5,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 129; verify_case(5, Arg2, minMoves(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Saleswoman ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

