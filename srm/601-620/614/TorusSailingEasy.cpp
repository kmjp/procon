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

const int MAT=301;
int Gauss(int n,double mat_[MAT][MAT],double v_[MAT],double r[MAT]) {
	int i,j,k;
	double mat[MAT][MAT],v[MAT];
	memmove(mat,mat_,sizeof(mat));
	memmove(v,v_,sizeof(v));
	
	FOR(i,n) {
		if(mat[i][i]==0) {
			for(j=i+1;j<n;j++) if(mat[j][i]) break;
			if(j>=n) return -1;
			FOR(k,n) swap(mat[i][k],mat[j][k]);
			swap(v[i],v[k]);
		}
		v[i]/=mat[i][i];
		for(k=n-1;k>=i;k--) mat[i][k]/=mat[i][i];
		for(j=i+1;j<n;j++) {
			v[j]-=v[i]*mat[j][i];
			for(k=n-1;k>=i;k--) mat[j][k]-=mat[i][k]*mat[j][i];
		}
	}
	
	for(i=n-1;i>=0;i--) {
		for(j=n-1;j>i;j--) v[i]-=mat[i][j]*v[j],mat[i][j]=0;
		r[i]=v[i];
	}
	return 0;
}



class TorusSailingEasy {
	public:
	double expectedTime(int N, int M, int goalX, int goalY) {
		int ps[2]={1000000,1000000};
		int x[2]={0,0},y[2]={0,0},i,j;
		
		double mm[MAT][MAT];
		double v[MAT],r[MAT];
		
		FOR(j,10000) {
			x[0]+=1;
			y[0]+=1;
			x[1]+=N-1;
			y[1]+=M-1;
			x[0]%=N;
			y[0]%=M;
			x[1]%=N;
			y[1]%=M;
			if(x[0]==goalX && y[0]==goalY) ps[0]=min(ps[0],j+1);
			if(x[1]==goalX && y[1]==goalY) ps[1]=min(ps[1],j+1);
		}
		if(ps[0]>=100000) return -1;
		ZERO(mm);
		ZERO(v);
		for(i=1;i<ps[0]+ps[1];i++) mm[i][i-1]=mm[i][i+1]=-0.5,v[i]=1;
		FOR(i,ps[0]+ps[1]+1) mm[i][i]=1;
		Gauss(ps[0]+ps[1]+1,mm,v,r);
		
		
		return r[ps[0]];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; double Arg4 = 1.0; verify_case(0, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 1; double Arg4 = -1.0; verify_case(1, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; double Arg4 = 2.0; verify_case(2, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 1; int Arg3 = 3; double Arg4 = 27.0; verify_case(3, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TorusSailingEasy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

