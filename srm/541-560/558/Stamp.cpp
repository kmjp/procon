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
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long s64;
typedef unsigned long long u64;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


class Stamp {
	public:
	int N;
	int col[51];
	int dp[51][51][3];
	int large;
	
	int calc(int L) {
		int x,z,cc,y;
		large=1<<29;
		ZERO(dp);
		
		if(L==1) return N;
		//_P("do %d\n",L);
		FOR(x,N+1) FOR(z,N) {
			dp[x][z][0]=dp[x][z][1]=dp[x][z][2]=large;
		}
		FOR(z,N) {
			dp[0][z][0]=dp[0][z][1]=dp[0][z][2]=0;
		}
		
		
		
		FOR(x,N) {
			if(x <= N-L) {
				//V‹K‚ÉL•¶Žš’u‚­
				
				cc=min(dp[x][0][0],dp[x][0][1]);
				cc=min(cc,dp[x][0][2]);
				cc++;
				if(cc<large) {
					FOR(z,3) {
						int ok=1,l;
						FOR(l,L) if(col[l+x] >0 && col[l+x]!=z+1) ok=0;
						if(ok) {
							//_P("%d %d %d\n",x,L,z);
							FOR(l,L){
								dp[x+l+1][L-(l+1)][z] = min(dp[x+l+1][L-(l+1)][z],cc);
								//_P("set %d %d %d\n",x+l+1,L-(l+1),dp[x+l+1][L-(l+1)][z]);
							}
						}
					}
				}
			}
			
			FOR(y,L) {
				if(x-y<0) continue;
				if(x-y+L>N) continue;
				FOR(z,3) {
					if(dp[x-y][y][z]>=large) continue;
					cc=dp[x-y][y][z]+1;
					//_P("do %d %d %d %d\n",x,y,z,cc);
					int ok=1,l;
					FOR(l,L) if(col[x-y+l] >0 && col[x-y+l]!=z+1) ok=0;
					if(ok) {
						FOR(l,L) dp[x-y+l+1][L-(l+1)][z] = min(dp[x-y+l+1][L-(l+1)][z],cc);
					}
				}
			}
		}
		
		cc=large;
		cc=min(cc,dp[N][0][0]);
		cc=min(cc,dp[N][0][1]);
		cc=min(cc,dp[N][0][2]);
		return cc;
	}
	
	int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
		int i,c;
		N=desiredColor.size();
		FOR(i,N) {
			if(desiredColor[i]=='*') col[i]=0;
			if(desiredColor[i]=='R') col[i]=1;
			if(desiredColor[i]=='G') col[i]=2;
			if(desiredColor[i]=='B') col[i]=3;
		}
		int minc=1<<29;
		
		for(i=1;i<=N;i++) {
			c=calc(i);
			if(c>=large) continue;
			minc=min(minc, i*stampCost + c*pushCost);
		}
		return minc;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRGGBB"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(0, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "R**GB*"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(1, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "BRRB"; int Arg1 = 2; int Arg2 = 7; int Arg3 = 30; verify_case(2, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "R*RR*GG"; int Arg1 = 10; int Arg2 = 58; int Arg3 = 204; verify_case(3, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "*B**B**B*BB*G*BBB**B**B*"; int Arg1 = 5; int Arg2 = 2; int Arg3 = 33; verify_case(4, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
//	void test_case_5() { string Arg0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG"; int Arg1 = 7; int Arg2 = 1; int Arg3 = 30; verify_case(5, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "RRRRRRRRRRRRRRRRRRRRRRRRGGGGGGGGGGGGGGGGGGGGGGGGG"; int Arg1 = 1; int Arg2 = 100000; int Arg3 = 300024; verify_case(5, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  Stamp ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE

