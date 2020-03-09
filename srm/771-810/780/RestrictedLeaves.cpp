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

int N;
vector <int> P;
vector<int> E[1010];

ll dp[1010][8];
const ll mo=1000000007;

class RestrictedLeaves {
	public:
	void dfs2(int cur) {
		if(E[cur].empty()) return;
		sort(ALL(E[cur]));
		int i;
		ll from[8]={};
		FOR(i,E[cur].size()) {
			int e=E[cur][i];
			dfs2(e);
			ll to[8]={};
			
			int x,y;
			if(i==0) {
				if(E[e].empty()) {
					to[0]=to[1]=to[6]=1;
				}
				else {
					FOR(x,8) {
						(to[x&6]+=dp[e][x])%=mo;
						if((x&1)==0) (to[x^1]+=dp[e][x])%=mo;
					}
				}
			}
			else {
				if(E[e].empty()) {
					FOR(x,8) {
						(to[x&3]+=from[x])%=mo;
						if((x&1)==0 && (x&4)==0) (to[x^4]+=from[x])%=mo;
					}
					
				}
				else {
					FOR(x,8) {
						FOR(y,8) {
							if((x&1)&&(y&1)) continue;
							if((x&4)&&(y&2)) continue;
							int z=(x&1)|(x&2)|(y&4);
							(to[z]+=from[x]*dp[e][y])%=mo;
						}
					}
				}
			}
			
			swap(from,to);
		}
		FOR(i,8) dp[cur][i]=from[i];
		
	}
	
	int count(vector <int> parent) {
		P=parent;
		N=P.size();
		int i;
		FOR(i,N) E[i].clear();
		FOR(i,N) if(i) E[P[i]].push_back(i);
		ZERO(dp);
		dfs2(0);
		ll ret=0;
		FOR(i,8) if((i&2)==0 || (i&4)==0) ret+=dp[0][i];
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {-1, 0, 0, 1, 2, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {-1, 0, 0, 1, 2, 1, 2, 1, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 75; verify_case(2, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RestrictedLeaves ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

