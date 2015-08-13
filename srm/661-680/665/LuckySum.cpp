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


class LuckySum {
	public:
	long long construct(string note) {
		int i,x,y;
		ll p10[15];
		ll dp[16][2][3];
		
		p10[0]=1;
		FOR(i,14) p10[i+1]=p10[i]*10;
		FOR(i,16) FOR(x,2) FOR(y,3) dp[i][x][y]=1LL<<60;
		
		dp[0][0][2]=0;
		int L=note.size();
		int c,o;
		
		FOR(i,L) {
			char tar=note[L-1-i];
			
			FOR(c,2) FOR(o,3) if(dp[i][c][o]<1LL<<60) {
				ll v=dp[i][c][o];
				if(o>=2) {
					if(tar=='?' || tar==c+4+4+'0')      dp[i+1][0][2]=min(dp[i+1][0][2],v+8*p10[i]);
					if(tar=='?' || tar==(c+4+7)%10+'0') dp[i+1][1][2]=min(dp[i+1][1][2],v+11*p10[i]);
					if(tar=='?' || tar==(c+7+7)%10+'0') dp[i+1][1][2]=min(dp[i+1][1][2],v+14*p10[i]);
				}
				if(i) {
					if(o>=1) {
						if(tar=='?' || tar==c+4+'0') dp[i+1][0][1]=min(dp[i+1][0][1],v+4*p10[i]);
						if(tar=='?' || tar==c+7+'0') dp[i+1][0][1]=min(dp[i+1][0][1],v+7*p10[i]);
					}
					if(i==L-1 && c!=0) if(tar=='?' || tar==c+'0') dp[i+1][0][0]=min(dp[i+1][0][0],v);
				}
			}
		}
		ll ret=min(dp[L][0][0],min(dp[L][0][1],dp[L][0][2]));
		if(ret>=1LL<<60) ret=-1;
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "?"; long long Arg1 = 8LL; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { string Arg0 = "?1"; long long Arg1 = 11LL; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { string Arg0 = "4?8"; long long Arg1 = 448LL; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { string Arg0 = "2??"; long long Arg1 = -1LL; verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { string Arg0 = "??????????????"; long long Arg1 = 11888888888888LL; verify_case(4, Arg1, construct(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LuckySum ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
