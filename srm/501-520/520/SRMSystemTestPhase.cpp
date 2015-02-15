#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

ll mo=1000000007;
ll dp[51][4][4];
ll numnum[4][4][4];

class SRMSystemTestPhase {
	public:
	int countWays(vector <string> description) {
		int N,i,x,p,c,p2,c2,y[3];
		int num[51];
		ZERO(numnum);
		numnum[0][0][0]=numnum[1][0][0]=numnum[0][1][0]=numnum[0][0][1]=1;
		numnum[2][0][0]=numnum[0][2][0]=numnum[0][0][2]=1;
		numnum[3][0][0]=numnum[0][3][0]=numnum[0][0][3]=1;
		numnum[1][1][0]=numnum[0][1][1]=numnum[1][0][1]=2;
		numnum[1][2][0]=numnum[2][1][0]=numnum[0][1][2]=numnum[0][2][1]=3;
		numnum[1][0][2]=numnum[2][0][1]=3;
		numnum[1][1][1]=6;
		
		
		N=description.size();
		FOR(i,N) num[i]=(description[i][0]&1)+(description[i][1]&1)+(description[i][2]&1);
		ZERO(dp);
		dp[0][3][0]=1;
		FOR(x,N) {
			FOR(p,4) FOR(c,4) FOR(p2,4) FOR(c2,4) {
				if(p2+c2>num[x]) continue;
				if(dp[x][p][c]==0) continue;
				if(p2>p || (p==p2 && c>c2)) continue;
				dp[x+1][p2][c2] = (dp[x+1][p2][c2]+dp[x][p][c]*numnum[p2][c2][num[x]-p2-c2]) % mo;
			}
		}
		ll ret=0;
		FOR(p,4) FOR(c,4) ret+=dp[N][p][c];
		
		return (int)(ret%mo);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {"YNN",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"YNN",
 "NNN",
 "NNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {"YYY",
 "YNY",
 "NYY",
 "YYN",
 "YYY",
 "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15176; verify_case(4, Arg1, countWays(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SRMSystemTestPhase ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

