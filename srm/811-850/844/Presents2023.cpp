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



class Presents2023 {
	public:
	long long pack(long long paperArea) {
		ll P=paperArea/2;
		ll V=0;
		while(P>=3) {
			ll ma=0,mv=0;
			ll B=sqrt(P/3);
			for(ll a=max(B-10000,1LL);a<=B+10000;a++) {
				for(ll b=a;a*b+b*b+b*a<=P;b++) {
					ll c=(P-a*b)/(a+b);
					ll na=a*b+b*c+c*a;
					if(a*b*c>mv) {
						mv=a*b*c;
						ma=na;
					}
				}
			}
			V+=mv;
			P-=ma;
		}
		
		return V;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 605LL; long long Arg1 = 1000LL; verify_case(0, Arg1, pack(Arg0)); }
	void test_case_1() { long long Arg0 = 366LL; long long Arg1 = 451LL; verify_case(1, Arg1, pack(Arg0)); }
	void test_case_2() { long long Arg0 = 887LL; long long Arg1 = 1734LL; verify_case(2, Arg1, pack(Arg0)); }
	void test_case_3_() { long long Arg0 = 888LL; long long Arg1 = 1728LL; verify_case(3, Arg1, pack(Arg0)); }
	void test_case_3() { long long Arg0 = 10000000000000LL; long long Arg1 = 1728LL; verify_case(3, Arg1, pack(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Presents2023 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

