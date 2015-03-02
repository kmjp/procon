#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;

class FoxConnection4 {
	public:
	set<set<pair<int,int> > > S[9];
	int howManyWays(vector <string> board, int k) {
		int i,j,x,y;
		set<pair<int,int> > ts;
		ts.insert(make_pair(0,0));
		S[1].insert(ts);
		
		for(i=1;i<=k-1;i++) {
			ITR(it,S[i]) {
				set<pair<int,int> > s=*it;
				
				ITR(it2,s) {
					int cx=it2->first,cy=it2->second;
					FOR(j,4) {
						int dd[4]={1,0,-1,0};
						int tx=cx+dd[j],ty=cy+dd[j^1];
						if(s.count(make_pair(tx,ty))) continue;
						set<pair<int,int> > s2;
						int dx=(tx<0),dy=(ty<0);
						s2.insert(make_pair(tx+dx,ty+dy));
						ITR(it3,s) s2.insert(make_pair(it3->first+dx,it3->second+dy));
						S[i+1].insert(s2);
					}
				}
				
			}
		}
		
		ll ret=0;
		int H=board.size(), W=board[0].size();
		ITR(it,S[k]) {
			set<pair<int,int> > s=*it;
			int mx=0,my=0;
			ITR(it2,s) mx=max(mx,it2->first+1), my=max(my,it2->second+1);
			FOR(y,H-my+1) FOR(x,W-mx+1) {
				int ok=1;
				ITR(it2,s) if(board[y+it2->second][x+it2->first]=='#') ok=0;
				ret += ok;
			}
		}
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(0, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".#.#",
 "#.#.",
 ".#.#",
 "#.#."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(1, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"##.",
 "...",
 ".##"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(2, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"....",
 "....",
 "....",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 113; verify_case(3, Arg2, howManyWays(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".....#....",
 ".#........",
 "....#.##..",
 "#......#..",
 "....#.....",
 "..........",
 ".##....#..",
 "..##......",
 "........##",
 "......#.#."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 22369; verify_case(4, Arg2, howManyWays(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxConnection4 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
