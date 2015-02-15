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
ll dpr[11];
class SmallBricks31 {
	public:
	int w;
	
	ll dp[12][1024];
	ll getr(int mask) {
		int x,bw;
		ll ret=1;
		if(dpr[1]==0) {
			dpr[0]=1;
			dpr[1]=1;
			dpr[2]=2;
			for(x=3;x<=10;x++) dpr[x]=dpr[x-1]+dpr[x-2]+dpr[x-3];
		}
		bw=0;
		FOR(x,w) {
			if(mask&(1<<x)) bw++;
			else ret*=dpr[bw],bw=0;
		}
		return (ret*dpr[bw])%mo;
	}
	
	int countWays(int w, int h) {
		int x,y,mask,nmask;
		this->w=w;
		
		ZERO(dp);
		dp[0][(1<<w)-1]=1;
		FOR(y,h) FOR(mask,1<<w) {
			FOR(nmask,1<<w) {
				int mu=0;
				int ng=0;
				FOR(x,w) if(((mask&(1<<x))==0) && (nmask&(1<<x))) {
					if(x==0 || x==w-1) ng++;
					else {
						if ((mask&(1<<(x-1)))==0 || (mask&(1<<(x+1)))==0) ng++;
						if ((nmask&(1<<(x-1)))==0 || (nmask&(1<<(x+1)))==0) ng++;
						if (mu&(1<<(x-1)) || mu&(1<<(x+1))) ng++;
						mu |= (1<<x) | (1<<(x-1)) | (1<<(x+1));
					}
				}
				if(ng) continue;
				dp[y+1][nmask] += getr(nmask^mu) * dp[y][mask];
				dp[y+1][nmask] %= mo;
			}
		}
		
		ll ret=0;
		FOR(mask,1<<w) ret+=dp[h][mask];
		return (int)(ret%mo);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 4; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 13; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 84; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 9; int Arg2 = 132976888; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 11676046; verify_case(4, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SmallBricks31 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

