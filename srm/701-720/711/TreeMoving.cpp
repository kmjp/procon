#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;
vector<pair<int,int>> E[303][303];
vector<pair<int,int>> E2[303];

int par[303][303];
int pv[303][303];
int D[303][303];
int lca[303][303];
vector<int> O[303];
int dp[303][303];

class TreeMoving {
	public:
	int add(int& a,int b) {
		a += b;
		if(a>=mo) a-=mo;
		return a;
	}
	void dfs(int id,int cur,int pre,int d) {
		D[id][cur]=d;
		FORR(e,E[id][cur]) {
			if(e.first==pre) {
				par[id][cur]=pre;
				pv[id][cur]=e.second;
			}
			else {
				dfs(id,e.first,cur,d+1);
			}
		}
		O[id].push_back(cur);
	}
	int count(int n, vector <int> roots, vector <int> a, vector <int> b, vector <int> c) {
		int i,k,j,x;
		int m=a.size();
		FOR(i,303) FOR(k,303) E[i][k].clear();
		
		FOR(i,m) {
			E2[i].clear();
			ll X=c[i];
			FOR(j,n-1) {
				int u=(roots[i]+j+1)%n;
				int v=(roots[i]+(X%(j+1)))%n;
				E[i][u].push_back({v,j});
				E[i][v].push_back({u,j});
				E2[i].push_back({u,v});
				X = (a[i]*X+b[i])%mo;
			}
			O[i].clear();
			dfs(i,0,-1,0);
		}
		FOR(i,m) {
			FOR(k,n-1) {
				int u=E2[i][k].first;
				int v=E2[i][k].second;
				j = (i+1)%m;
				while(D[j][u]<D[j][v]) v=par[j][v];
				while(D[j][u]>D[j][v]) u=par[j][u];
				while(u!=v) v=par[j][v], u=par[j][u];
				lca[i][k]=u;
			}
		}
		
		ll ret=0;
		FOR(x,n-1) {
			ZERO(dp);
			dp[0][x]=1;
			FOR(i,m) {
				int sum[303]={};
				FOR(k,n-1) {
					add(sum[E2[i][k].first],dp[i][k]);
					add(sum[E2[i][k].second],dp[i][k]);
					add(sum[lca[i][k]],mo-dp[i][k]);
					add(sum[lca[i][k]],mo-dp[i][k]);
				}
				FORR(o,O[(i+1)%m]) if(o) {
					add(dp[i+1][pv[(i+1)%m][o]],sum[o]);
					add(sum[par[(i+1)%m][o]],sum[o]);
				}
			}
			ret += dp[m][x];
		}
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(0, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 1, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6, 5, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 5, 9}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(1, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {0, 1, 1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7, 4, 7, 9, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8, 3, 9, 5, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {6, 0, 1, 5, 9}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 22; verify_case(2, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {373206610, 937739946, 172315864}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {870770575, 635025870, 765158489}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {915938656, 747443899, 387215442}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(3, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 10; int Arr1[] = {0, 1, 0, 4, 0, 2, 1, 8, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {508821715, 481198414, 163209181, 56649169, 276327522, 13486359, 845629232, 482370937, 373100199, 297431939}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {256979012, 884002808, 393825387, 609998779, 816536931, 123064634, 673095376, 18224901, 510687925, 466437174}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {368733721, 596826005, 853637399, 436680590, 369153650, 853574577, 609377415, 903050702, 259325966, 105275092}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 17765; verify_case(4, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TreeMoving ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

