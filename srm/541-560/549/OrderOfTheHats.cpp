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

int N;
int mat[21][21];
int mask[1<<20];

class OrderOfTheHats {
	public:
	
	
	int minChanged(vector <string> spellChart) {
		int x,y,i,j,r;
		
		N=spellChart.size();
		FOR(y,N) FOR(x,N) mat[y][x]=spellChart[y][x]=='Y';
		
		FOR(i,1<<N) mask[i]=99999;
		mask[0]=0;
		FOR(i,1<<N) {
			FOR(j,N) {
				if(i & (1<<j)) continue;
				r=0;
				FOR(x,N) if((i & (1<<x))||j==x) r += mat[j][x];
				mask[i | (1<<j)] = min(mask[i | (1<<j)], mask[i] + r);
			}
		}
		return mask[(1<<N)-1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minChanged(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYN",
 "NNY",
 "NNN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minChanged(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYN",
 "NNY",
 "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minChanged(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYYYYY",
 "YNYYYYY",
 "YYNYYYY",
 "YYYNYYY",
 "YYYYNYY",
 "YYYYYNY",
 "YYYYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(3, Arg1, minChanged(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNY",
 "YNYN",
 "YNNN",
 "YYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, minChanged(Arg0)); }
	void test_case_5() { string Arr0[] = {"YYYYYNNYYYNYNNNNYNNY",
 "NYNNNYYNNYNYYYNYYYYY",
 "NNYNNNYYNNNNNNYYYYNY",
 "YYNYNYYNNYYYNYNNNYYY",
 "NYYNNYNYNYNNNNYYYNYN",
 "NNNNNYYNYNNYYYYNYYYN",
 "YNYNYYNNNYNNNNNYNNYY",
 "NYYYYNYNYNNYNNYNNNNY",
 "YYYYNYYNNYYYNNYNNYNY",
 "YYYYYYNYNYNYNNNNNNYN",
 "NNYYYYYNNNYNNNYNNNNY",
 "YYNNNYNYYNYYNYYNYNYN",
 "NNYNYYNYYNYYNYNYNYYN",
 "YNYNYYNYNNNYNYNYYNYY",
 "NNYNNNYYYYYYYYYYYNYY",
 "YYYYYNYYNYYYYYNNYNNN",
 "NYYYYYYYYNNNNNYYNNYN",
 "YNNYNNNYYNYYYNYNYYYY",
 "YYNNYNYYYNYYNNNYYNNY",
 "NNYNYNYYYNYYNYNNYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 79; verify_case(5, Arg1, minChanged(Arg0)); }
	void test_case_6() { string Arr0[] = {"YYNYNN",
 "YNYNNY",
 "YYYYNN",
 "NNNYNN",
 "NNNYNN",
 "YNYNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(6, Arg1, minChanged(Arg0)); }
	void test_case_7() { string Arr0[] = {"NNNNNNNNNN",
 "NNNNNNNNNN",
 "NNNYNNYNNN",
 "NNNYNNYNNN",
 "NNNYNNYNNN",
 "NNNNNNNNNN",
 "NNYYYYYYNN",
 "NNYNNNNYNN",
 "NNNYYYYNNN",
 "NNNNNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(7, Arg1, minChanged(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OrderOfTheHats ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

