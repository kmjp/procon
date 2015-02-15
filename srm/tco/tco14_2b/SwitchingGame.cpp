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

class SwitchingGame {
	public:
	int N,M;
	int need[51][2];
	int fix[55][55];
	
	int timeToWin(vector <string> states) {
		N=states.size();
		M=states[0].size();
		ZERO(need);
		int i,x,y;
		int ret=N;
		
		FOR(y,N+1) FOR(x,M+1) fix[y][x]=N;
		for(y=N-1;y>=0;y--) {
			FOR(x,M) {
				if(states[y][x]=='?') fix[y][x]=fix[y+1][x];
				else fix[y][x]=y;
			}
		}
		
		string s="";
		FOR(i,M) s+="-";
		FOR(y,N) {
			int needp=0,needm=0;
			FOR(x,M) {
				if(s[x]=='-' && states[y][x]=='+') needp=1;
				if(s[x]=='+' && states[y][x]=='-') needm=1;
			}
			ret+=needp+needm;
			FOR(x,M) {
				if(states[y][x]!='?') s[x]=states[y][x];
				else {
					if(fix[y][x]<N && states[fix[y][x]][x]=='+' && needp) s[x]='+';
					if(fix[y][x]<N && states[fix[y][x]][x]=='-' && needm) s[x]='-';
				}
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"++--",
 "--++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, timeToWin(Arg0)); }
	void test_case_1() { string Arr0[] = {"+-++",
 "+-++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, timeToWin(Arg0)); }
	void test_case_2() { string Arr0[] = {"++",
 "+?",
 "?+",
 "++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, timeToWin(Arg0)); }
	void test_case_3() { string Arr0[] = {"+", 
 "?",
 "?",
 "?",
 "-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, timeToWin(Arg0)); }
	void test_case_4() { string Arr0[] = {"+??+++",
 "++??+-",
 "?++??+",
 "?-+-??",
 "??+?++",
 "++-?+?",
 "?++?-+",
 "?--+++",
 "-??-?+"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(4, Arg1, timeToWin(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  SwitchingGame ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
