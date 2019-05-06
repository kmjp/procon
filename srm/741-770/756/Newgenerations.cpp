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

ll mo=1000000007;
ll p2[5050];
vector<int> L;

class Newgenerations {
	public:
	int count(vector <string> S) {
		int H=S.size(),W=S[0].size();
		vector<vector<int>> V;
		int x,y,i,j;
		int numf=0;
		
		p2[0]=1;
		FOR(x,5000) p2[x+1]=p2[x]*2%mo;
		
		FOR(y,H) FOR(x,W) {
			if(S[y][x]=='x') {
				S[y][x]='#';
				V.push_back({y,x});
			}
			if(S[y][x]=='*') numf++;
		}
		ll ret=0;
		int N=V.size(),mask;
		FOR(mask,1<<N) {
			int NG=0;
			L.clear();
			FOR(i,N) if(mask&(1<<i)) {
				FOR(j,4) {
					int dd[4]={1,0,-1,0};
					int ty=V[i][0]+dd[j];
					int tx=V[i][1]+dd[j^1];
					if(ty<0 || ty>=H || tx<0 || tx>=W) {
						NG=1;
					}
					else if(S[ty][tx]=='.') {
						NG=1;
					}
					else if(S[ty][tx]=='*') {
						L.push_back(ty*50+tx);
					}
				}
			}
			if(NG) continue;
			sort(ALL(L));
			L.erase(unique(ALL(L)),L.end());
			if(__builtin_popcount(mask)%2==0) {
				ret+=p2[numf-L.size()];
			}
			else {
				ret+=mo-p2[numf-L.size()];
			}
		}
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"x*"
,"*#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"##."
,".#."
,".##"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"#.......#.......#"
,"##.....###.....##"
,"###...#####...###"
,"####.x#####x.####"
,"####xxx###xxx####"
,"###xx*******xx###"
,"##x***********x##"
,"#***************#"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 134217728; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"#****#*#*****#******"
,"#****#..*.#*#*.*x.#*"
,"****#**#**##*****#**"
,"*##***#*##x*x***#x*x"
,"****#*#*****#*****#*"
,".**###*#**x*.*###**x"
,"*#**##*.**#****x**.*"
,"#************.***#**"
,"*******#*#****#***.*"
,"*#.***##**.**##.#*##"
,"*.##****.****#.****x"
,"*.*#****#*##*#***.#*"
,"###x#*.***#x***#***#"
,"#*.**#**#*******#.**"
,"****#x***##x*.##.*#*"
,"*###*###****.**#****"
,"*.*#*****###****##**"
,"*#*#**.*#*x*##**#***"
,"*##*******#x#**#****"
,"***##*******#*******"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 961436185; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Newgenerations ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

