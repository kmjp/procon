#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

class BuildingRoutes {
	int mat[51][51];
	int num[51][51];
	public:
	int build(vector <string> dist, int T) {
		int N=dist.size();
		int i,x,y,x2,y2;
		FOR(x,N) FOR(y,N) mat[x][y]=dist[x][y]-'0';
		FOR(i,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
		int ret=0;
		FOR(x,N) FOR(y,N) if(x!=y) {
			i=0;
			FOR(x2,N) FOR(y2,N) if(x2!=y2 && mat[x2][x]+dist[x][y]-'0'+mat[y][y2]==mat[x2][y2]) i++;
			if(i>=T) ret+=dist[x][y]-'0';
		}
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"011",
 "101",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(0, Arg2, build(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"033",
 "309",
 "390"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 12; verify_case(1, Arg2, build(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0123",
 "1023",
 "1203",
 "1230"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; verify_case(2, Arg2, build(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"05789654",
 "10347583",
 "65085479",
 "55602398",
 "76590934",
 "57939045",
 "12345608",
 "68647640"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 40; verify_case(3, Arg2, build(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  BuildingRoutes ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
