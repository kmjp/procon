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

bitset<640> dp[51];


class CoinFlipping2 {
	public:
	vector <int> correctHeads(vector <string> S, int desiredCount) {
		int H=S.size();
		int W=S[0].size();
		int mask;
		FOR(mask,1<<H) {
			int C[2][50]={};
			dp[0].reset();
			dp[0][0]=1;
			int x,y;
			FOR(x,W) {
				FOR(y,H) if(S[y][x]!='.') {
					if((S[y][x]=='H') == ((mask&(1<<y))==0)) {
						C[0][x]++;
					}
					else {
						C[1][x]++;
					}
				}
				dp[x+1]=(dp[x]<<C[0][x])|(dp[x]<<C[1][x]);
			}
			
			if(dp[W][desiredCount]) {
				vector<int> ret;
				FOR(y,H) if(mask&(1<<y)) ret.push_back(y);
				int cur=desiredCount;
				for(x=W-1;x>=0;x--) {
					if(cur>=C[0][x] && dp[x][cur-C[0][x]]) {
						cur-=C[0][x];
					}
					else {
						assert(cur>=C[1][x] && dp[x][cur-C[1][x]]);
						cur-=C[1][x];
						ret.push_back(H+x);
					}
				}
				return ret;
			}
			
			
		}
		return {-1};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"H.T.H",
 "TTTTT",
 "HHTHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arr2[] = {1, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, correctHeads(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"HT",
 "HH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {-1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, correctHeads(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"HT",
 "HH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, correctHeads(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"T....",
 "...T.",
 "..T..",
 "....T",
 ".T..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arr2[] = {0, 9, 2, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, correctHeads(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CoinFlipping2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

