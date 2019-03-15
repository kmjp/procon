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

int nex[65][25];
vector<vector<int>> V[6];
map<vector<int>,int> id;
ll dp[62][20200];

class PurpleSubsequences {
	public:
	long long count(vector <int> A, int L) {
		int N=A.size();
		int i,j,x;
		
		
		V[0].clear();
		V[0].push_back(vector<int>());
		FOR(i,L-1) {
			V[i+1].clear();
			FORR(v,V[i]) {
				for(j=(v.empty()?1:min(20,v.back()+1));j<=20;j++) {
					v.push_back(j);
					V[i+1].push_back(v);
					v.pop_back();
				}
			}
		}
		sort(ALL(V[L-1]));
		
		id.clear();
		FOR(i,V[L-1].size()) id[V[L-1][i]]=i;
		
		FOR(i,22) nex[N+1][i]=N+1;
		for(i=N;i>=0;i--) {
			FOR(j,21) nex[i][j]=nex[i+1][j];
			if(i<N) nex[i][A[i]]=i+1;
		}
		
		ZERO(dp);
		int T=V[L-1].size();
		dp[0][T-1]=1;
		ll ret=0;
		int x;
		
		FOR(i,N+1) {
			FOR(j,T) if(dp[i][j]) {
				for(x=1;x<=20;x++) if(nex[i][x]<=N) {
					vector<int> CV=V[L-1][j];
					int y=lower_bound(ALL(CV),x)-CV.begin();
					
					if(y==L-1) {
						dp[nex[i][x]][T]+=dp[i][j];
					}
					else {
						CV[y]=x;
						dp[nex[i][x]][id[CV]]+=dp[i][j];
					}
				}
			}
			ret+=dp[i][T];
			for(x=1;x<=20;x++) dp[nex[i][x]][T]+=dp[i][T];
		}
		
		
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4,7,4,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 11LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,2,2,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 8LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long long Arg2 = 17LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 17LL; verify_case(2, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PurpleSubsequences ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

