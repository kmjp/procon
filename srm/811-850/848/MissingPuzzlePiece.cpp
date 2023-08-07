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

class MissingPuzzlePiece {
	public:
	string identify(int R, int C, vector <string> pieces) {
		int vis[20][20]={};
		FORR(a,pieces) {
			int y=a[0]-'A';
			int x=a[1]-'0';
			if(a.size()==3) x=x*10+a[2]-'0';
			vis[y][x-1]=1;
		}
		int y,x;
		FOR(y,R) FOR(x,C) if(vis[y][x]==0) {
			string S;
			S+='A'+y;
			S+=to_string(x+1);
			return S;
		}
		return "";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A1"; verify_case(0, Arg3, identify(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"A1", "B1", "C1", "C2", "C3", "B3", "A3", "A2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "B2"; verify_case(1, Arg3, identify(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"A1", "A2", "A3", "B1", "B3", "C1", "C2", "C3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "B2"; verify_case(2, Arg3, identify(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 12; string Arr2[] = {"A1", "A3", "A5", "A7", "A9", "A2", "A4", "A6", "A8", "A10", "A12"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A11"; verify_case(3, Arg3, identify(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MissingPuzzlePiece ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

