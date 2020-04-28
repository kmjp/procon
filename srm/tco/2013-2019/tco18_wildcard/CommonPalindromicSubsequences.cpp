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

int L[2][62][26];
int R[2][62][26];
ll dp[62][62][62][62];

class CommonPalindromicSubsequences {
	int N,M;
	public:
	long long count(string A, string B) {
		int i,j,x;
		int N=A.size();
		int M=B.size();
		FOR(i,26) {
			L[0][0][i]=L[1][0][i]=0;
			R[0][N+1][i]=N+1;
			R[1][M+1][i]=M+1;
		}
		for(i=1;i<=N+1;i++) {
			FOR(x,26) L[0][i][x]=L[0][i-1][x];
			if(i>=2) L[0][i][A[i-2]-'a']=i-1;
		}
		for(i=1;i<=M+1;i++) {
			FOR(x,26) L[1][i][x]=L[1][i-1][x];
			if(i>=2) L[1][i][B[i-2]-'a']=i-1;
		}
		for(i=N;i>=0;i--) {
			FOR(x,26) R[0][i][x]=R[0][i+1][x];
			if(i<N) R[0][i][A[i]-'a']=i+1;
		}
		for(i=M;i>=0;i--) {
			FOR(x,26) R[1][i][x]=R[1][i+1][x];
			if(i<M) R[1][i][B[i]-'a']=i+1;
		}
		
		ZERO(dp);
		ll ret=0;
		dp[0][N+1][0][M+1]=1;
		for(int alen=N+1;alen>=0;alen--) {
			for(int blen=M+1;blen>=0;blen--) {
				for(int AL=0;AL+alen<=N+1;AL++) {
					for(int BL=0;BL+blen<=M+1;BL++) {
						ll d=dp[AL][AL+alen][BL][BL+blen];
						if(d==0) continue;
						if(AL!=0) {
							ret+=d;
							if(alen&&blen) ret+=d;
						}
						FOR(i,26) {
							int nal=R[0][AL][i];
							int nar=L[0][AL+alen][i];
							int nbl=R[1][BL][i];
							int nbr=L[1][BL+blen][i];
							dp[nal][nar][nbl][nbr]+=d;
						}
					}
				}
			}
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abcbac"; string Arg1 = "cacbbda"; long long Arg2 = 10LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "a"; long long Arg2 = 1LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "bc"; string Arg1 = "adea"; long long Arg2 = 0LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abcdefghhgfedcba"; string Arg1 = "badcfehgghefcdab"; long long Arg2 = 160LL; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CommonPalindromicSubsequences ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

