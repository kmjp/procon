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

class TaroJiroGrid {
	public:
	int N;
	int okok(vector <string*> G) {
		int y,x;
		FOR(x,N) {
			int c=1;
			for(y=1;y<N;y++) {
				if((*G[y])[x]!=(*G[y-1])[x]) c=0;
				if(++c>N/2) return 0;
			}
		}
		return 1;
	}
	
	int getNumber(vector <string> G) {
		int a,b,c,i;
		N=G.size();
		string BB="BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
		string WW="WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW";
		
		vector <string*> G2;
		FOR(a,N) G2.push_back(&G[a]);
		
		if(okok(G2)) return 0;
		
		FOR(a,N) {
			G2[a]=&BB;
			if(okok(G2)) return 1;
			G2[a]=&WW;
			if(okok(G2)) return 1;
			G2[a]=&G[a];
		}
		return 2;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"WB",
 "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arr0[] = {"WB",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arr0[] = {"WB",
 "WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arr0[] = {"WBBW",
 "WBWB",
 "WWBB",
 "BWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arr0[] = {"WBBWBB",
 "BBWBBW",
 "WWBWBW",
 "BWWBBB",
 "WBWBBW",
 "WWWBWB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TaroJiroGrid ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
