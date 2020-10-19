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

int D[20][20];
int M[20][20];
double dp[1<<15];

class RandomDijkstraDiv2 {
	public:
	double solve(int N, vector <int> G) {
		int i,x,y,z,j;
		FOR(y,N) FOR(x,N) M[y][x]=D[y][x]=G[y*N+x];
		FOR(z,N) FOR(x,N) FOR(y,N) M[x][y]=min(M[x][y],M[x][z]+M[z][y]);
		ZERO(dp);
		dp[0]=1;
		
		int mask;
		FOR(mask,1<<N) if(dp[mask]>0) {
			
			FOR(i,N) if((mask&(1<<i))==0) {
				int isok=0;
				if(i==0) isok=1;
				FOR(j,N) if((mask&(1<<j))&&M[0][j]+D[j][i]==M[0][i]) isok=1;
				
				if(isok) {
					dp[mask|(1<<i)]+=dp[mask]/(N-__builtin_popcount(mask));
				}
				
			}
		}
		
		return dp[(1<<N)-1];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = { 0, 1, 1000, 1000, 1000, 0, 1, 1000, 1000, 1000, 0, 1, 1000, 1000, 1000, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.041666666666666664; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = { 0, 1, 1, 1, 1, 0, 1000, 1000, 1, 1000, 0, 1000, 1, 1000, 1000, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.25; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {
      0, 1000, 1000,    4,    5,
   1000,    0, 1000, 1000, 1000,
   1000,    2,    0, 1000, 1000,
   1000, 1000,    6,    0, 1000,
   1000,    7, 1000, 1000,    0
}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.058333333333333334; verify_case(2, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RandomDijkstraDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

