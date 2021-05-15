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

class GalleryIllumination {
	public:
	int countDarkCells(int R, int C, vector <string> floorPlan) {
		int y,x;
		FOR(y,R) {
			int on=0;
			FOR(x,C) {
				if(floorPlan[y][x]=='O') on=1;
				if(floorPlan[y][x]=='.'&&on) floorPlan[y][x]='*';
				if(floorPlan[y][x]=='#') on=0;
			}
			on=0;
			for(x=C-1;x>=0;x--) {
				if(floorPlan[y][x]=='O') on=1;
				if(floorPlan[y][x]=='.'&&on) floorPlan[y][x]='*';
				if(floorPlan[y][x]=='#') on=0;
			}
		}
		FOR(x,C) {
			int on=0;
			FOR(y,R) {
				if(floorPlan[y][x]=='O') on=1;
				if(floorPlan[y][x]=='.'&&on) floorPlan[y][x]='*';
				if(floorPlan[y][x]=='#') on=0;
			}
			on=0;
			for(y=R-1;y>=0;y--) {
				if(floorPlan[y][x]=='O') on=1;
				if(floorPlan[y][x]=='.'&&on) floorPlan[y][x]='*';
				if(floorPlan[y][x]=='#') on=0;
			}
		}
		int rem=0;
		FOR(y,R) FOR(x,C) if(floorPlan[y][x]=='.') rem++;
		
		return rem;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; string Arr2[] = {"....",
 "....",
 "...."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(0, Arg3, countDarkCells(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 5; string Arr2[] = {".....",
 ".O...",
 ".....",
 "....."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(1, Arg3, countDarkCells(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 5; string Arr2[] = {".....",
 ".OO..",
 ".....",
 "....."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(2, Arg3, countDarkCells(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 5; string Arr2[] = {".....",
 ".O#..",
 ".#.O.",
 "....."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(3, Arg3, countDarkCells(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 5; string Arr2[] = {".....",
 ".O...",
 "...O.",
 "....."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(4, Arg3, countDarkCells(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {"O"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(5, Arg3, countDarkCells(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GalleryIllumination ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

