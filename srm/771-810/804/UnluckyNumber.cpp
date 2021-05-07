#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


vector<int> E[20];
const ll mo=1000000007;
int vis[20];

class UnluckyNumber {
	public:
	
	int dfs(int cur,int col) {
		if(vis[cur]!=-1) {
			return col!=vis[cur];
		}
		vis[cur]=col;
		int ret=0;
		FORR(e,E[cur]) ret|=dfs(e,col^1);
		return ret;
	}
	
	int numberOfColourings(int n, int m, int k, int z, vector <int> x, vector <int> y) {
		ZERO(E);
		
		int i;
		ll ret=0;
		int mask;
		FOR(mask,1<<m) {
			FOR(i,n) E[i].clear(), vis[i]=-1;
			FOR(i,m) if(mask&(1<<i)) {
				E[x[i]-1].push_back(y[i]-1);
				E[y[i]-1].push_back(x[i]-1);
			}
			ll pat=1;
			FOR(i,n) if(vis[i]==-1) {
				if(E[i].size()==0) {
					pat=pat*k%mo;
				}
				else if(dfs(i,0)) {
					if(z%2) pat=0;
				}
				else {
					if(z<=k+1) pat=pat*(z-1)%mo;
					else pat=pat*(2*k+1-z)%mo;
					
				}
			}
			
			if(__builtin_popcount(mask)%2) {
				ret+=mo-pat;
			}
			else {
				ret+=pat;
			}
		}
		return ret%mo;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 5; int Arg3 = 2; int Arr4[] = {1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {2}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 24; verify_case(0, Arg6, numberOfColourings(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 5; int Arg3 = 2; int Arr4[] = {}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 3125; verify_case(1, Arg6, numberOfColourings(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  UnluckyNumber ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

