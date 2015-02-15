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
const int CN=51;
ll C[CN][CN];

class AdjacentSwaps {
	public:
	ll dpdp[51][51];
	int dir[51][51];
	int N;
	ll dodo(int L,int R) {
		int x,y;
		if(L>=R) return 1;
		if(dpdp[L][R]>=0) return dpdp[L][R];
		dpdp[L][R]=0;
		
		for(x=L;x<=R;x++) {
			for(y=L;y<=R;y++) if(dir[y][x]) break;
			if(y==R+1) dpdp[L][R]+=C[R-L][x-L]*dodo(L,x-1)%mo*dodo(x+1,R)%mo;
		}
		dpdp[L][R]%=mo;
		return dpdp[L][R];
	}
	
	int theCount(vector <int> p) {
		int i,j,y,x,tot=0;
		N=p.size();
		
		FOR(x,CN) C[x][0]=C[x][x]=1;
		for(i=1;i<CN;i++) for(j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
		
		ZERO(dir);
		MINUS(dpdp);
		FOR(i,N) {
			j=i-p[i];
			if(j==0) return 0;
			if(j>0) {
				if(p[i]>0) dir[p[i]][p[i]-1]=i+1;
				for(x=p[i];x<i-1;x++) dir[x][x+1]=i+1;
				if(i<N-1) dir[i][i-1]=i+1;
			}
			else {
				if(p[i]<N-1) dir[p[i]-1][p[i]]=i+1;
				for(x=p[i];x>i+1;x--) dir[x-1][x-2]=i+1;
				if(i>0) dir[i-1][i]=i+1;
			}
		}
		FOR(i,N-1) FOR(x,N-1) FOR(y,N-1) dir[x][y]|=dir[x][i]&&dir[i][y];
		FOR(x,N-1) FOR(y,N-1) if(dir[x][y] && dir[y][x]) return 0;
		return dodo(0,N-2);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 0, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 0, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 3, 0, 5, 2, 7, 4, 8, 10, 6, 12, 9, 14, 11, 16, 13, 18, 15, 19, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 716743312; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AdjacentSwaps ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

