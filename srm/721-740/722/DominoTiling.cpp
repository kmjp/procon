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

ll from[1<<14];
ll to[1<<14];
vector<int> cand[1<<14];


class DominoTiling {
	public:
	int H,W;
	void dfs(int cm,int nm,int d) {
		if(d==W) {
			cand[cm].push_back(nm);
			return;
		}
		// non
		dfs(cm,nm,d+1);
		// yoko
		if(d+2<=W) dfs(cm|(3<<d),nm,d+2);
		// tate
		dfs(cm|(1<<d),nm|(1<<d),d+1);
	}
	long long count(vector <string> S) {
		int x,y,i,mask;
		H=S.size();
		W=S[0].size();
		
		FOR(mask,1<<W) cand[mask].clear();
		dfs(0,0,0);
		
		ZERO(from);
		ZERO(to);
		
		from[0]=1;
		FOR(y,H) {
			int bmask=0;
			FOR(x,W) if(S[y][x]=='X') bmask|=1<<x;
			ZERO(to);
			FOR(mask,1<<W) if(from[mask]) {
				if(mask&bmask) continue;
				int left=((1<<W)-1) ^ (mask|bmask);
				FORR(c,cand[left]) to[c]+=from[mask];
			}
			
			swap(from,to);
		}
		
		
		
		return from[0];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"...",
 ".X.",
 "..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"...",
 "...",
 "..X"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {".....",
 ".....",
 ".X...",
 ".X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 29LL; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DominoTiling ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

