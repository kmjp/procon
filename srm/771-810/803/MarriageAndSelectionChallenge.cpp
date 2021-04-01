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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int nex[3030][12];
int dp[3030][1<<12];
int to[3030][1<<12];

class MarriageAndSelectionChallenge {
	public:
	string solve(string S) {
		int N=S.size();
		int i,j,mask;
		
		FORR(c,S) c-='a';
		FOR(i,12) nex[N][i]=N;
		FOR(i,1<<12) FOR(j,N+2) dp[j][i]=-1<<20;
		FOR(i,1<<12) dp[N][i]=0;
		
		MINUS(to);
		
		for(i=N-1;i>=0;i--) {
			FOR(j,12) nex[i][j]=nex[i+1][j];
			nex[i][S[i]]=i;
			
			FOR(j,12) {
				int t=nex[i+1][j];
				FOR(mask,1<<12) if(dp[t][mask]>=0) {
					if(S[i]!=j && mask&(1<<S[i])) continue;
					int nmask=mask|(1<<S[i]);
					if(dp[i][nmask]<dp[t][mask]+1) {
						dp[i][nmask]=dp[t][mask]+1;
						to[i][nmask]=j;
					}
				}
			}
		}
		
		int ma=-1;
		int cur=-1;
		FOR(i,N) if(dp[i][(1<<12)-1]>ma || (dp[i][(1<<12)-1]==ma && S[i]<S[cur])) {
			ma=dp[i][(1<<12)-1];
			cur=i;
		}
		
		string T;
		int c=cur;
		int m=(1<<12)-1;
		while(c<N) {
			T.push_back(S[c]+'a');
			i=to[c][m];
			if(S[c]!=i) m^=1<<S[c];
			c=nex[c+1][i];
		}
		
		return T;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "kick"; string Arg1 = "ick"; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arg0 = "cccaaccc"; string Arg1 = "cccccc"; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arg0 = "ccaaccc"; string Arg1 = "aaccc"; verify_case(2, Arg1, solve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MarriageAndSelectionChallenge ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

