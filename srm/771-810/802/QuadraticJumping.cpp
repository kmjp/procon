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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int ok[10101];

class QuadraticJumping {
	public:
	long long jump(long long goal) {
		
		ZERO(ok);
		ok[0]=1;
		int i,j;
		for(i=1;i<=100;i++) {
			for(j=10000-i*i;j>=0;j--) ok[j+i*i]|=ok[j];
		}
		
		for(i=1;i<=10000000;i++) {
			ll sum=1LL*i*(i+1)*(2*i+1)/6;
			
			if(sum>=goal&&(sum-goal)%2==0) {
				ll dif=(sum-goal)/2;
				if(dif>=10000||ok[dif]) return i;
			}
		}
		return 0;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 14LL; long long Arg1 = 3LL; verify_case(0, Arg1, jump(Arg0)); }
	void test_case_1() { long long Arg0 = 28LL; long long Arg1 = 4LL; verify_case(1, Arg1, jump(Arg0)); }
	void test_case_2() { long long Arg0 = 7LL; long long Arg1 = 6LL; verify_case(2, Arg1, jump(Arg0)); }
	void test_case_3() { long long Arg0 = 333383335000LL; long long Arg1 = 10000LL; verify_case(3, Arg1, jump(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  QuadraticJumping ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

