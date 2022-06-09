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

class AddFlowers {
	public:
	vector <string> add(vector <string> lawn) {
		int H=lawn.size();
		int W=lawn[0].size();
		int y,x;
		FOR(y,H) FOR(x,W) if(lawn[y][x]=='F') {
			vector<int> Y={y,y+1};
			if(Y.back()==H) Y.back()=y-1;
			vector<int> X={x,x+1};
			if(X.back()==W) X.back()=x-1;
			FORR(x2,X) FORR(y2,Y) if(lawn[y2][x2]=='.') lawn[y2][x2]='G';
		}
		FOR(y,H) FOR(x,W) if(lawn[y][x]=='G') lawn[y][x]='F';
		return lawn;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"..........",
 "...FFFF...",
 "..FF......",
 "..F...F...",
 "..FFFFF...",
 ".........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..........", "...FFFF...", "..FF..F...", "..F...F...", "..FFFFF...", ".........." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, add(Arg0)); }
	void test_case_1() { string Arr0[] = {"F.F.F.",
 ".F.F.F",
 "F.F.F."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"FFFFFF", "FFFFFF", "FFFFFF" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, add(Arg0)); }
	void test_case_2() { string Arr0[] = {"..........",
 "...FFFF...",
 "..FF.FFF..",
 "..F.F.F...",
 "..FF.FF...",
 "....F....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..........", "...FFFFF..", "..FF.FFF..", "..FFF.FF..", "..FFFFF...", "...FF....." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, add(Arg0)); }
	void test_case_3() { string Arr0[] = {"......",
 "......"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"......", "......" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, add(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AddFlowers ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

