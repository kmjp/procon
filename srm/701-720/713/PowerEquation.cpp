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

ll mo=1000000007;
int pat[101010];
ll num[35][35];

class PowerEquation {
	public:
	int count(int n) {
		ZERO(pat);
		ZERO(num);
		int left=max(0,n-100000);
		
		
		int i,x,y;
		for(i=2;i<=min(n,100000);i++) if(pat[i]==0) {
			int mul=1;
			ll j=i;
			while(j*i<=n) {
				j*=i;
				mul++;
				if(j<=100000) pat[j]++;
				else left--;
			}
			for(x=1;x<=mul;x++) for(y=1;y<=mul;y++) num[x][y]++;
		}
		
		num[1][1]+=left;
		
		ll ret=1LL*n*n%mo;
		for(x=1;x<=34;x++) for(y=1;y<=34;y++) if(num[x][y]) {
			int g=__gcd(x,y);
			int a=max(x,y)/g;
			ret += (n/a)*num[x][y]%mo;
		}
		
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 6; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 15; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 21620; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 22306; int Arg1 = 68467; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PowerEquation ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

