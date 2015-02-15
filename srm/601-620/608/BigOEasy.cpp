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



class BigOEasy {
	public:
	
	string isBounded(vector <string> graph) {
		vector<string> G=graph;
		int N=graph.size();
		int dist[51][51];
		
		int i,x,y,z;
		FOR(x,N) FOR(y,N) dist[x][y]=(G[x][y]=='Y');
		FOR(i,N) FOR(x,N) FOR(y,N) dist[x][y] |= dist[x][i]&&dist[i][y];
		
		FOR(x,N) {
			int r=0;
			FOR(y,N) if(y!=x && G[x][y]=='Y' && dist[y][x]) r++;
			if(r>1) return "Unbounded";
		}
		return "Bounded";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYY",
 "YNY",
 "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Unbounded"; verify_case(0, Arg1, isBounded(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYN",
 "NNNY",
 "NNNY",
 "NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bounded"; verify_case(1, Arg1, isBounded(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYN",
 "NNY",
 "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bounded"; verify_case(2, Arg1, isBounded(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYN",
 "YNNN",
 "NNNY",
 "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bounded"; verify_case(3, Arg1, isBounded(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYY",
 "YNN",
 "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Unbounded"; verify_case(4, Arg1, isBounded(Arg0)); }
	void test_case_5() { string Arr0[] = {"NYNYN",
 "NNYNY",
 "YNNNN",
 "NNNNN",
 "YNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Unbounded"; verify_case(5, Arg1, isBounded(Arg0)); }
	void test_case_6() { string Arr0[] = {"NYYN",
 "NNYN",
 "NNNY",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Unbounded"; verify_case(6, Arg1, isBounded(Arg0)); }
	void test_case_7() { string Arr0[] = {"NYYNNNNYNNYNYNNNNYYNNYNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "NNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYNYYYYYNYYN",
 "YYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "YYYNYNNYNNYYYNNNYYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYYYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYN",
 "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNYNNYNNNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYYYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNYYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYYNNNNNNYYNYNNNN",
 "NNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YYYNYNNYYNYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYYNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYYYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNYYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNYNNNNNNNNNNYNNNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYYYYYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYYNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNYNNNYNNNNNNNYYNYNNNN",
 "YYYNYYNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNN",
 "YYYNYNNYNNYYYYNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYY",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNYNNNNNYNNNNNNNYYNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYYYYYYYNYYN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNYNN",
 "NYYNNNNYNNYYYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNYNNNNNNNYNNNNNNNYYNYNNNN",
 "YYYNYNNYNNYYYNYNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNNYYYNYNYNYYYNYNYNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNYNNYYNYNNNN",
 "NYYNNNNYNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNYYNNNNNNNYYNYNNNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYNNNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNNYYYYNNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNYNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNYYYNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYYYYN",
 "NYYNYNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNN",
 "NYYNNNNNNNYNYNNNNYYNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYNYNYNN",
 "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYNYYYYYNYYN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNYNNNNYNNNNNNNYYNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYNN",
 "YYYNYYYYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bounded"; verify_case(7, Arg1, isBounded(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BigOEasy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

