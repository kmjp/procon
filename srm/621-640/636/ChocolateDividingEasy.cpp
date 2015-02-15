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

int S[60][60];
class ChocolateDividingEasy {
	public:
	int sum(int x1,int y1,int x2,int y2) {
		return S[y2][x2]-S[y1][x2]-S[y2][x1]+S[y1][x1];
	}
	
	int findBest(vector <string> C) {
		int H=C.size(), W=C[0].size();
		int x,y,mi=0;
		ZERO(S);
		FOR(y,H) {
			FOR(x,W) S[y+1][x+1]=S[y+1][x]+C[y][x]-'0';
			FOR(x,W) S[y+1][x+1]+=S[y][x+1];
		}
		int x1,x2,y1,y2;
		for(y1=1;y1<=H;y1++) for(y2=y1+1;y2<=H;y2++) {
			for(x1=1;x1<W;x1++) for(x2=x1+1;x2<=W;x2++) {
				int v=99999999;
				v=min(v,sum(0,0,x1,y1));
				v=min(v,sum(x1,0,x2,y1));
				v=min(v,sum(x2,0,W,y1));
				v=min(v,sum(0,y1,x1,y2));
				v=min(v,sum(x1,y1,x2,y2));
				v=min(v,sum(x2,y1,W,y2));
				v=min(v,sum(0,y2,x1,H));
				v=min(v,sum(x1,y2,x2,H));
				v=min(v,sum(x2,y2,W,H));
				mi=max(mi,v);
			}
		}
		return mi;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"9768",
"6767",
"5313"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, findBest(Arg0)); }
	void test_case_1() { string Arr0[] = {
"36753562",
"91270936",
"06261879",
"20237592",
"28973612",
"93194784"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(1, Arg1, findBest(Arg0)); }
	void test_case_2() { string Arr0[] = {
"012",
"345",
"678"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, findBest(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChocolateDividingEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
