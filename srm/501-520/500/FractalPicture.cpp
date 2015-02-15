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

double fin[502],totgen[502];

class FractalPicture {
	public:
	
	double gen(int g,int x1,int y1,int x2,int y2) {
		if(g==500) return 0;
		
		x1=max(-10000,min(x1,10000));
		x2=max(-10000,min(x2,10000));
		y1=max(-10000,min(y1,10000));
		y2=max(-10000,min(y2,10000));
		if(x2<-27 || x1>27) return 0;
		if(y2<0 || y1>81) return 0;
		if(x1<=-27 && x2>=27 && y1<=0 && y2>=81) return totgen[g];
		
		double ret=0;
		if(x1<=0 && x2>=0) ret += fin[g]*(max(0,min(y2,54))-min(54,max(y1,0)))/54.0;
		ret += gen(g+1,x1*3,(y1-54)*3,x2*3,(y2-54)*3);  //top
		ret += gen(g+1,(y1-54)*3,-x2*3,(y2-54)*3,-x1*3);//left
		ret += gen(g+1,(54-y2)*3,x1*3,(54-y1)*3,x2*3);//right
		
		return ret;
	}
	
	
	
	double getLength(int x1, int y1, int x2, int y2) {
		int i=0;
		fin[0]=54;
		FOR(i,500) fin[i+1]=fin[i]/3.0;
		totgen[499]=fin[499]*1.5;
		for(i=499;i>0;i--) totgen[i-1] = fin[i-1] + 3*totgen[i];
		
		return gen(0,x1,y1,x2,y2);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = -1; int Arg1 = 0; int Arg2 = 1; int Arg3 = 53; double Arg4 = 53.0; verify_case(0, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 10; double Arg4 = 0.0; verify_case(1, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = -10; int Arg1 = 54; int Arg2 = 10; int Arg3 = 55; double Arg4 = 21.0; verify_case(2, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_32() { int Arg0 = 14; int Arg1 = 45; int Arg2 = 22; int Arg3 = 54; double Arg4 = 2999.0; verify_case(3, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 80; int Arg2 = 1; int Arg3 = 81; double Arg4 = 322; verify_case(3, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FractalPicture ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

