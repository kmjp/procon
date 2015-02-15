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

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b,a%b);}
int vis[21][100001];

class KnightCircuit {
	public:
	
	long dfs(int W,int H,int a,int b) {
		int dx[8]={a,-a,a,-a,b,-b,b,-b};
		int dy[8]={b,b,-b,-b,a,a,-a,-a};
		int x,y,i;
		long res=0;
		ZERO(vis);
		FOR(y,H) FOR(x,W) if(vis[x][y]==0) {
			long num=1;
			queue<int> dfs;
			dfs.push(y*100+x);
			vis[x][y]=1;
			while(!dfs.empty()) {
				int key=dfs.front();
				dfs.pop();
				int sx=key%100,sy=key/100;
				FOR(i,8) {
					int tx=sx+dx[i];
					int ty=sy+dy[i];
					if(tx>=0 && tx<W && ty>=0 && ty<H && vis[tx][ty]==0) {
						vis[tx][ty]=1;
						num++;
						dfs.push(ty*100+tx);
					}
				}
				
			}
			res = max(res,num);
		}
		return res;
	}
	
	long long maxSize(int w, int h, int a, int b) {
		int g=gcd(a,b);
		if(g>1){ w=(w+(g-1))/g; h=(h+(g-1))/g; a/=g; b/=g;}
		if(w>h) swap(w,h), swap(a,b);
		
		if(w<=max(a,b)*2) return dfs(w,h,a,b);
		if((a+b)%2) return w*(ll)h;
		else return (1+w*(ll)h)/2;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; int Arg3 = 1; long long Arg4 = 1LL; verify_case(0, Arg4, maxSize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 20; int Arg2 = 1; int Arg3 = 3; long long Arg4 = 11LL; verify_case(1, Arg4, maxSize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 100000; int Arg1 = 100000; int Arg2 = 1; int Arg3 = 2; long long Arg4 = 10000000000LL; verify_case(2, Arg4, maxSize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 2; long long Arg4 = 8LL; verify_case(3, Arg4, maxSize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 30; int Arg1 = 30; int Arg2 = 8; int Arg3 = 4; long long Arg4 = 64LL; verify_case(4, Arg4, maxSize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 32; int Arg1 = 34; int Arg2 = 6; int Arg3 = 2; long long Arg4 = 136LL; verify_case(5, Arg4, maxSize(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  KnightCircuit ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
