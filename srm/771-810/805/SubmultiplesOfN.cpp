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

ll dp[5050][1010];
const ll mo=1000000007;
int nex[5050][10];

class SubmultiplesOfN {
	public:
	int count(string B, int N) {
		int i,j,x;
		int L=B.size();
		FOR(i,10) nex[L][i]=L;
		for(i=L-1;i>=0;i--) {
			FOR(j,10) nex[i][j]=nex[i+1][j];
			nex[i][B[i]-'0']=i;
		}
		
		ZERO(dp);
		dp[0][0]=1;
		ll ret=0;
		FOR(i,L) FOR(j,N) FOR(x,10) if(nex[i][x]!=L) {
			if(i==0&&x==0) continue;
			(dp[nex[i][x]+1][(j*10+x)%N]+=dp[i][j])%=mo;
			if((j*10+x)%N==0) (ret+=dp[i][j])%=mo;
		}
		
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1111111111"; int Arg1 = 7; int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "12345678"; int Arg1 = 2; int Arg2 = 170; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1357913579135791357913579"; int Arg1 = 2; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "1122334455"; int Arg1 = 6; int Arg2 = 20; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "1020402"; int Arg1 = 24; int Arg2 = 6; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "123456789012345678901234567890"; int Arg1 = 1; int Arg2 = 62224120; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SubmultiplesOfN ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

