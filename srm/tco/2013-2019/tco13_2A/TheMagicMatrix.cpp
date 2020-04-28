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

ll mo=1234567891;
int nn;
// a^n % p
ll modpow(ll a, ll n, ll p) {
	ll r=1;
	while(n) {
		if(n%2) r=(r*a)%p;
		a=(a*a)%p;
		n>>=1;
	}
	return r;
}

int a[200][200],r[200];
ll pat(int mod) {
	int i,j,x,y;
	int A[200][200],R[200];
	int rev[5];
	
	rev[0]=0; rev[1]=1;
	if(mod==5) rev[2]=3,rev[3]=2,rev[4]=4;
	FOR(i,200) {
		R[i]=((r[i]%mod)+mod) % mod;
		FOR(j,200) A[i][j]=((a[i][j]%mod)+mod) % mod;
	}
	int po=0;
	FOR(i,200) {
		for(j=po;j<200;j++) if(A[j][i]) break;
		if(j==200) continue;
		
		FOR(x,200) swap(A[j][x],A[po][x]);
		swap(R[j],R[po]);
		
		j=rev[A[po][i]];
		FOR(x,200) A[po][x]=(A[po][x]*j)%mod;
		R[po]=(R[po]*j)%mod;
		
		for(x=po+1;x<200;x++) if(A[x][i]) {
			int tot=0;
			R[x] = (((R[x] - R[po]*A[x][i])%mod)+mod) % mod;
			for(j=199;j>=i;j--) tot += (A[x][j] = (((A[x][j] - A[po][j]*A[x][i])%mod)+mod) % mod);
			if(tot==0 && R[x]) return 0;
		}
		
		po++;
	}
	
	return modpow(mod,nn*nn+1-po,mo);
}


class TheMagicMatrix {
	public:
	
	
	int find(int n, vector <int> rows, vector <int> columns, vector <int> values) {
		int i,x,y;
		nn=n;
		int N=rows.size();
		if(n>N) return modpow(10,(n-1)*(n-1)-N+1,mo);
		
		ZERO(a);
		ZERO(r);
		// row
		FOR(y,n) {
			FOR(x,n) a[y][y*10+x] = 1;
			a[y][100]=-1;
		}
		// col 
		FOR(y,n) {
			FOR(x,n) a[n+y][x*10+y] = 1;
			a[n+y][100]=-1;
		}
		
		FOR(i,N) {
			a[2*n+i][rows[i]*10+columns[i]] = 1;
			r[2*n+i] = values[i];
		}
		
		return (int)(pat(2)*pat(5)%mo);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {0, 0, 0, 1, 2, 2, 2, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 0, 1, 2, 0, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 5, 1, 9, 5, 1, 8, 6, 7, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 474; int Arr1[] = {44, 77}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {47, 74}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 83494518; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TheMagicMatrix ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
