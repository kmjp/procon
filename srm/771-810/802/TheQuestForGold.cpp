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

int vis[51][51];

class TheQuestForGold {
	public:
	string explore(vector <string> cave) {
		int H=cave.size();
		int W=cave[0].size();
		int y,x;
		ZERO(vis);
		queue<int> Q;
		FOR(y,H) FOR(x,W) if(cave[y][x]=='S') {
			vis[y][x]=1;
			Q.push(y*100+x);
		}
		FOR(y,H) FOR(x,W) if(cave[y][x]=='P') {
			if(y&&cave[y-1][x]=='.') cave[y-1][x]='*';
			if(y+1<H&&cave[y+1][x]=='.') cave[y+1][x]='*';
			if(x&&cave[y][x-1]=='.') cave[y][x-1]='*';
			if(x+1<W&&cave[y][x+1]=='.') cave[y][x+1]='*';
			if(y&&cave[y-1][x]=='S') return "no gold";
			if(y+1<H&&cave[y+1][x]=='S') return "no gold";
			if(x&&cave[y][x-1]=='S') return "no gold";
			if(x+1<W&&cave[y][x+1]=='S') return "no gold";
		}
		
		while(Q.size()) {
			int cy=Q.front()/100;
			int cx=Q.front()%100;
			Q.pop();
			if(cave[cy][cx]=='T') return "gold";
			int i;
			int d[4]={0,-1,0,1};
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty>=0&&ty<H&&tx>=0&&tx<W&&cave[ty][tx]!='P'&&cave[ty][tx]!='*'&&vis[ty][tx]==0) {
					vis[ty][tx]=1;
					Q.push(ty*100+tx);
				}
			}
		}
		return "no gold";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"S....",
 ".....",
 "...T.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "gold"; verify_case(0, Arg1, explore(Arg0)); }
	void test_case_1() { string Arr0[] = {"S....",
 "...P.",
 "..PTP",
 "...P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "no gold"; verify_case(1, Arg1, explore(Arg0)); }
	void test_case_2() { string Arr0[] = {"S....",
 "..P.P",
 ".P.T.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "no gold"; verify_case(2, Arg1, explore(Arg0)); }
	void test_case_3() { string Arr0[] = {"S....",
 "P....",
 "...T.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "no gold"; verify_case(3, Arg1, explore(Arg0)); }
	void test_case_4() { string Arr0[] = {"S....",
 ".....",
 "PPP..",
 ".....",
 ".....",
 ".....",
 "..PPP",
 "..T.."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "gold"; verify_case(4, Arg1, explore(Arg0)); }
	void test_case_5() { string Arr0[] = {".......",
 ".......",
 "..P.P..",
 "..PPP..",
 "..P.P..",
 ".......",
 "..S...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "no gold"; verify_case(5, Arg1, explore(Arg0)); }
	void test_case_6() { string Arr0[] = {".......",
 ".......",
 "..P.P..",
 "..PTP..",
 "..P.P..",
 ".......",
 "..S...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "no gold"; verify_case(6, Arg1, explore(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheQuestForGold ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

