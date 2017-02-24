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

int S[1<<15][64];

class Xscoregame {
	public:
	int getscore(vector <int> A) {
		int N=A.size();
		int i,j;
		
		MINUS(S);
		S[0][0]=0;
		
		int mask,ret=0;
		for(int mask=0;mask<(1<<N);mask++) {
			FOR(j,64) if(S[mask][j]>=0) {
				ret = max(ret,S[mask][j]);
				
				FOR(i,N) if((mask&(1<<i))==0) {
					int mask2=mask|(1<<i);
					int nv=S[mask][j]+(S[mask][j]^A[i]);
					
					S[mask2][nv&63]=max(S[mask2][nv&63],nv);
				}
			}
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, getscore(Arg0)); }
	void test_case_1() { int Arr0[] = {10,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 80; verify_case(1, Arg1, getscore(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getscore(Arg0)); }
	void test_case_3() { int Arr0[] = {1,0,1,0,1,0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 170; verify_case(3, Arg1, getscore(Arg0)); }
	void test_case_5() { int Arr0[] = {1,4,7,6,2,4,8,9,7,1,5,3,1,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 830122; verify_case(4, Arg1, getscore(Arg0)); }
	void test_case_4() { int Arr0[] = {50,0,1,0,1,0,1,0,1,0,1,0,1,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 830122; verify_case(4, Arg1, getscore(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Xscoregame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

