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
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


class TreeUnionDiv2 {
	int T,K;
	int dist[2][10][10];
	vector<int> P;
	public:
	
	int maximumCycles(vector <string> tree1, vector <string> tree2, int K) {
		int i,j,k,x,y,z;
		T=tree1.size();
		this->K=K;
		FOR(x,T) FOR(y,T) dist[0][x][y]=(tree1[x][y]=='X')?1:100;
		FOR(x,T) FOR(y,T) dist[1][x][y]=(tree2[x][y]=='X')?1:100;
		FOR(x,T) dist[0][x][x]=dist[1][x][x]=0;
		FOR(i,T) FOR(j,T) FOR(k,T) dist[0][j][k] = min(dist[0][j][k], dist[0][j][i]+dist[0][i][k]);
		FOR(i,T) FOR(j,T) FOR(k,T) dist[1][j][k] = min(dist[1][j][k], dist[1][j][i]+dist[1][i][k]);
		P.clear();
		FOR(i,T) P.push_back(i);
		
		int ma=0;
		do{
			//select2
			int res=0;
			FOR(x,T) for(y=x+1;y<T;y++) {
				if(2+dist[0][x][y]+dist[1][P[x]][P[y]]==K) res++;
			}
			ma=max(ma,res);
		}while(next_permutation(P.begin(),P.end()));
		
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"-X",
 "X-"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X",
 "X-"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 1; verify_case(0, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"-X-",
 "X-X",
 "-X-"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-",
 "X-X",
 "-X-"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 2; verify_case(1, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"-X-",
 "X-X",
 "-X-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-",
 "X-X",
 "-X-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 0; verify_case(2, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"-X---",
 "X-XXX",
 "-X---",
 "-X---",
 "-X---"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-X-",
 "X-X-X",
 "-X---",
 "X----",
 "-X---"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 5; verify_case(3, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"-XX------",
 "X------X-",
 "X--XX-X--",
 "--X--X---",
 "--X------",
 "---X----X",
 "--X------",
 "-X-------",
 "-----X---"}

; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-X-------",
 "X-X------",
 "-X-XX----",
 "--X---X--",
 "--X--X---",
 "----X--XX",
 "---X-----",
 "-----X---",
 "-----X---"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 17; verify_case(4, Arg3, maximumCycles(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TreeUnionDiv2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
