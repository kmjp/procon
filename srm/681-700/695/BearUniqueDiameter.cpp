#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

vector<int> E[301];
int num[301][301];
int mat[301][301];
ll mo=1000000007;

class BearUniqueDiameter {
	public:
	int N;
	
	ll dfs(int cur,int pre,int left,int u,int v) {
		if(left<0) return 1;
		ll ret=1;
		
		int canerase = (mat[cur][u]+mat[cur][v]>mat[u][v]);
		FORR(e,E[cur]) if(e!=pre) (ret *= dfs(e,cur,left-1,u,v))%=mo;
		return ret+canerase;
	}
	
	int countSubtrees(vector <int> a, vector <int> b) {
		int x,y,z,i;
		N=a.size()+1;
		FOR(x,N) FOR(y,N) mat[x][y]=(x!=y)*999;
		FOR(i,N-1) mat[a[i]][b[i]]=mat[b[i]][a[i]]=1;
		FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][z]+mat[z][y]);
		FOR(i,N) E[i].clear();
		FOR(i,N-1) E[a[i]].push_back(b[i]),E[b[i]].push_back(a[i]);
		
		ll ret=N;
		FOR(y,N) FOR(x,y) {
			int d=mat[x][y];
			int u=-2,v=-2,i;
			FOR(i,N) {
				if(d%2==0 && mat[x][i]==mat[y][i] && mat[x][i]==d/2) u=i,v=-1;
				if(d%2==1 && mat[x][i]==d/2 && mat[y][i]==d/2+1) u=i;
				if(d%2==1 && mat[x][i]==d/2+1 && mat[y][i]==d/2) v=i;
			}
			if(v==-1) ret += dfs(u,-1,d/2-1,x,y);
			else ret += dfs(u,v,d/2-1,x,y)*dfs(v,u,d/2-1,x,y)%mo;
		}
		
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(0, Arg2, countSubtrees(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,2,1,4,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,4,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 21; verify_case(1, Arg2, countSubtrees(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,1,2,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(2, Arg2, countSubtrees(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, countSubtrees(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {36,23,33,33,33,24,33,33,33,33,37,33,33,33,33,28,33,33,22,33,
29,16,33,33,33,33,33,31,35,33,33,8,13,26,12,33,33,0,33,33}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33,33,0,9,39,33,32,40,15,19,33,30,38,7,25,33,27,11,33,3,33,33,
21,18,5,6,4,33,11,14,10,33,33,33,33,20,2,1,34,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 719477120; verify_case(4, Arg2, countSubtrees(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,0,0,1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 70; verify_case(5, Arg2, countSubtrees(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearUniqueDiameter ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
