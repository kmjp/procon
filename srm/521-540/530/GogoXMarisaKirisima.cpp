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

class GogoXMarisaKirisima {
	public:
	int N;
	int mat[51][51],mat2[51][51];
	
	int solve(vector <string> choices) {
		int x,y,i;
		N=choices.size();
		FOR(x,N) FOR(y,N) mat[x][y]=mat2[x][y]=(choices[x][y]!='Y');
		FOR(x,N) mat[x][x]=mat2[x][x]=0;
		FOR(i,N) FOR(x,N) FOR(y,N) mat2[x][y]=min(mat2[x][y],mat2[x][i]+mat2[i][y]);
		
		if(mat2[0][N-1]) return 0;
		
		int ret=1;
		FOR(x,N) if(mat2[0][x]==0 && mat2[x][N-1]==0) {
			FOR(y,N) if(x!=y && mat[x][y]==0 && mat2[y][N-1]==0) ret++;
			if(x!=N-1) ret--;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN"
,"YNY"
,"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNY"
,"YNY"
,"YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"NN"
,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYY"
,"NNNY"
,"NNNY"
,"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GogoXMarisaKirisima ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
