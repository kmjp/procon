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

int H,W;
vector<string> S;

int nim[51][51];

class LightbulbGame {
	public:
	int countWinningMoves(vector <string> board) {
		S=board;
		H=S.size();
		W=S[0].size();
		
		int i,x,y;
		for(y=1;y<=H;y++) {
			for(x=1;x<=W;x++) {
				set<int> S;
				nim[y][x]=0;
				S.insert(0);
				for(i=1;i<y;i++) S.insert(nim[i][x]);
				for(i=1;i<x;i++) S.insert(nim[y][i]);
				while(S.count(nim[y][x])) nim[y][x]++;
			}
		}
		
		int tot=0;
		for(y=1;y<=H;y++) {
			for(x=1;x<=W;x++) {
				if(S[H-y][W-x]=='1') tot^=nim[y][x];
			}
		}
		
		int ret=0;
		for(y=1;y<=H;y++) {
			for(x=1;x<=W;x++) if(S[H-y][W-x]=='1') {
				tot^=nim[y][x];
				if(tot==0) ret++;
				for(int x2=1;x2<x;x2++) if(nim[y][x2]==tot) ret++;
				for(int y2=1;y2<y;y2++) if(nim[y2][x]==tot) ret++;
				tot^=nim[y][x];
			}
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000",
 "000",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, countWinningMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"0000",
 "0100",
 "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, countWinningMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"00000",
 "01001",
 "00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countWinningMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"10",
 "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, countWinningMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"1111",
 "1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, countWinningMoves(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LightbulbGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

