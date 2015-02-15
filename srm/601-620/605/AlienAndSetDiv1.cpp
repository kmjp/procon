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

ll mo=1000000007;
ll dpdp[52][52][1<<10];
class AlienAndSetDiv1 {
	public:
	
	int getNumber(int N, int K) {
		int i,x,y,mask,mask2=(1<<K)-1;
		ll ret=0;
		ZERO(dpdp);
		dpdp[0][0][0]=1;
		FOR(x,N+1) FOR(y,N+1) FOR(mask,1<<K) {
			if(x+y>=2*N) continue;
			ll va=dpdp[x][y][mask];
			int nex=x+y+1;
			
			bool addadd=false;
			//push A
			if(x<N && x>=y) addadd = true;
			if(x<y) {
				int y2=y,va=nex;
				FOR(i,K) {
					va--;
					if((mask>>i)&1) {
						if(y2==x+1) break;
						y2--;
					}
				}
				addadd = (nex-va>=K);
			}
			
			if(addadd) dpdp[x+1][y][((mask<<1)&mask2)] = (dpdp[x+1][y][((mask<<1)&mask2)]+va) % mo;
			
			//push B
			addadd=false;
			if(y<N && y>=x) addadd = true;
			if(y<x) {
				int x2=x,va=nex;
				FOR(i,K) {
					va--;
					if(((mask>>i)&1)==0) {
						if(x2==y+1) break;
						x2--;
					}
				}
				addadd = (nex-va>=K);
			}
			if(addadd) dpdp[x][y+1][1+((mask<<1)&mask2)] = (dpdp[x][y+1][1+((mask<<1)&mask2)]+va) % mo;
		}
		
		FOR(mask,1<<K) ret+=dpdp[N][N][mask];
		return ret%mo;
	}
	
	
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 20; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 14; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 40; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AlienAndSetDiv1 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

