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

string F;
vector<int> E[52],E2[52];
int N,TF;
int NF[52];
int memo[52][52][52];

class FoxConnection {
	public:
	string F;
	
	int dfscount(int cur,int pre) {
		int i;
		NF[cur]=F[cur]=='Y';
		E[cur].erase(remove(E[cur].begin(),E[cur].end(),pre),E[cur].end());
		FOR(i,E[cur].size()) NF[cur] += dfscount(E[cur][i],cur);
		return NF[cur];
	}
	
	int dfsdfs(int cur,int e,int lf) {
		if(memo[cur][e][lf]>=0) return memo[cur][e][lf];
		if(e==E[cur].size()) return memo[cur][e][lf] = (lf <= 1) ? 0 : 1<<20;
		
		int tar=E[cur][e];
		memo[cur][e][lf] = 1<<20;
		for(int sf=0;sf<=max(0,lf-1);sf++) {
			memo[cur][e][lf] = min(memo[cur][e][lf], abs(sf-NF[tar]) + dfsdfs(tar,0,sf) + dfsdfs(cur,e+1,lf-sf));
		}
		return memo[cur][e][lf];
	}
	
	
	int minimalDistance(vector <int> A, vector <int> B, string haveFox) {
		N=A.size()+1;
		int i,x,y;
		
		F=haveFox;
		TF=count(F.begin(),F.end(),'Y');
		if(TF<=1) return 0;
		
		FOR(x,N) E2[x].clear();
		FOR(x,N-1) E2[A[x]-1].push_back(B[x]-1),E2[B[x]-1].push_back(A[x]-1);
		
		int mi=1<<20,center;
		FOR(center,N) {
			MINUS(memo);
			FOR(x,N) E[x]=E2[x];
			dfscount(center,-1);
			mi=min(mi,dfsdfs(center,0,TF));
		}
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YNNY"; int Arg3 = 2; verify_case(0, Arg3, minimalDistance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NYYYY"; int Arg3 = 1; verify_case(1, Arg3, minimalDistance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,3,4,5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,2,4,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YNYNYY"; int Arg3 = 2; verify_case(2, Arg3, minimalDistance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YNNNYNYNNY"; int Arg3 = 7; verify_case(3, Arg3, minimalDistance(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,3,6,8,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,8,9,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YNNYYNYYY"; int Arg3 = 3; verify_case(4, Arg3, minimalDistance(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NY"; int Arg3 = 0; verify_case(5, Arg3, minimalDistance(Arg0, Arg1, Arg2)); }
	//void test_case_6() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NN"; int Arg3 = 0; verify_case(6, Arg3, minimalDistance(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {7, 19, 4, 18, 5, 16, 3, 22, 15, 8, 10, 1, 2, 17, 12, 21, 9, 20, 13, 14, 6, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {23, 7, 23, 23, 4, 19, 4, 18, 3, 16, 16, 10, 10, 15, 8, 1, 21, 17, 17, 13, 14, 14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NYNYYNYNYNYNYYYYNNNYYYN"; int Arg3 = 12; verify_case(6, Arg3, minimalDistance(Arg0, Arg1, Arg2)); }

// END CUT HERE
};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxConnection ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

