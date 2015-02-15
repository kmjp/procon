#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<int> E[53];
int num[53];
int sc[53][53];

class TheKingsTree {
	public:
	
	void dfs(int cur) {
		int dp[55][55];
		int i,x,y;
		num[cur]=0;
		memset(dp,0x3f,sizeof(dp));
		dp[0][0]=0;
		FOR(i,E[cur].size()){
			int tar=E[cur][i];
			dfs(tar);
			FOR(x,num[cur]+1) FOR(y,num[tar]+1) dp[i+1][x+y]=min(dp[i+1][x+y],dp[i][x]+sc[tar][y]);
			num[cur]+=num[tar];
		}
		
		FOR(i,num[cur]+1) {
			sc[cur][i+1] = min(sc[cur][i+1], dp[E[cur].size()][i]+i+1);
			sc[cur][i] = min(sc[cur][i], dp[E[cur].size()][i]+(num[cur]-i)+1);
		}
		num[cur]++;
	}
	
	int getNumber(vector <int> parent) {
		int i;
		N=parent.size()+1;
		FOR(i,N) E[i].clear();
		memset(sc,0x3f,sizeof(sc));
		
		FOR(i,N-1) E[parent[i]].push_back(i+1);
		dfs(0);
		return *min_element(sc[0],sc[0]+num[0]+1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 1, 2, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 0, 1, 0, 4, 3, 5, 2, 0, 7, 9, 2, 4, 5, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheKingsTree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
