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

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

vector<int> E[1010];
int vis[1010];
int dp[1010][2];
class MaxCutFree {
	public:
	void dfs(int cur,int pre) {
		vis[cur]=1;
		dp[cur][0]=0;
		dp[cur][1]=1;
		FORR(e,E[cur]) if(e!=pre) {
			dfs(e,cur);
			dp[cur][0]+=max(dp[e][0],dp[e][1]);
			dp[cur][1]+=dp[e][0];
		}
	}
	
	int solve(int n, vector <int> a, vector <int> b) {
		int M=a.size();
		int i,j;
		FOR(i,n) E[i].clear();
		FOR(i,M) {
			UF<1050> uf;
			FOR(j,M) if(i!=j) uf(a[j],b[j]);
			if(uf[a[i]]!=uf[b[i]]) {
				E[a[i]].push_back(b[i]);
				E[b[i]].push_back(a[i]);
			}
		}
		
		ZERO(vis);
		ZERO(dp);
		int ret=0;
		FOR(i,n) if(vis[i]==0) {
			dfs(i,-1);
			ret+=max(dp[i][0],dp[i][1]);
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {0, 1, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 0, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {0,1,2,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {0,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
//	void test_case_3() { int Arg0 = 4; int Arr1[] = {0,0,0,1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,2,3,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 13; int Arr1[] = {0,0,0,0,1,1,2,2,3,3,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6,7,8,9,10,11,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MaxCutFree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

