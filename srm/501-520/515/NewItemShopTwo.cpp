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

int N[2];
int T[2][51],C[2][51],P[2][51];


class NewItemShopTwo {
	public:
	double getMaximum(vector <string> customers) {
		int i,j,x,y;
		string s;
		ZERO(T),ZERO(C),ZERO(P);
		FOR(i,2) {
			int d=0,j;
			N[i]=0;
			
			ITR(it,customers[i]) {
				if(*it==',') d++;
				else if(*it==' ') d=0,N[i]++;
				else if(d==0) T[i][N[i]]=T[i][N[i]]*10+*it-'0';
				else if(d==1) C[i][N[i]]=C[i][N[i]]*10+*it-'0';
				else if(d==2) P[i][N[i]]=P[i][N[i]]*10+*it-'0';
			}
			N[i]++;
		}
		double r=0;
		FOR(i,2) {
			int lx=100;
			FOR(x,N[i]) {
				int ly=100;
				double expe=0;
				FOR(y,N[i^1]) {
					if(T[i^1][y]<T[i][x]) ly-=P[i^1][y];
					else expe+=C[i^1][y]*P[i^1][y];
				}
				
				r += max((double)C[i][x],ly?(expe/ly):0)*P[i][x]*ly/10000.0;
				lx-=P[i][x];
			}
			
		}
		
		return r;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "8,1,80 16,100,11", "12,10,100" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 19.0; verify_case(0, Arg1, getMaximum(Arg0)); }
	void test_case_1() { string Arr0[] = { "8,1,80 16,100,11", "12,10,90 13,30,5" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 19.4; verify_case(1, Arg1, getMaximum(Arg0)); }
	void test_case_2() { string Arr0[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 90.0; verify_case(2, Arg1, getMaximum(Arg0)); }
	void test_case_3() { string Arr0[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,95" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 95.0; verify_case(3, Arg1, getMaximum(Arg0)); }
	void test_case_4() { string Arr0[] = { "0,3,1 2,4,1 4,5,9 6,2,6 8,5,3 10,5,8 12,9,7 14,9,3", 
  "1,2,3 3,8,4 5,6,2 7,6,4 9,3,3 11,8,3 13,2,7 15,9,5" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0692999999999997; verify_case(4, Arg1, getMaximum(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NewItemShopTwo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

