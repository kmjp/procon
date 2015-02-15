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

int dpdp[100][100];
class AstronomicalRecords {
	public:
	int X,Y;
	vector<ll> AA,BB;
	
	int lcs() {
		int x,y;
		ZERO(dpdp);
		FOR(x,X) FOR(y,Y) {
			if(AA[x]==BB[y]) dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y]+1);
			dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y+1]);
			dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x+1][y]);
		}
		int ma=0;
		FOR(x,X+1) FOR(y,Y+1) ma=max(ma,dpdp[x][y]);
		return ma;
	}
	
	int minimalPlanets(vector <int> A, vector <int> B) {
		X=A.size(),Y=B.size();
		int i,j,k;
		int ret=0;
		AA.resize(X);
		BB.resize(Y);
		
		FOR(i,X) FOR(j,Y) {
			ll g=__gcd(A[i],B[j]);
			FOR(k,X) AA[k]=A[k]*(B[j]/g);
			FOR(k,Y) BB[k]=B[k]*(A[i]/g);
			ret=max(ret,lcs());
		}
		return X+Y-ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,1,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1,2,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,6,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,3,2,3,2,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {600,700,600,700,600,700,600}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(2, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,7,8,9,10,11,12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(3, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_42() { int Arr0[] = {100000000,200000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {200000000,100000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, minimalPlanets(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {616, 652, 504}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {308, 232, 304, 296, 204, 264, 280, 194, 206, 290, 234, 226, 282, 294, 208, 326, 230, 270, 330, 190, 314, 246, 286, 340, 342, 202, 276, 248, 292, 196, 244, 254, 212, 312, 288, 274, 252, 306, 216, 272, 268, 192, 332, 334, 200, 224, 298, 198, 336}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 49; verify_case(4, Arg2, minimalPlanets(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AstronomicalRecords ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

