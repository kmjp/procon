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

class CoinFlipping {
	public:
	int mostHeads(vector <string> S) {
		int H=S.size();
		int W=S[0].size();
		int mask;
		int ma=0;
		FOR(mask,1<<H) {
			int x,y;
			int pat=0;
			FOR(x,W) {
				int C[2]={};
				FOR(y,H) if(S[y][x]!='.') {
					if((S[y][x]=='H') == ((mask&(1<<y))==0)) {
						C[0]++;
					}
					else {
						C[1]++;
					}
				}
				pat+=max(C[0],C[1]);
			}
			ma=max(ma,pat);
		}
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"H.T.H",
 "TTTTT",
 "HHTHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, mostHeads(Arg0)); }
	void test_case_1() { string Arr0[] = {"TT",
 "HT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, mostHeads(Arg0)); }
	void test_case_2() { string Arr0[] = {"T....",
 "...T.",
 "..T..",
 "....T",
 ".T..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, mostHeads(Arg0)); }
	void test_case_3() { string Arr0[] = {"HT.HT.HT.HT.",
 ".HT.HT.HT.HT",
 "T.HT.HT.HT.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(3, Arg1, mostHeads(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CoinFlipping ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

