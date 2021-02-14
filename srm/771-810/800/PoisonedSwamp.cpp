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

int dp[20][20];

class PoisonedSwamp {
	public:
	string cross(vector <string> swamp) {
		int H=swamp.size();
		int W=swamp[0].size();
		MINUS(dp);
		dp[0][0]=9;
		priority_queue<pair<int,int>> Q;
		Q.push({9,0});
		while(Q.size()) {
			int cur=Q.top().first;
			int cy=Q.top().second/100;
			int cx=Q.top().second%100;
			if(cy==H-1&&cx==W-1) return "possible";
			Q.pop();
			if(dp[cy][cx]!=cur) continue;
			int i;
			FOR(i,4) {
				int dd[4]={1,0,-1,0};
				int ty=cy+dd[i];
				int tx=cx+dd[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(swamp[ty][tx]=='#') continue;
				int tar=cur;
				if(swamp[ty][tx]=='S') tar=9;
				if(swamp[ty][tx]>='1'&&swamp[ty][tx]<='9') tar=cur-(swamp[ty][tx]-'0');
				if(tar<0) continue;
				if(dp[ty][tx]<tar) {
					dp[ty][tx]=tar;
					Q.push({tar,ty*100+tx});
				}
			}
		}
		return "impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 "####.",
 ".....",
 ".####",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(0, Arg1, cross(Arg0)); }
	void test_case_1() { string Arr0[] = {".....",
 "####.",
 "97...",
 "9#2##",
 "97..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(1, Arg1, cross(Arg0)); }
	void test_case_2() { string Arr0[] = {".111111111.",
 ".#########.",
 "..22222...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(2, Arg1, cross(Arg0)); }
	void test_case_3() { string Arr0[] = {".#222#111",
 "4#S#2#1#S",
 "4#3#S#1#9",
 "S33#111#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(3, Arg1, cross(Arg0)); }
	void test_case_4() { string Arr0[] = {"..111111111111..",
 "###############."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "impossible"; verify_case(4, Arg1, cross(Arg0)); }
	void test_case_5() { string Arr0[] = {"..111111111111..",
 "#######S#######."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(5, Arg1, cross(Arg0)); }
	void test_case_6() { string Arr0[] = {"..#.#.",
 "..#.#.",
 "#5#.5.",
 "....#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "impossible"; verify_case(6, Arg1, cross(Arg0)); }
	void test_case_7() { string Arr0[] = {".1.#.",
 ".9.#.",
 ".###.",
 "2#.1.",
 ".#.7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "impossible"; verify_case(7, Arg1, cross(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PoisonedSwamp ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

