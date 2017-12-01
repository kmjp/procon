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

class OrAndSumEasy {
	public:
	string isPossible(long long O, long long S) {
		vector<long long> pairOr={O};
		vector<long long> pairSum={S};
		int N=pairSum.size();
		int i,j,k;
		
		for(i=0;i<=60;i++) {
			FOR(j,2) {
				int prev=j;
				FOR(k,N) {
					int cur=prev^(pairSum[k]&1);
					if((cur|prev)!=(pairOr[k]&1)) break;
					prev=cur;
				}
				if(k==N) {
					prev=j;
					FOR(k,N) {
						int cur=prev^(pairSum[k]&1);
						pairOr[k]>>=1;
						pairSum[k]-=prev+cur;
						pairSum[k]>>=1;
						prev=cur;
					}
					break;
				}
			}
			if(j==2) return "Impossible";
		}
		return "Possible";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 7LL; long long Arg1 = 11LL; string Arg2 = "Possible"; verify_case(0, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 11LL; long long Arg1 = 7LL; string Arg2 = "Impossible"; verify_case(1, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 999799115789631487LL; long long Arg1 = 999999999999999999LL; string Arg2 = "Possible"; verify_case(2, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 100LL; string Arg2 = "Impossible"; verify_case(3, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 0LL; long long Arg1 = 0LL; string Arg2 = "Possible"; verify_case(4, Arg2, isPossible(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OrAndSumEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

