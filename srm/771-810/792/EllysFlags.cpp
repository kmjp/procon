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

int from[1<<20];
int to[1<<20];

// G0,G1,G2,W

class EllysFlags {
	public:
	int getMax(vector <string> paper) {
		int H=paper.size();
		int W=paper[0].size();
		
		int i,mask;
		FOR(i,1<<20) from[i]=-101010;
		from[0]=0;
		int y,x;
		FOR(y,H) FOR(x,W) {
			FOR(i,1<<20) to[i]=-101010;
			FOR(mask,1<<(2*W)) {
				int cm=(mask>>(2*x))&3;
				int pm=(x?((mask>>(2*(x-1)))&3):4);
				int nmask=mask^(cm<<(2*x));
				int v=from[mask];
				if(paper[y][x]=='W') {
					to[nmask|(3<<(2*x))]=max(to[nmask|(3<<(2*x))],v);
				}
				if(paper[y][x]=='W'||paper[y][x]=='G') {
					int nv=0;
					if(cm==3) nv++;
					if(pm==3) nv++;
					to[nmask|(nv<<(x*2))]=max(to[nmask|(nv<<(x*2))],v);
				}
				if(paper[y][x]=='W'||paper[y][x]=='R') {
					int ok=0;
					if(cm<3) ok+=cm;
					if(pm<3) ok+=pm;
					to[nmask]=max(to[nmask],v+ok);
				}
				
			}
			swap(to,from);
		}
		
		int ma=0;
		FOR(mask,1<<(2*W)) ma=max(ma,from[mask]);
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"WGWWR",
 "GRGRG",
 "RWGRW",
 "GGWGR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(0, Arg1, getMax(Arg0)); }
	void test_case_1() { string Arr0[] = {"WWGRWW",
 "WWWWWW",
 "WWRGWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(1, Arg1, getMax(Arg0)); }
	void test_case_2() { string Arr0[] = {"WWGGRGWGGW",
 "WWRWRGWWRG",
 "GGWRWRRWRW",
 "WWRRWWWWGR",
 "WWGWWGRWGR",
 "WWGWRRWWWR",
 "WRGWWGWGWW",
 "WWRGWRWGGW",
 "WWRRWWGWRW",
 "WRGWRRRGWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; verify_case(2, Arg1, getMax(Arg0)); }
	void test_case_3() { string Arr0[] = {"WWWWWWW",
 "WWWWWWW",
 "WWWWWWW",
 "WWWWWWW",
 "WWWWWWW",
 "WWWWWWW",
 "WWWWWWW",
 "WWWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 56; verify_case(3, Arg1, getMax(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysFlags ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

