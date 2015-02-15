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

int maa[2600],mab[2600];
int dpb[2600][2600],dpe[2600][2600];

class WinterAndReindeers {
	public:
	string concatvec(vector <string> expr) { return accumulate(expr.begin(),expr.end(),string("")); }
	int getNumber(vector <string> allA, vector <string> allB, vector <string> allC) {
		int i,j,k,x,y,c,ma=0;
		string A=concatvec(allA);
		string B=concatvec(allB);
		string C=concatvec(allC);
		
		ZERO(maa);
		ZERO(mab);
		FOR(i,A.size()) {
			c=0;
			for(maa[i]=i;maa[i]<A.size();maa[i]++) {
				if(A[maa[i]]==C[c]) c++;
				if(c>=C.size()) break;
			}
		}
		FOR(i,B.size()) {
			c=0;
			for(mab[i]=i;mab[i]<B.size();mab[i]++) {
				if(B[mab[i]]==C[c]) c++;
				if(c>=C.size()) break;
			}
		}
		
		ZERO(dpb);ZERO(dpe);
		FOR(x,A.size()) FOR(y,B.size()) {
			if(A[x]==B[y]) dpb[x+1][y+1]=max(dpb[x+1][y+1],dpb[x][y]+1);
			dpb[x+1][y+1]=max(dpb[x+1][y+1],dpb[x][y+1]);
			dpb[x+1][y+1]=max(dpb[x+1][y+1],dpb[x+1][y]);
		}
		for(x=A.size();x>=1;x--) for(y=B.size();y>=1;y--) {
			if(A[x]==B[y]) dpe[x-1][y-1]=max(dpe[x-1][y-1],dpe[x][y]+1);
			dpe[x-1][y-1]=max(dpe[x-1][y-1],dpe[x][y-1]);
			dpe[x-1][y-1]=max(dpe[x-1][y-1],dpe[x-1][y]);
		}
		
		FOR(x,A.size()) FOR(y,B.size()) {
			if(maa[x]>=A.size() || mab[y]>=B.size()) continue;
			ma=max(ma,(int)C.size() + dpe[maa[x]][mab[y]] + dpb[x][y]-1);
		}
		
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X", "Y"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"X"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"ABCXD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BCDEF"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"CD"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"WE", "LOVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"WORKING", "FOR", "SANTA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"JK"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"ABCDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CDEAB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"B"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AXBADXBBAB", "CDD"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 23; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WinterAndReindeers ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

