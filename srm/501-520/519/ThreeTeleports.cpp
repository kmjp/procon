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

class ThreeTeleports {
	public:
	int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
		ll xt[8],yt[8];
		ll dist[8][8];
		int i,x,y;
		xt[0]=xMe;yt[0]=yMe;
		xt[7]=xHome;yt[7]=yHome;
		FOR(i,3) sscanf(teleports[i].c_str(),"%lld%lld%lld%lld",&xt[i*2+1],&yt[i*2+1],&xt[i*2+2],&yt[i*2+2]);
		FOR(x,8) FOR(y,8) dist[x][y]=abs(xt[x]-xt[y])+abs(yt[x]-yt[y]);
		dist[1][2]=dist[2][1]=10;
		dist[3][4]=dist[4][3]=10;
		dist[5][6]=dist[6][5]=10;
		FOR(i,8) FOR(x,8) FOR(y,8) dist[x][y]=min(dist[x][y],dist[x][i]+dist[i][y]);
		return dist[0][7];
		
		
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 4; int Arg3 = 5; string Arr4[] = {"1000 1001 1000 1002", "1000 1003 1000 1004", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 3; verify_case(0, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 20; int Arg3 = 20; string Arr4[] = {"1 1 18 20", "1000 1003 1000 1004", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 14; verify_case(1, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 20; int Arg3 = 20; string Arr4[] = {"1000 1003 1000 1004", "18 20 1 1", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 14; verify_case(2, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10000; int Arg3 = 20000; string Arr4[] = {"1000 1003 1000 1004", "3 3 10004 20002", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 30; verify_case(3, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 10000; int Arg3 = 30000; string Arr4[] = {"3 10 5200 4900", "12212 8699 9999 30011", "12200 8701 5203 4845"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 117; verify_case(4, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1000000000; int Arg3 = 1000000000; string Arr4[] = {"0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 36; verify_case(5, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ThreeTeleports ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

