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


class TheFrog {
	ll N;
	int NG[30002];
	public:
	double getMinimum(int D, vector <int> L, vector <int> R) {
		ll ml=0,i,l,j,MM=0;;
		N=L.size();
		ZERO(NG);
		
		FOR(i,N) {
			ml=max((int)ml,R[i]-L[i]);
			MM=max(MM,(ll)R[i]);
		}
		if(ml==1) return 1.0;
		FOR(i,N) {
			NG[L[i]]=1;
			for(l=L[i]+1;l<R[i];l++) NG[l]=2;
		}
		
		ll minu=MM,minl=1;
		
		/*
		FOR(j,2*N) {
			if(j<N) l=L[j];
			else l=R[j-N];*/
		//for(l=ml;l<=MM;l++) {
		FOR(j,2*N) {
			if(j<N) l=L[j];
			else l=R[j-N];
			if(l==0) continue;
			
			ll ng=0,c;
			for(c=l;c<MM;c+=l) {
				if(NG[c]==2) { ng=1; break; }
			}
			if(ng==1) continue;
			ll div=1;
			while(1) {
				if(l<div*ml) break;
				if(l*minl<div*minu) {
					ng=0;
					FOR(i,N) {
						if(L[i]*div/l != R[i]*div/l && (L[i]*div/l+1 != R[i]*div/l || R[i]*div%l!=0)) {
							ng=1;
							break;
						}
					}
					if(ng==0) {
						minu=l;
						minl=div;
					}
				}
				div++;
			}
			
			
		}
		return (double)minu/(double)minl;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 16; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 7.0; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 25; int Arr1[] = {11, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {21, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 10.5; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 100.0; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arr1[] = {0, 50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 50.0; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_14() { int Arg0 = 30000; int Arr1[] = {17, 25281, 5775, 2825, 14040}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {55, 26000, 5791, 3150, 14092}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 787.8787878787879; verify_case(4, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 20376; int Arr1[] = {18032, 5323, 8737, 17192, 10454, 15980, 3089, 13118, 7479, 16988, 19174, 14137, 15784, 16911, 6163, 18939, 15091, 16605, 19360, 4047, 7068, 9274}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {18061, 5336, 8743, 17226, 10473, 16018, 3100, 13124, 7480, 16991, 19209, 14177, 15793, 16926, 6190, 18944, 15118, 16642, 19378, 4071, 7108, 9320}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 787.8787878787879; verify_case(4, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TheFrog ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
