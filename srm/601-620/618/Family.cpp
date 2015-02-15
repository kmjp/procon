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




class Family {
	public:
	int N;
	int mat[101][101];
	int col[101];
	
	int check(int cur,int c) {
		int i,tot=1;
		col[cur]=c;
		
		FOR(i,N) if(mat[cur][i]) {
			if(col[i]==c) return 0;
			if(col[i]==0) tot &= check(i,3-c);
		}
		return tot;
	}
	
	string isFamily(vector <int> parent1, vector <int> parent2) {
		int i,x;
		N=parent1.size();
		
		ZERO(mat);
		ZERO(col);
		FOR(i,N) if(parent1[i]!=-1) mat[parent1[i]][parent2[i]]=mat[parent2[i]][parent1[i]]=1;
		
		FOR(i,N) if(col[i]==0 && check(i,1)==0) return "Impossible";
		return "Possible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1,-1,-1,-1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1,-1,0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(3, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(4, Arg2, isFamily(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Family ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

