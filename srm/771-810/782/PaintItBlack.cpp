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

vector<int> E[1010];
int did[1010];
vector<int> GL,R,V;
int col[1010];
int D[1010];
int turn;

class PaintItBlack {
	public:
	
	int dfs(int cur,int pre) {
		if(did[cur]==1) {
			if(GL.empty() && D[cur]==D[pre]) {
				int i;
				for(i=V.size()-1;i>=0;i--) {
					GL.push_back(V[i]);
					if(V[i]==cur) break;
				}
			}
			return 0;
		}
		col[cur]^=1;
		did[cur]=1;
		V.push_back(cur);
		R.push_back(cur);
		if(cur!=pre) D[cur]=D[pre]^1;
		
		if(turn==1 && cur==GL.back()) {
			FORR(g,GL) R.push_back(g), col[g]^=1;
		}

		FORR(e,E[cur]) if(e!=pre) {
			int r=dfs(e,cur);
			if(r) {
				R.push_back(cur);
				col[cur]^=1;
				if(col[e]==0) {
					R.push_back(e);
					R.push_back(cur);
					col[e]^=1;
					col[cur]^=1;
				}
			}
		}
		V.pop_back();
		return 1;
	}
	
	vector <int> findWalk(int n, int u, vector <int> a, vector <int> b) {
		int i;
		FOR(i,n) E[i].clear();
		GL.clear();
		
		FOR(i,a.size()) E[a[i]].push_back(b[i]),E[b[i]].push_back(a[i]);
		
		ZERO(col);
		ZERO(D);
		ZERO(did);
		R.clear();
		V.clear();
		turn=0;
		col[u]=1;
		dfs(u,u);
		cout<<col[u]<<endl;
		if(col[u]==0) {
			if(GL.empty()) return {};
			ZERO(col);
			R.clear();
			V.clear();
			ZERO(D);
			ZERO(did);
			turn=1;
			col[u]=1;
			dfs(u,u);
			assert(col[u]==1);
			
		}
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, findWalk(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 0; int Arr2[] = {0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, findWalk(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arr2[] = {0, 1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2, 3, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 3, 0, 1, 2 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, findWalk(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PaintItBlack ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

