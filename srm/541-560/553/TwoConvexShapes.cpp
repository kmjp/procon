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

ll mo=1000000007;

class TwoConvexShapes {
	public:
	vector<string> G,G2;
	
	ll dodo(char tar,int type) {
		int H=G.size(),W=G[0].size();
		int y,x,z;
		char op='B'+'W'-tar;
		
		int mat[53][53];
		ll dp[53][53][2][3];
		ZERO(mat);
		ZERO(dp);
		
		if(G[0][W-1]==tar) return 0;
		
		FOR(y,G.size()) {
			int t=1;
			
			mat[y][0]=1;
			FOR(x,W) {
				if(t==1) {
					if(G[y][x]==op) t=0;
					else {
						if(G[y][x]==tar) {
							z=x;
							while(z>=0 && mat[y][z]) mat[y][z--]=0;
						}
						mat[y][x+1]=1;
					}
				}
				else {
					if(G[y][x]==tar) return 0;
				}
			}
			
			if(y==0) {
				for(x=1;x<=W-1;x++) dp[0][x][0][0]=dp[0][x][0][1]=dp[0][x][0][2]=mat[y][x];
			}
			else {
				FOR(x,W) if(mat[y][x]) {
					for(z=x+1;z<W;z++) dp[y][x][1][0]+=dp[y-1][z][0][0]+dp[y-1][z][1][0];
					FOR(z,x) dp[y][x][1][1]+=dp[y-1][z][0][1]+dp[y-1][z][1][1];
					
					dp[y][x][0][0] += dp[y-1][x][0][0];
					dp[y][x][1][0] += dp[y-1][x][1][0];
					dp[y][x][0][1] += dp[y-1][x][0][1];
					dp[y][x][1][1] += dp[y-1][x][1][1];
					dp[y][x][0][2] += dp[y-1][x][0][2];
					dp[y][x][0][0] %= mo;
					dp[y][x][1][0] %= mo;
					dp[y][x][0][1] %= mo;
					dp[y][x][1][1] %= mo;
					dp[y][x][0][2] %= mo;
				}
			}
		}
		
		ll ret=0;
		if(type==0) {
			ret=dp[H-1][0][1][0];
		}
		else {
			for(x=1;x<W;x++) ret+=dp[H-1][x][1][0]+dp[H-1][x][1][1]+dp[H-1][x][0][2];
		}
		return ret%mo;
	}
	
	int countWays(vector <string> grid) {
		ll ret=0;
		int i,j,k,x,y;
		string S;
		
		G=grid;
		
		// allsame
		FOR(y,G.size()) S+=G[y];
		ret=(count(S.begin(),S.end(),'B')==0)+(count(S.begin(),S.end(),'W')==0);
		
		FOR(i,4) {
			ret+=dodo('B',0);
			ret+=dodo('W',0);
			ret+=dodo('B',1);
			// rot
			grid=G;
			G.clear();
			FOR(y,grid[0].size()) G.push_back(string(grid.size(),'*'));
			FOR(y,grid.size()) FOR(x,grid[0].size()) G[grid[0].size()-1-x][y]=grid[y][x];
		}
		
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"??",
 "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {"B?",
 "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"WWB",
 "WWW",
 "WWW",
 "WWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBBBBB",
 "WWBBBB",
 "WBBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {"?BB?",
 "BBBB",
 "?BB?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, countWays(Arg0)); }
 /*
	void test_case_5() { string Arr0[] = {"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 73741817; verify_case(5, Arg1, countWays(Arg0)); }*/
	void test_case_5() { string Arr0[] = {"?????????", "???????W?", "?????????", "?????????", "?????????", "?????????", "?????????", "?????????", "??????W??", "?????????", "?????????", "?????????", "?????????", "?????????", "?????????", "?????????", "?????????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3922493; verify_case(5, Arg1, countWays(Arg0)); }
// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  TwoConvexShapes ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
