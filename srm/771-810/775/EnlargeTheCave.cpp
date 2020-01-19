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

class EnlargeTheCave {
	public:
	vector <string> enlarge(vector <string> S, int desiredArea) {
		int H=S.size(), W=S[0].size();
		int y,x;
		queue<int> Q;
		FOR(y,H) FOR(x,W) {
			if(S[y][x]=='K') {
				if(y&&S[y-1][x]=='#') S[y-1][x]='k';
				if(x&&S[y][x-1]=='#') S[y][x-1]='k';
				if(y+1<H&&S[y+1][x]=='#') S[y+1][x]='k';
				if(x+1<W&&S[y][x+1]=='#') S[y][x+1]='k';
			}
			if(S[y][x]=='.') {
				desiredArea--;
				Q.push(y*100+x);
			}
		}
		while(Q.size() && desiredArea) {
			int cy=Q.front()/100;
			int cx=Q.front()%100;
			Q.pop();
			int i;
			FOR(i,4) if(desiredArea) {
				int dd[4]={0,1,0,-1};
				int ty=cy+dd[i];
				int tx=cx+dd[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(S[ty][tx]=='#') {
					desiredArea--;
					S[ty][tx]='.';
					Q.push(ty*100+tx);
				}
			}
		}
		if(desiredArea) return {};
		FOR(y,H) FOR(x,W) if(S[y][x]=='k') S[y][x]='#';
		return S;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {".##",
 "###",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; string Arr2[] = {"...", "..#", "..#" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, enlarge(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".##",
 "##K",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; string Arr2[] = {"..#", ".#K", "..#" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, enlarge(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".##",
 "##K",
 "###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, enlarge(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"###K########",
 "#.#K########",
 "..#K########",
 "############"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, enlarge(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"###############",
 "###############",
 "##K###..####K##",
 "######..#######",
 "###############",
 "##K#########K##",
 "###############",
 "###############"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 82; string Arr2[] = {"...............", "..#.........#..", ".#K#.......#K##", "###.........###", "###.........###", "##K#.......#K##", "###.........###", "#............##" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, enlarge(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"#K#K###..###K#K##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arr2[] = {"#K#K#......#K#K##" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, enlarge(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"....",
 "....",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; string Arr2[] = {"....", "....", "...." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, enlarge(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EnlargeTheCave ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

