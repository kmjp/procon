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
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int okok[1200][1200];

class EnclosingTriangleColorful {
	int N;
	vector<int> X,Y;
	vector<pair<int,int> > V;
	public:
	
	int check(int p1,int p2) {
		int i;
		FOR(i,N) {
			if((V[p2].second-V[p1].second)*(X[i]-V[p1].first)-
				(V[p2].first-V[p1].first)*(Y[i]-V[p1].second)<0) return 0;
		}
		return 1;
	}
	
	int getNumber(int m, vector <int> x, vector <int> y) {
		
		N=x.size();
		V.clear();
		int x1,x2,y1,y2,i,j,k,r=0;
		
		ZERO(okok);
		X=x;Y=y;
		
		for(i=1;i<m;i++) V.push_back(make_pair(i,m));  // top 
		for(i=1;i<m;i++) V.push_back(make_pair(m,m-i));// right
		for(i=1;i<m;i++) V.push_back(make_pair(m-i,0));// bottom
		for(i=1;i<m;i++) V.push_back(make_pair(0,i));// left
		
		FOR(x1,V.size()) FOR(x2,V.size()) {
			if(V[x1].first==V[x2].first && (V[x1].first==0 || V[x1].first==m)) continue;
			if(V[x1].second==V[x2].second && (V[x1].second==0 || V[x1].second==m)) continue;
			okok[x1][x2]=check(x1,x2);
		}
		
		m--;
		FOR(i,m) FOR(j,m) if(okok[i][j+m]) FOR(k,m) r+=okok[j+m][k+2*m]&okok[k+2*m][i];
		FOR(i,m) FOR(j,m) if(okok[i][j+m]) FOR(k,m) r+=okok[j+m][k+3*m]&okok[k+3*m][i];
		FOR(i,m) FOR(j,m) if(okok[i][j+2*m]) FOR(k,m) r+=okok[j+2*m][k+3*m]&okok[k+3*m][i];
		FOR(i,m) FOR(j,m) if(okok[i+m][j+2*m]) FOR(k,m) r+=okok[j+2*m][k+3*m]&okok[k+3*m][i+m];
		
		return r;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = { 1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 3, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 7; int Arr1[] = { 1, 1, 6, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 6, 1, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = { 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 72; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = { 2, 6, 7, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 7, 7, 9, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 52; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 15; int Arr1[] = { 7, 6, 5, 4, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 4, 7, 10, 13 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 150; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 300; int Arr1[] = { 117, 183, 181, 118, 132, 128, 184, 150, 168, 121, 
  179, 132, 168, 182, 119, 117, 180, 120, 175, 177, 
  116, 175, 128, 163, 181, 178, 123, 118, 172, 143, 
  163, 157, 179, 122, 121, 119, 157, 122, 150, 180, 
  137, 177, 125, 123, 172, 125, 137, 143, 120, 178 }
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 157, 157, 132, 163, 181, 180, 150, 116, 181, 125, 
  125, 119, 119, 163, 132, 143, 172, 172, 179, 178, 
  150, 121, 120, 118, 168, 123, 178, 137, 120, 117, 
  182, 117, 175, 177, 175, 168, 183, 123, 184, 128, 
  118, 122, 179, 122, 180, 121, 182, 183, 128, 177 }
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21690886; verify_case(5, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  EnclosingTriangleColorful ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
