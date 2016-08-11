#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int ma[1<<20];
int id[20][20];

class Clicountingd2 {
	public:
	int count(vector <string> g) {
		int N=g.size();
		int M=0;
		MINUS(id);
		int i,j,x,y,mask;
		FOR(y,N) FOR(x,y) if(g[x][y]=='?') id[x][y]=id[y][x]=M++;
		
		ZERO(ma);
		FOR(mask,1<<N) {
			int yes=1;
			int nm=0;
			FOR(y,N) FOR(x,y) if((mask&(1<<x)) && (mask&(1<<y))) {
				if(g[y][x]=='0') yes=0;
				if(g[y][x]=='?') nm |= 1<<id[y][x];
			}
			if(yes==0) continue;
			ma[nm] = max(ma[nm], __builtin_popcount(mask));
		}
		FOR(i,M) FOR(mask,1<<M) if(mask&(1<<i)) ma[mask] = max(ma[mask], ma[mask^(1<<i)]);
		return accumulate(ma,ma+(1<<M),0);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"0?","?0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"011","101","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"0?1","?01","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"0???","?0??","??0?","???0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 151; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Clicountingd2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
