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
ll dpdp[2][51][51][51];

class VocaloidsAndSongs {
	public:
	int count(int S, int gumi, int ia, int mayu) {
		int i,x,y,z;
		ZERO(dpdp);
		dpdp[0][gumi][ia][mayu]=1;
		FOR(i,S) {
			int cur=i%2,tar=cur^1;
			ZERO(dpdp[tar]);
			FOR(x,51) FOR(y,51) FOR(z,51) {
				if(dpdp[cur][x][y][z]==0) continue;
				
				if(x&&y&&z) dpdp[tar][x-1][y-1][z-1] = (dpdp[tar][x-1][y-1][z-1] + dpdp[cur][x][y][z]) % mo;
				if(x&&y) dpdp[tar][x-1][y-1][z] = (dpdp[tar][x-1][y-1][z] + dpdp[cur][x][y][z]) % mo;
				if(x&&z) dpdp[tar][x-1][y][z-1] = (dpdp[tar][x-1][y][z-1] + dpdp[cur][x][y][z]) % mo;
				if(y&&z) dpdp[tar][x][y-1][z-1] = (dpdp[tar][x][y-1][z-1] + dpdp[cur][x][y][z]) % mo;
				if(x) dpdp[tar][x-1][y][z] = (dpdp[tar][x-1][y][z] + dpdp[cur][x][y][z]) % mo;
				if(y) dpdp[tar][x][y-1][z] = (dpdp[tar][x][y-1][z] + dpdp[cur][x][y][z]) % mo;
				if(z) dpdp[tar][x][y][z-1] = (dpdp[tar][x][y][z-1] + dpdp[cur][x][y][z]) % mo;
			}
		}
		
		return dpdp[S%2][0][0][0];
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 6; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; int Arg4 = 9; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 10; int Arg2 = 10; int Arg3 = 10; int Arg4 = 0; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 12; int Arg2 = 8; int Arg3 = 9; int Arg4 = 81451692; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 198591037; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  VocaloidsAndSongs ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

