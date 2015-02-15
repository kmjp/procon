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

ll dp[2][51][51][51][3];
ll mo=1000000007;

class ColorfulCupcakesDivTwo {
	public:
	int countArrangements(string cupcakes) {
		int c[3],i,L,x,y,z,col;
		ll ret = 0;
		
		L=cupcakes.size();
		ZERO(c);
		FOR(i,L) c[cupcakes[i]-'A']++;
		ZERO(dp);
		
		FOR(col,3) {
			if(c[col]==0) continue;
			dp[1][c[0]-(col==0)][c[1]-(col==1)][c[2]-(col==2)][col]=1;
		
			for(i=1;i<L;i++) {
				int cur=i%2, tar=cur^1;
				ZERO(dp[tar]);
				FOR(x,L) FOR(y,L) {
					z = L-i-x-y;
					if(z<0) break;
					
					if(dp[cur][x][y][z][0]) {
						if(y) dp[tar][x][y-1][z][1] = (dp[tar][x][y-1][z][1] + dp[cur][x][y][z][0]) % mo;
						if(z) dp[tar][x][y][z-1][2] = (dp[tar][x][y][z-1][2] + dp[cur][x][y][z][0]) % mo;
					}
					if(dp[cur][x][y][z][1]) {
						if(x) dp[tar][x-1][y][z][0] = (dp[tar][x-1][y][z][0] + dp[cur][x][y][z][1]) % mo;
						if(z) dp[tar][x][y][z-1][2] = (dp[tar][x][y][z-1][2] + dp[cur][x][y][z][1]) % mo;
					}
					if(dp[cur][x][y][z][2]) {
						if(x) dp[tar][x-1][y][z][0] = (dp[tar][x-1][y][z][0] + dp[cur][x][y][z][2]) % mo;
						if(y) dp[tar][x][y-1][z][1] = (dp[tar][x][y-1][z][1] + dp[cur][x][y][z][2]) % mo;
					}
				}
			}
			
			ret += dp[L%2][0][0][0][0]+dp[L%2][0][0][0][1]+dp[L%2][0][0][0][2];
			ret -= dp[L%2][0][0][0][col];
		}
		
		return ret % mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABAB"; int Arg1 = 2; verify_case(0, Arg1, countArrangements(Arg0)); }
	void test_case_1() { string Arg0 = "ABABA"; int Arg1 = 0; verify_case(1, Arg1, countArrangements(Arg0)); }
	void test_case_2() { string Arg0 = "ABC"; int Arg1 = 6; verify_case(2, Arg1, countArrangements(Arg0)); }
	void test_case_3() { string Arg0 = "ABABABABABABABABABABABABABABABABABABABABABABABABAB"; int Arg1 = 2; verify_case(3, Arg1, countArrangements(Arg0)); }
	void test_case_4() { string Arg0 = "BCBABBACBABABCCCCCAABBAACBBBBCBCAAA"; int Arg1 = 741380640; verify_case(4, Arg1, countArrangements(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ColorfulCupcakesDivTwo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

