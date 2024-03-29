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

class TigerRiverCrossing {
	public:
	vector <string> addRocks(vector <string> river, int maxL) {
		vector<pair<int,int>> V;
		int H=river.size();
		int W=river[0].size();
		int x,y,s;
		FOR(x,W) {
			for(s=1;s<=maxL;s++) {
				FOR(y,s) {
					int fail=0;
					for(int y2=y;y2<H;y2+=s) fail+=river[y2][x]=='=';
					V.push_back({fail,x*10000+s*100+y});
				}
			}
		}
		sort(ALL(V));
		int tx=V[0].second/10000;
		int step=V[0].second/100%100;
		for(y=V[0].second%100;y<H;y+=step) river[y][tx]='O';
		return river;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"===============",
 "========O======",
 "===============",
 "========O======",
 "=O=============",
 "========O======",
 "===============",
 "========O======",
 "===============",
 "========O======"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arr2[] = {"===============", "========O======", "===============", "========O======", "=O=============", "========O======", "===============", "========O======", "===============", "========O======" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, addRocks(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"===============",
 "========O======",
 "===============",
 "========O======",
 "=O=============",
 "========O======",
 "===============",
 "========O======",
 "===============",
 "========O======"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arr2[] = {"========O======", "========O======", "========O======", "========O======", "=O======O======", "========O======", "========O======", "========O======", "========O======", "========O======" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, addRocks(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"===============",
 "========O======",
 "===============",
 "========O======",
 "=O=============",
 "===============",
 "===============",
 "========O======",
 "===============",
 "========O======"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arr2[] = {"===============", "========O======", "===============", "========O======", "=O=============", "========O======", "===============", "========O======", "===============", "========O======" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, addRocks(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"===============",
 "========O======",
 "===============",
 "========O======",
 "=O=============",
 "===============",
 "===============",
 "========O======",
 "===============",
 "========O======"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; string Arr2[] = {"===============", "========O======", "===============", "========O======", "=O=============", "===============", "===============", "========O======", "===============", "========O======" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, addRocks(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"===============",
 "===============",
 "========O======",
 "===============",
 "==============="}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; string Arr2[] = {"===============", "===============", "========O======", "===============", "===============" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, addRocks(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"===============",
 "===============",
 "===============",
 "===============",
 "==============="}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; string Arr2[] = {"===============", "===============", "O==============", "===============", "===============" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, addRocks(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"===============",
 "===============",
 "===============",
 "===============",
 "==============="}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; string Arr2[] = {"===============", "===============", "===============", "===============", "===============" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, addRocks(Arg0, Arg1)); }
	void test_case_7() { string Arr0[] = {"===============",
 "===============",
 "====O==========",
 "===============",
 "====O==========",
 "===============",
 "===============",
 "====O==========",
 "==============="}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arr2[] = {"===============", "====O==========", "====O==========", "===============", "====O==========", "===============", "===============", "====O==========", "===============" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(7, Arg2, addRocks(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TigerRiverCrossing ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

