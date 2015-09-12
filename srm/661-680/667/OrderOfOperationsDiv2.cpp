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

int cost[1<<21];

class OrderOfOperationsDiv2 {
	public:
	int minTime(vector <string> s) {
		int val[51]={},tot=0;
		int N=s.size();
		int M=s[0].size();
		int i,j,k;
		FOR(i,N) {
			FOR(j,M) if(s[i][j]=='1') val[i] |= 1<<j;
			tot |= val[i];
		}
		FOR(i,1<<M) cost[i]=1<<20;
		cost[0]=0;
		
		for(int mask=0;mask<tot;mask++) if(cost[mask]<1<<20) {
			int cur=__builtin_popcount(mask);
			FOR(i,N) {
				int mask2=mask | val[i];
				if(mask!=mask2) {
					int tar=__builtin_popcount(mask2);
					cost[mask2]=min(cost[mask2],cost[mask]+(tar-cur)*(tar-cur));
				}
			}
			
		}
		return cost[tot];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
 "111",
 "001",
 "010"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { string Arr0[] = {
 "11101",
 "00111",
 "10101",
 "00000",
 "11000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { string Arr0[] = {
  "11111111111111111111"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 400; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { string Arr0[] = {
  "1000",
  "1100",
  "1110"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minTime(Arg0)); }
	void test_case_4() { string Arr0[] = {
  "111",
  "111",
  "110",
  "100"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, minTime(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OrderOfOperationsDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
