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

int mo=1000000007;
int dp[15][15][31][15][15][15];
vector<vector<int>> V;

void add(int& a,int&b) {
	a+=b;
	if(a>=mo) a-=mo;
}

class BuffaloBuffaloBuffalo {
	public:
	int count(string P) {
		int N=P.size(),M=N/7;
		
		if(N%7) return 0;
		ZERO(dp);
		
		dp[N/7][0][0][0][0][0]=1;
		FORR(s,P) {
			int a,b,c,d,e,f;
			for(f=M;f>=0;f--) for(e=M-f;e>=0;e--) for(d=M-f-e;d>=0;d--) for(c=2*(M-d-e-f);c>=0;c--) for(b=M-c/2-d-e-f;b>=0;b--) for(a=M-b-c/2-d-e-f;a>=0;a--) {
				int x=dp[a][b][c][d][e][f];
				if(x==0) continue;
				if((s=='b' || s=='?') && a) add(dp[a-1][b+1][c][d][e][f],x);
				if((s=='u' || s=='?') && b) add(dp[a][b-1][c+2][d][e][f],x);
				if((s=='f' || s=='?') && c) {
					if(c%2) add(dp[a][b][c-1][d+1][e][f],x);
					else V.push_back({a,b,c-1,d,e,f,x});
				}
				if((s=='a' || s=='?') && d) add(dp[a][b][c][d-1][e+1][f],x);
				if((s=='l' || s=='?') && e) add(dp[a][b][c][d][e-1][f+1],x);
				if((s=='o' || s=='?') && f) {
					V.push_back({a,b,c,d,e,f-1,x});
				}
				dp[a][b][c][d][e][f]=0;
			}
			FORR(v,V) {
				add(dp[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]],v[6]);
			}
			V.clear();
		}
		return dp[0][0][0][0][0][0];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "buffa????ffalo"; int Arg1 = 6; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "buffal????????"; int Arg1 = 7; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "b??????b??????b??????b??????"; int Arg1 = 1; verify_case(2, Arg1, count(Arg0)); }
//	void test_case_3() { string Arg0 = "???????????????????????????????????"; int Arg1 = 420429295; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = "x"; int Arg1 = 0; verify_case(4, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "???????u??b???????????f??????????????????????????f???????????????????????????"; int Arg1 = 420429295; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BuffaloBuffaloBuffalo ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

