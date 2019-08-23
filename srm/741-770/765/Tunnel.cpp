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

class Tunnel {
	public:
	int minKeystrokes(vector <string> level, int rate) {
		int from[50],to[50];
		int H=level.size(),W=level[0].size();
		int x,y;
		FOR(x,W) from[x]=level[0][x]=='v'?0:101010;
		
		FOR(y,H-1) {
			FOR(x,W) to[x]=101010;
			FOR(x,W-1) if(from[x]<100000) {
				for(int x2=x;x2<W && level[y][x2]!='#'&&x2-x<=rate;x2++) {
					if(level[y+1][x2]=='.') to[x2]=min(to[x2],from[x]+x2-x);
				}
				for(int x2=x;x2>=0 && level[y][x2]!='#'&&x-x2<=rate;x2--) {
					if(level[y+1][x2]=='.') to[x2]=min(to[x2],from[x]+x-x2);
				}
			}
			swap(from,to);
		}
		
		int mi=101010;
		FOR(x,W) mi=min(mi,from[x]);
		if(mi>=101000) mi=-1;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"##..v..##",
 "###.....#",
 "#####...#",
 "####...##",
 "###..####",
 "#.......#",
 "#...#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, minKeystrokes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"#.v.#",
 "##..#",
 "###.#",
 "#...#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = -1; verify_case(1, Arg2, minKeystrokes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"#v....#",
 "###...#",
 "#####.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(2, Arg2, minKeystrokes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"#v....#",
 "###...#",
 "#####.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(3, Arg2, minKeystrokes(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#...v.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arg2 = 0; verify_case(4, Arg2, minKeystrokes(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Tunnel ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

