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

int A[101][101];

class UniformingMatrix {
	public:
	string isPossible(vector <string> M) {
		int H=M.size();
		int W=M[0].size();
		int y,x,i;
		
		FOR(i,2) {
			FOR(y,H) FOR(x,W) A[y][x]=M[y][x]=='0';
		
			int R=i,C=0;
			FOR(x,W) A[0][x]^=i;
			
			FOR(x,W) if(A[0][x]) {
				C^=1;
				FOR(y,H) A[y][x]^=1;
			}
			
			for(y=1;y<H;y++) if(A[y][0]) {
				R^=1;
				FOR(x,W) A[y][x]^=1;
			}
			
			if(R!=C) continue;
			int sum=0;
			FOR(y,H) FOR(x,W) sum+=A[y][x];
			if(sum) continue;
			
			return "possible";
		}
		
		return "impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1101",
 "0010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(0, Arg1, isPossible(Arg0)); }
	void test_case_1() { string Arr0[] = {"11111",
 "11111",
 "11111",
 "11111",
 "11111",
 "11111",
 "11111",
 "11111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(1, Arg1, isPossible(Arg0)); }
	void test_case_2() { string Arr0[] = {"110",
 "001",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(2, Arg1, isPossible(Arg0)); }
	void test_case_3() { string Arr0[] = {"01010",
 "10101",
 "01010",
 "01010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(3, Arg1, isPossible(Arg0)); }
	void test_case_4() { string Arr0[] = {"0110011",
 "1011000",
 "0101000",
 "0010001",
 "1010011",
 "1011011",
 "0111100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "impossible"; verify_case(4, Arg1, isPossible(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  UniformingMatrix ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

