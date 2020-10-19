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
double dp[5000000];
int p3[15];

class RandomDijkstraDiv1 {
	public:
	double solve(int N, vector <int> G) {
		int i,x,y,z,j;
		FOR(y,N) FOR(x,N) M[y][x]=D[y][x]=G[y*N+x];
		FOR(z,N) FOR(x,N) FOR(y,N) M[x][y]=min(M[x][y],M[x][z]+M[z][y]);
		p3[0]=1;
		FOR(i,14) p3[i+1]=p3[i]*3;
		ZERO(dp);
		dp[0]=1;
		
		double ret=0;
		int mask;
		FOR(mask,p3[N]) if(dp[mask]>0) {
			int ok=0;
			int ng=0;
			int lef=0;
			int cnt=0;
			FOR(i,N) {
				int v=mask/p3[i]%3;
				if(v==2) ok|=1<<i;
				if(v==1) ng|=1<<i;
				if(v==0) lef|=1<<i,cnt++;
			}
			if(lef==0) {
				int isok=1;
				
				FOR(i,N) if(ng&(1<<i)) {
					isok=0;
					FOR(j,N) if((ok&(1<<j))&&M[0][j]+D[j][i]==M[0][i]) isok=1;
					if(isok==0) break;
				}
				if(isok) ret+=dp[mask];
			}
			else {
				FOR(i,N) if(lef&(1<<i)) {
					int isok=1;
					int nmask=mask;
					if(i==0) isok=2;
					FOR(j,N) if((ok&(1<<j))&&M[0][j]+D[j][i]==M[0][i]) isok=2;
					nmask+=isok*p3[i];
					dp[nmask]+=dp[mask]/cnt;
				}
			}
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = { 0, 1, 1000, 1000, 1000, 0, 1, 1000, 1000, 1000, 0, 1, 1000, 1000, 1000, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.16666666666666666; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = { 0, 1, 1, 1, 1, 0, 1000, 1000, 1, 1000, 0, 1000, 1, 1000, 1000, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {
      0, 1000, 1000,    4,    5,
   1000,    0, 1000, 1000, 1000,
   1000,    2,    0, 1000, 1000,
   1000, 1000,    6,    0, 1000,
   1000,    7, 1000, 1000,    0
}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.375; verify_case(2, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RandomDijkstraDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

