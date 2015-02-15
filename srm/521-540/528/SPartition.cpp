#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

//-------------------------------------------------------

ll dpdp[2][41][41];

class SPartition {
	public:
	long long getCount(string s) {
		int L=s.size();
		int i,x,y,mask;
		ll ret=0;
		
		FOR(mask,1<<(L/2)) {
			if(__builtin_popcount(mask)*2!=count(s.begin(),s.end(),'o')) continue;
			ZERO(dpdp);
			dpdp[0][0][0]=1;
			ll tot=0;
			FOR(i,L) {
				int cur=i%2,tar=cur^1;
				ZERO(dpdp[tar]);
				tot=0;
				FOR(x,min(i+1,L/2+1)) FOR(y,min(i+1,L/2+1)) if(dpdp[cur][x][y]) {
					tot+=dpdp[cur][x][y];
					if(x<L/2 && ((mask>>x)&1)==(s[i]=='o')) dpdp[tar][x+1][y]+=dpdp[cur][x][y];
					if(y<L/2 && ((mask>>y)&1)==(s[i]=='o')) dpdp[tar][x][y+1]+=dpdp[cur][x][y];
				}
				if(tot==0) break;
			}
			if(tot) ret += dpdp[L%2][L/2][L/2];
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "oxox"; long long Arg1 = 2LL; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { string Arg0 = "oooxxx"; long long Arg1 = 0LL; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { string Arg0 = "xoxxox"; long long Arg1 = 4LL; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { string Arg0 = "xo"; long long Arg1 = 0LL; verify_case(3, Arg1, getCount(Arg0)); }
	void test_case_4() { string Arg0 = "ooooxoox"; long long Arg1 = 8LL; verify_case(4, Arg1, getCount(Arg0)); }
	void test_case_52() { string Arg0 = "ooxxoxox"; long long Arg1 = 8LL; verify_case(5, Arg1, getCount(Arg0)); }
	void test_case_5() { string Arg0 = "ooxxooxxooxxooxxooxxooxxooxxooxxoooooxxo"; long long Arg1 = 8LL; verify_case(5, Arg1, getCount(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SPartition ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
