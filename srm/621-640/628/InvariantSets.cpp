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

class InvariantSets {
	public:
	vector <int> F;
	int inloop[51],vis[51],uf[51];
	vector<int> rev[51];
	int N;
	
	void dfs(int cur,int tar) {
		if(cur==tar) inloop[tar]=1;
		else if(!vis[cur]) vis[cur]++,dfs(F[cur],tar);
	}
	ll dfs2(int cur) {
		ll ret=1;
		int i;
		FOR(i,rev[cur].size()) ret*=1+dfs2(rev[cur][i]);
		return ret;
	}
	
	long long countSets(vector <int> f) {
		int i,x;
		F=f;
		N=f.size();
		ZERO(inloop);
		FOR(i,N) {
			ZERO(vis);
			dfs(f[i],i);
			uf[i]=i;
			if(inloop[i]) FOR(x,N) if(vis[x]) uf[i]=min(uf[i],x);
			rev[i].clear();
		}
		FOR(i,N) if(inloop[i]==0) rev[uf[f[i]]].push_back(i);
		ll ret=1;
		FOR(i,N) if(inloop[i] && uf[i]==i) ret*=1+dfs2(i);
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(0, Arg1, countSets(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(1, Arg1, countSets(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(2, Arg1, countSets(Arg0)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 64LL; verify_case(3, Arg1, countSets(Arg0)); }
	void test_case_4() { int Arr0[] = {12, 10, 0, 4, 0, 6, 3, 8, 9, 14, 1, 5, 6, 12, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 90LL; verify_case(4, Arg1, countSets(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  InvariantSets ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
