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

// index, num cost comp0, cost comp1
ll dp[37][73][73][2];
ll tmp[73][73][2];

class CentaurCompany {
	public:
	vector<int> edge[60];
	int N;
	
	
	void dfs(int cur, int from) {
		vector<int>& e=edge[cur];
		int x,y,z,a,b;
		
		dp[cur][37][36][0]=dp[cur][36][37][1]=1;
		
		FOR(x,e.size()) {
			if(e[x]==from) continue;
			dfs(e[x],cur);
			ZERO(tmp);
			FOR(y,73) FOR(z,73) {
				if(dp[e[x]][y][z][0]==0 && dp[e[x]][y][z][1]==0) continue;
				FOR(a,73) FOR(b,73) {
					if(a+y-36<1 || a+y-36>71 || b+z-36<1 || b+z-36>71) continue;
					if(dp[cur][a][b][0]==0 && dp[cur][a][b][1]==0) continue;
					//_P("%d : %d %d %d %d : ",cur,y,z,a,b);
					tmp[a+y-36-2][b+z-36][0] += dp[cur][a][b][0]*dp[e[x]][y][z][0];
					tmp[a+y-36+0][b+z-36][0] += dp[cur][a][b][0]*dp[e[x]][y][z][1];
					tmp[a+y-36][b+z-36+0][1] += dp[cur][a][b][1]*dp[e[x]][y][z][0];
					tmp[a+y-36][b+z-36-2][1] += dp[cur][a][b][1]*dp[e[x]][y][z][1];
					//_P("%d %lld %lld %lld %lld\n",cur,dp[cur][a+y-36-1][b+z-36][0],dp[cur][a+y-36+1][b+z-36][0],
					//tmp[a+y-36][b+z-36+1][1],dp[cur][a+y-36][b+z-36-1][1]);
				}
			}
			
			memmove(dp[cur],tmp,sizeof(tmp));
		}
		
		return ;
	}
	
	double getvalue(vector <int> a, vector <int> b) {
		int x,y,z,w;
		ll tot=0;
		N=a.size()+1;
		
		FOR(x,N) edge[x].clear();
		
		FOR(x,a.size()) {
			edge[a[x]-1].push_back(b[x]-1);
			edge[b[x]-1].push_back(a[x]-1);
		}
		
		ZERO(dp);
		dfs(0,-1);
		
		FOR(y,73) FOR(z,73) {
			//if(dp[0][y][z][0] || dp[0][y][z][1]) _P("%d\t%d\t%lld\t%lld\t%lld\n",y-36,z-36,dp[0][y][z][0],dp[0][y][z][1],
			//	(max(0,y-38)+max(0,z-38))*dp[0][y][z][0]+(max(0,y-38)+max(0,z-38))*dp[0][y][z][1]);
			tot += (max(0,y-38)+max(0,z-38))*dp[0][y][z][0];
			tot += (max(0,y-38)+max(0,z-38))*dp[0][y][z][1];
		}
		return tot/(double)(1LL<<N);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.125; verify_case(1, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.375; verify_case(2, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.41796875; verify_case(3, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 15.500000001076842; verify_case(4, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {10, 7, 2, 5, 6, 2, 4, 9, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 10, 10, 4, 1, 6, 2, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.646484375; verify_case(5, Arg2, getvalue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  CentaurCompany ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
