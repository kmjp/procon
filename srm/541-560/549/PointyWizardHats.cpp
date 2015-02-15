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

class PointyWizardHats {
	public:
	int ok[51][51];
	int g[105][105];
	
	int can(int th,int tr,int bh,int br) {
		double tth;
		
		if(tr >= br) return 0;
		tth = bh * (tr/(double)br);
		if(tth<=th-0.0000001) return 1;
		return 0;
	}
	
	int path[100000];
	int vi[103];
	int np,tn,bn;
	int npm[102][102];
	int nnp[102];
	int ngpath[102];
	
	int dfs(int e) {
		int r,i;
		
		path[np++]=e;
		vi[e]=1;
		
		if(e==tn+bn+1) return 1;
		
		FOR(i,nnp[e]) {
			int t = npm[e][i];
			if(g[e][t] && vi[t]==0) {
				r=dfs(t);
				if(r==1) return 1;
			}
		}
		np--;
		return 0;
	}
	
	int match() {
		int m=0,i;
		int x,y;
		
		ZERO(ngpath);
		while(1) {
			np=0;
			ZERO(vi);
			if(!dfs(0)) break;
			
			FOR(i,np-1) g[path[i]][path[i+1]]=0, g[path[i+1]][path[i]]=1;
		}
		FOR(x,tn) FOR(y,bn) if(g[1+tn+y][x+1]) m++;
		return m;
	}
	
	
	int getNumHats(vector <int> topHeight, vector <int> topRadius, vector <int> bottomHeight, vector <int> bottomRadius) {
		tn = topHeight.size();
		bn = bottomHeight.size();
		int t,b;
		
		ZERO(g);
		FOR(t,tn) g[0][1+t]=1;
		FOR(b,bn) g[tn+1+b][tn+bn+1]=1;
		
		FOR(t,tn) FOR(b,bn) {
			ok[t][b] = can(topHeight[t],topRadius[t],bottomHeight[b],bottomRadius[b]);
			if(ok[t][b]) g[1+t][tn+1+b]=1;
		}
		int i;
		FOR(i,102) {
			nnp[i]=0;
			FOR(b,102) if(g[i][b] || g[b][i]) npm[i][nnp[i]++] = b;
		}
		return match();
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {30}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(0, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(1, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(2, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(3, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,4,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,8,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(4, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(5, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {123,214,232,323,342,343}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {123,123,232,123,323,434}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {545,322,123,545,777,999}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {323,443,123,656,767,888}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5; verify_case(6, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arr0[] = {999,999,999,10000,10000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10000,10000,10000,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2324,2323,234,5454,323,232}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3222,434,5454,23}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(7, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PointyWizardHats ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

