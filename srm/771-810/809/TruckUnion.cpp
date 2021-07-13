#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int D[18][18];
int dp[1<<18][18];

class TruckUnion {
	public:

	int optimize(int N, vector <int> C) {
		int y,x;
		FOR(y,N) FOR(x,N) D[y][x]=C[y*N+x];
		int mi=1LL<<30;
		
		int i,j,k,mask;
		for(i=1;i<=N-1;i++) {
			if((N-1)%i) continue;
			
			FOR(mask,1<<N) FOR(j,N) dp[mask][j]=1<<30;
			dp[1][0]=0;
			
			FOR(mask,1<<N) {
				int step=(__builtin_popcount(mask)-1)%i;
				FOR(j,N) if(dp[mask][j]<1<<30) {
					FOR(k,N) if((mask&(1<<k))==0) {
						if(step+1==i) {
							dp[mask|(1<<k)][0]=min(dp[mask|(1<<k)][0],dp[mask][j]+D[j][k]+D[k][0]);
						}
						else {
							dp[mask|(1<<k)][k]=min(dp[mask|(1<<k)][k],dp[mask][j]+D[j][k]);
						}
					}
				}
			}
			mi=min(mi,dp[(1<<N)-1][0]);
		}
		
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {0, 1, 1, 1, 1,
 1, 0, 9, 9, 9,
 1, 9, 0, 9, 9,
 1, 9, 9, 0, 9,
 1, 9, 9, 9, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, optimize(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {0, 9, 9, 9, 8,
 8, 0, 9, 9, 9,
 9, 9, 0, 8, 9,
 9, 8, 9, 0, 9,
 9, 9, 8, 9, 0}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 40; verify_case(1, Arg2, optimize(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {0, 1000000,
 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000001; verify_case(2, Arg2, optimize(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {0, 9, 9, 1, 1,
 1, 0, 9, 9, 9,
 1, 9, 0, 8, 9,
 9, 8, 9, 0, 9,
 9, 9, 8, 9, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; verify_case(3, Arg2, optimize(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {0, 1, 1, 1000000, 1,
1, 0, 90000, 80000, 70000,
1, 60000, 0, 1, 50000,
900000, 40000, 1, 0, 1,
1, 30000, 20000, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 30004; verify_case(4, Arg2, optimize(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TruckUnion ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

