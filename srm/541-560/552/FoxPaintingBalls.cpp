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

typedef signed long long s64;
typedef unsigned long long u64;

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


class FoxPaintingBalls {
	public:
	long long theMax(long long R, long long G, long long B, int N) {
		u64 num1,num2,tnum,m,m2;
		u64 n[3];
		
		tnum = N*((long long)N+1)/2;
		
		if(tnum==1) {
			return R+G+B;
		}
		else if(tnum%3==0) {
			tnum/=3;
			m=min(min(R/tnum,G/tnum),B/tnum);
		}
		else {
			num1=tnum/3+1;
			num2=tnum/3;
			n[0]=R; n[1]=G; n[2]=B;
			m=0;
			while(1) {
				sort(&n[0],&n[3]);
				reverse(&n[0],&n[3]);
				if(n[0]<num1 || n[1]<num2 || n[2]<num2) break;
				
				if(n[2]<num2*5) {
					m++;
					n[0]-=num1;
					n[1]-=num2;
					n[2]-=num2;
					continue;
				}
				
				if(n[0]==n[1]) {
					if(n[1]==n[2]) {
						m2=n[0]/(num1+num2+num2);
						m+=m2*3;
						n[0]-=num1*m2+num2*m2*2;
						n[1]-=num1*m2+num2*m2*2;
						n[2]-=num1*m2+num2*m2*2;
					}
					else {
						m2=min(min(n[1]/(num1+num2),n[2]/(num2+num2)),(n[1]-n[2]));
						m+=m2*2;
						n[0]-=num1*m2+num2*m2*1;
						n[1]-=num1*m2+num2*m2*1;
						n[2]-=num2*m2*2;
					}
				}
				else {
					m2=min(min(min(n[0]/num1,n[1]/num2),n[2]/num2),n[0]-n[1]);
					m+=m2;
					n[0]-=num1*m2;
					n[1]-=num2*m2;
					n[2]-=num2*m2;
				}
				
			}
		}
		return m;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; long long Arg2 = 2LL; int Arg3 = 3; long long Arg4 = 1LL; verify_case(0, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; int Arg3 = 3; long long Arg4 = 0LL; verify_case(1, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 8LL; long long Arg1 = 6LL; long long Arg2 = 6LL; int Arg3 = 4; long long Arg4 = 2LL; verify_case(2, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 7LL; long long Arg1 = 6LL; long long Arg2 = 7LL; int Arg3 = 4; long long Arg4 = 2LL; verify_case(3, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 100LL; long long Arg1 = 100LL; long long Arg2 = 100LL; int Arg3 = 4; long long Arg4 = 30LL; verify_case(4, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { long long Arg0 = 19330428391852493LL; long long Arg1 = 48815737582834113LL; long long Arg2 = 11451481019198930LL; int Arg3 = 3456; long long Arg4 = 5750952686LL; verify_case(5, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; int Arg3 = 1; long long Arg4 = 3LL; verify_case(6, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  FoxPaintingBalls ___test;
  ___test.run_test(-1);
}
// END CUT HERE
