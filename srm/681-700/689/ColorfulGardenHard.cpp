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

ll dp[1<<16][16];
ll mo=1000000007;

class ColorfulGardenHard {
	public:
	int count(string G, string F) {
		int i,j;
		int N = G.size();
		
		sort(G.begin(),G.end());
		ZERO(dp);
		
		FOR(i,N) if((i==0 || G[i]!=G[i-1]) && G[i]!=F[0]) dp[1<<i][i]=1;
		for(int mask=1;mask<1<<N;mask++) {
			int num=__builtin_popcount(mask);
			FOR(i,N) if((mask&(1<<i)) && dp[mask][i]) {
				FOR(j,N) {
					if(mask&(1<<j)) continue;
					if(G[i]==G[j]) continue;
					if(j&&G[j]==G[j-1]&&((mask&(1<<(j-1)))==0)) continue;
					if(F[num]==G[j]) continue;
					(dp[mask | (1<<j)][j] += dp[mask][i])%=mo;
				}
			}
		}
		ll tot=0;
		FOR(i,N) tot += dp[(1<<N)-1][i];
		return tot%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaabbb"; string Arg1 = "cccccc"; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aabbcc"; string Arg1 = "aabbcc"; int Arg2 = 5; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "aaaabb"; string Arg1 = "xxxxxx"; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abcdefghijklmno"; string Arg1 = "zzzzzzzzzzzzzzz"; int Arg2 = 674358851; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "a"; string Arg1 = "b"; int Arg2 = 1; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ColorfulGardenHard ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
