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



class TwoCatsAndAMouse {
	public:
	string catchMouse(int R, int C) {
		int cy1,cy2,my;
		int cx1,cx2,mx;
		string S;
		FOR(cy1,R) FOR(cx1,C) FOR(cy2,R) FOR(cx2,C) FOR(my,R) FOR(mx,C) {
			int p1=0;
			int p2=0;
			
			//c1ÇÕêÊÇ…y
			if(cy1<my) p1=2;
			else if(cy1>my) p1=1;
			else if(cx1<mx) p1=4;
			else if(cx1>mx) p1=3;
			else continue;
			//c2ÇÕêÊÇ…x
			if(cx2<mx) p2=4;
			else if(cx2>mx) p2=3;
			else if(cy2<my) p2=2;
			else if(cy2>my) p2=1;
			else continue;
			
			int ch=65+p1*5+p2;
			S.push_back(ch);
			
		}
		
		return S;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "UKOKCUEUKCKPNKPKPDEUFUFJUFBFPDPBFIFP"; verify_case(0, Arg2, catchMouse(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 1; string Arg2 = "KMMMMCMMMKCMMKBCMKLBCKLLBKMMMFKMMMFCMMFKCMFKBCFKLBFKMMBKMMGFKMMGFCMGFKCGFKBCFKMBFKMGBKMGGFKMGGFCGGFKCHFKBCFKGBFKGGBKGGGFKGGGFCHHFBCHFGBCFGGBFGGGBGGGGF"; verify_case(1, Arg2, catchMouse(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TwoCatsAndAMouse ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

