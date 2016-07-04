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

int dp[101][3];
int pe[101];

class TreeAndCycle {
	public:
	int N;
	vector<int> V;
	vector<pair<int,int>> E[101];
	
	int dpdp(int cur,int isopen) {
		if(dp[cur][isopen]>=0) return dp[cur][isopen];
		int& ret = dp[cur][isopen];
		ret=1<<30;
		
		int t=0;
		FORR(e,E[cur]) t+=dpdp(e.first,0);
		ret=t+V[cur]+(isopen?0:V[cur]+pe[cur]);
		
		// both
		if(isopen==0) {
			FORR(e,E[cur]) FORR(e2,E[cur]) if(e!=e2) {
				int t=dpdp(e.first,1)+dpdp(e2.first,1)+pe[cur];
				FORR(e3,E[cur]) if(e!=e3 && e2!=e3) t+=dpdp(e3.first,0);
				ret=min(ret,t);
			}
		}
		FORR(e,E[cur]) {
			int t=dpdp(e.first,1);
			FORR(e2,E[cur]) if(e!=e2) t+=dpdp(e2.first,0);
			ret=min(ret,t+(isopen?0:V[cur]+pe[cur]));
		}
		return ret;
		
	}
	
	int minimize(vector <int> costV, vector <int> pre, vector <int> costE) {
		N=costV.size();
		V=costV;
		int i;
		
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			E[pre[i]].push_back({i+1,costE[i]});
			pe[i+1]=costE[i];
		}
		
		MINUS(dp);
		return min(dpdp(0,0),dpdp(0,1)+V[0]);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7,2,5,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,4,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 15; verify_case(0, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100,5,9,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 32; verify_case(1, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {10,20,30,40,50,60,70,80,90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,2,3,4,5,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,15,25,35,45,55,65,75}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 205; verify_case(2, Arg3, minimize(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TreeAndCycle ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
