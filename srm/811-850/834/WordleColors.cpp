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

class WordleColors {
	public:
	string color(string hidden, string guess) {
		string r="-----";
		int x,y;
		FOR(x,5) if(hidden[x]==guess[x]) {
			r[x]='g';
			hidden[x]=guess[x]='-';
		}
		FOR(x,5) FOR(y,5) if(hidden[x]!='-'&&hidden[x]==guess[y]) {
			r[y]='y';
			hidden[x]=guess[y]='-';
		}
		return r;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BLOCK"; string Arg1 = "BRICK"; string Arg2 = "g--gg"; verify_case(0, Arg2, color(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BLOCK"; string Arg1 = "BLOBS"; string Arg2 = "ggg--"; verify_case(1, Arg2, color(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BLURB"; string Arg1 = "BOBBY"; string Arg2 = "g-y--"; verify_case(2, Arg2, color(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABBOT"; string Arg1 = "BOBBY"; string Arg2 = "yyg--"; verify_case(3, Arg2, color(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "CANAL"; string Arg1 = "AAAAA"; string Arg2 = "-g-g-"; verify_case(4, Arg2, color(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "GREEN"; string Arg1 = "BLACK"; string Arg2 = "-----"; verify_case(5, Arg2, color(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "RATES"; string Arg1 = "STARE"; string Arg2 = "yyyyy"; verify_case(6, Arg2, color(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WordleColors ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

