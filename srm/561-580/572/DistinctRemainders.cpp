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

ll MO=1000000007;
ll combi(ll N_, ll C_) {
	int i;
	const int num=100;
	static ll rev[num+1],revt[num+1];
	
	if(rev[1]==0) {
		rev[1]=1; for(i=2;i<=num;i++) rev[i]=rev[MO%i]*(MO-MO/i)%MO;
		revt[0]=1; for(i=1;i<=num;i++) revt[i]=revt[i-1]*rev[i]%MO;
	}
	ll ret=revt[C_];
	FOR(i,C_) ret = (ret * ((N_-i)%MO))%MO;
	return ret;
}

class DistinctRemainders {
	public:
	int howMany(long long N, int M) {
		int i,x,y,sum=0;
		ll dp[50*51/2+2][51];
		ll P[60];
		
		ZERO(dp);
		dp[0][0]=1;
		
		sum=0;
		FOR(i,M) {
			for(x=sum;x>=0;x--) for(y=i;y>=0;y--) dp[x+i][y+1] = (dp[x+i][y+1]+dp[x][y])%MO;
			sum+=i;
		}
		
		P[0]=1;
		FOR(x,M) P[x+1]=(P[x]*(x+1))%MO;
		
		ll res=0;
		FOR(x,sum+1) {
			if(x>N) continue;
			if((N-x) % M) continue;
			ll H=(N-x)/M;
			for(y=1;y<=M;y++){
				if(dp[x][y]){
					res = (res+((dp[x][y]*P[y])%MO)*combi(H+y-1,y-1)) % MO;
				}
			}
		}
		
		return res;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; int Arg1 = 2; int Arg2 = 5; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 3LL; int Arg1 = 3; int Arg2 = 9; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 58LL; int Arg1 = 1; int Arg2 = 1; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 572LL; int Arg1 = 7; int Arg2 = 922572833; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 1000000000000000000LL; int Arg1 = 20; int Arg2 = 240297629; verify_case(4, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  DistinctRemainders ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
