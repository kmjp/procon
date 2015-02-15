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

ll mo=1234567891;
ll dpdp[2][256][8];

class TheBrickTowerHardDivTwo {
	public:
	int find(int C, int K, int H) {
		ll tot=0;
		int mask,mask2,c[4],d[4],x,y,h;
		
		ZERO(dpdp);
		
		FOR(mask,256) {
			int n=0;
			c[0]=mask%4; c[1]=mask/4%4;	c[2]=mask/16%4;	c[3]=mask/64%4;
			if(c[0]>=C || c[1]>=C ||c[2]>=C ||c[3]>=C) continue;
			n=(c[0]==c[1])+(c[0]==c[2])+(c[1]==c[3])+(c[2]==c[3]);
			if(n<=K) {
				dpdp[0][mask][n]=1;
				tot++;
			}
		}
		
		for(h=1;h<H;h++) {
			int cur=(h-1)&1;
			int tar=h&1;
			ZERO(dpdp[tar]);
			
			FOR(mask,256) {
				c[0]=mask%4; c[1]=mask/4%4;	c[2]=mask/16%4;	c[3]=mask/64%4;
				if(c[0]>=C || c[1]>=C ||c[2]>=C ||c[3]>=C) continue;
				FOR(mask2,256) {
					d[0]=mask2%4; d[1]=mask2/4%4; d[2]=mask2/16%4;	d[3]=mask2/64%4;
					if(d[0]>=C || d[1]>=C || d[2]>=C ||d[3]>=C) continue;
					
					int n=(d[0]==d[1])+(d[0]==d[2])+(d[1]==d[3])+(d[2]==d[3]);
					n+=(d[0]==c[0])+(d[1]==c[1])+(d[2]==c[2])+(d[3]==c[3]);
					FOR(x,K+1) if(n+x<=K) dpdp[tar][mask2][n+x] +=dpdp[cur][mask][x];
				}
			}
			
			FOR(mask2,256) FOR(x,K+1) tot += dpdp[tar][mask2][x] %= mo;
			tot %= mo;
		}
		return (int)tot;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 2; int Arg3 = 4; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 7; int Arg2 = 19; int Arg3 = 1; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1; int Arg3 = 14; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 47; int Arg3 = 1008981254; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheBrickTowerHardDivTwo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

