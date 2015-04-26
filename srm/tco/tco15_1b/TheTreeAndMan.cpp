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

ll mo=1000000007;
int PN[2020],D[2020];
vector<pair<int,int> > E[2020];
int L[2020],R[2020],id;

class TheTreeAndMan {
	public:
	int N;
	ll pat2(int cur,int exc) {
		ll ret=0;
		int tot=0;
		if(E[cur].size()<2) return 0;
		FORR(r,E[cur]) {
			if(exc!=-1 && L[r.first]<=L[exc]&&R[exc]<=R[r.first]) continue;
			ret += tot*r.second % mo;
			tot += r.second;
		}
		return ret % mo;
	}
	
	int dfs(int cur) {
		int tot=1;
		L[cur]=id++;
		FORR(r,E[cur]) if(r.first>cur) tot += r.second = dfs(r.first);
		R[cur]=id++;
		return tot;
	}
	
	int solve(vector <int> parent) {
		int i,x,y;
		N=parent.size()+1;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) E[parent[i]].emplace_back(i+1,0), D[i+1]=D[parent[i]]+1;
		
		id=0;
		dfs(0);
		
		ll ret=0;
		FOR(y,N) FOR(x,y) if(L[x]<L[y] && R[y]<R[x]) ret += D[x] * pat2(x,y) % mo * pat2(y,-1) % mo;
		
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,2,2,2,4,0,4,7,2,10,11,9,0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,2,2,3,1,0,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,0,2,3,5,2,5,3,7,7,7,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {0,0,1,2,2,2,1,4,2,9,0,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, solve(Arg0)); }
	void test_case_5() { int Arr0[] = {0,0,0,2,4,2,5,6,5,9,5,0,3,8,8,15,0,17,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, solve(Arg0)); }
	void test_case_6() { int Arr0[] = {0,0,0,3,0,1,3,5,6,8,2,7,1,9,1,5,13,6,3,7,8,4,2,18,12,11,17,13,10,25,11,26,22,32,32,18,35,33,25,31,24,38,41,34,43,42,32,
43,31,35,47,49,36,35,39,42,36,39,47,53,40,61,60,43,47,61,51,56,67,69,53,53,63,56,71,55,76,73,70,74,67,76,64,80,68,85,78,
69,79,73,70,75,77,81,80,94,85,88,88,99,83,99,93,90,85,100,89,96,96,103,107,96,105,95,100,97,97}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9864; verify_case(6, Arg1, solve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheTreeAndMan ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
