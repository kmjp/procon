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

class EllysThreeRivers {
	public:
	int L,WA;
	vector<int> W,S;
	
	double len1(double le) {
		int x;
		double l=0,r=le,res=0;
		FOR(x,100) {
			double p0=(l+r)/2.0;
			double p1=(l+p0)/2.0;
			double p2=(r+p0)/2.0;
			
			double lp0=p0/WA+sqrt(W[0]*W[0]+(le-p0)*(le-p0))/S[0];
			double lp1=p1/WA+sqrt(W[0]*W[0]+(le-p1)*(le-p1))/S[0];
			double lp2=p2/WA+sqrt(W[0]*W[0]+(le-p2)*(le-p2))/S[0];
			
			if(lp1==lp2) l=p1,r=p2;
			else if(lp1<lp2) r=p2;
			else l=p1;
			res=min(lp0,min(lp1,lp2));
		}
		
		return res;
	}
	
	double len2(double le) {
		int x;
		double l=0,r=le,res=0;
		FOR(x,100) {
			double p0=(l+r)/2.0;
			double p1=(l+p0)/2.0;
			double p2=(r+p0)/2.0;
			
			double lp0=sqrt(W[1]*W[1]+p0*p0)/S[1]+sqrt(W[2]*W[2]+(le-p0)*(le-p0))/S[2];
			double lp1=sqrt(W[1]*W[1]+p1*p1)/S[1]+sqrt(W[2]*W[2]+(le-p1)*(le-p1))/S[2];
			double lp2=sqrt(W[1]*W[1]+p2*p2)/S[1]+sqrt(W[2]*W[2]+(le-p2)*(le-p2))/S[2];
			
			if(lp1==lp2) l=p1,r=p2;
			else if(lp1<lp2) r=p2;
			else l=p1;
			res=min(lp0,min(lp1,lp2));
		}
		
		return res;
	}
	
	double getMin(int length, int walk, vector <int> width, vector <int> swim) {
		L=length;
		WA=walk;
		W=width;
		S=swim;
		
		double l=0,r=length,res=0;
		int x;
		
		FOR(x,100) {
			double p0=(l+r)/2.0;
			double p1=(l+p0)/2.0;
			double p2=(r+p0)/2.0;
			
			double lp0=len1(p0)+len2(length-p0);
			double lp1=len1(p1)+len2(length-p1);
			double lp2=len1(p2)+len2(length-p2);
			
			if(lp1==lp2) l=p1,r=p2;
			else if(lp1<lp2) r=p2;
			else l=p1;
			res=min(lp0,min(lp1,lp2));
		}
		
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 8; int Arr2[] = {5, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 2, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 3.2063518370413364; verify_case(0, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1000; int Arg1 = 100; int Arr2[] = {91, 911, 85}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {28, 97, 19}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 21.549321613601297; verify_case(1, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 666; int Arg1 = 4; int Arr2[] = {777, 888, 999}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {11, 12, 13}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 228.26633673141083; verify_case(2, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 100; int Arr2[] = {2, 3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {77, 88, 99}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.12049782476139667; verify_case(3, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_42() { int Arg0 = 873; int Arg1 = 54; int Arr2[] = {444, 588, 263}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {67, 97, 26}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 26.365540023205206; verify_case(4, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 848; int Arg1 = 55; int Arr2[] = {215,244,956}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {34,27,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 31.522247049508906; verify_case(4, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysThreeRivers ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

