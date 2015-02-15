#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

//-------------------------------------------------------

double dpdp[2][51][51][51];
double sum[4][55][55][55];

class RandomColoring {
	public:
	double calc(int r2,int r1,int g2,int g1,int b2,int b1) {
		double ret=0;
		int r,g,b;
		if(r1>r2 || g1>g2 || b1>b2) return 0;
		r2++,b2++,g2++;
		return sum[3][r2][g2][b2]-(sum[3][r1][g2][b2]+sum[3][r2][g1][b2]+sum[3][r2][g2][b1])
			+ (sum[3][r2][g1][b1]+sum[3][r1][g2][b1]+sum[3][r1][g1][b2])-sum[3][r1][g1][b1];
	}
	
	double getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
		ZERO(dpdp);
		int r,b,g,i;
		
		dpdp[0][startR][startG][startB]=1.0;
		FOR(i,N-1) {
			int cur=i%2,tar=cur^1;
			ZERO(dpdp[tar]);
			ZERO(sum);
			double tot=0;
			FOR(r,maxR) FOR(g,maxG) FOR(b,maxB) {
				tot+=dpdp[cur][r][g][b];
				int inin[3],out[3];
				inin[0]=(d1==0)?0:(min(r+d1-1,maxR-1)-max(r-d1+1,0)+1);
				inin[1]=(d1==0)?0:(min(g+d1-1,maxG-1)-max(g-d1+1,0)+1);
				inin[2]=(d1==0)?0:(min(b+d1-1,maxB-1)-max(b-d1+1,0)+1);
				out[0]=min(r+d2,maxR-1)-max(r-d2,0)+1;
				out[1]=min(g+d2,maxG-1)-max(g-d2,0)+1;
				out[2]=min(b+d2,maxB-1)-max(b-d2,0)+1;
				int num=out[0]*out[1]*out[2]-inin[0]*inin[1]*inin[2];
				if(num>0) sum[0][r+1][g+1][b+1]=dpdp[cur][r][g][b]/num;
			}
			FOR(r,maxR) FOR(g,maxG) FOR(b,maxB) sum[1][r+1][g+1][b+1]=sum[1][r+1][g+1][b]+sum[0][r+1][g+1][b+1];
			FOR(r,maxR) FOR(g,maxG) FOR(b,maxB) sum[2][r+1][g+1][b+1]=sum[2][r+1][g][b+1]+sum[1][r+1][g+1][b+1];
			FOR(r,maxR) FOR(g,maxG) FOR(b,maxB) sum[3][r+1][g+1][b+1]=sum[3][r][g+1][b+1]+sum[2][r+1][g+1][b+1];
			
			FOR(r,maxR) FOR(g,maxG) FOR(b,maxB) {
				dpdp[tar][r][g][b] = calc(min(r+d2,maxR-1),max(r-d2,0),min(g+d2,maxG-1),max(g-d2,0),min(b+d2,maxB-1),max(b-d2,0));
				dpdp[tar][r][g][b] -= calc(min(r+d1-1,maxR-1),max(r-d1+1,0),min(g+d1-1,maxG-1),max(g-d1+1,0),min(b+d1-1,maxB-1),max(b-d1+1,0));
			}
		}
		
		double ret=1;
		FOR(r,maxR) FOR(g,maxG) FOR(b,maxB) {
			if(abs(r-startR)<=d2 && abs(g-startG)<=d2 && abs(b-startB)<=d2 &&
			  (abs(r-startR)>=d1 || abs(g-startG)>=d1 || abs(b-startB)>=d1)) ret-=dpdp[(N-1)%2][r][g][b];
		}
		return ret;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = 0; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; double Arg9 = 0.0; verify_case(0, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = 0; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; double Arg9 = 0.22222222222222227; verify_case(1, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 2; int Arg3 = 2; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 3; int Arg8 = 3; double Arg9 = 1.0; verify_case(2, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 8; int Arg3 = 9; int Arg4 = 1; int Arg5 = 2; int Arg6 = 3; int Arg7 = 0; int Arg8 = 10; double Arg9 = 0.0; verify_case(3, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 8; int Arg3 = 9; int Arg4 = 1; int Arg5 = 2; int Arg6 = 3; int Arg7 = 4; int Arg8 = 10; double Arg9 = 0.37826245943967396; verify_case(4, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arg3 = 2; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 2; double Arg9 = 0.09090909090909148; verify_case(5, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RandomColoring ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
