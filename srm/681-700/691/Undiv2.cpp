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


class Undiv2 {
	public:
	
	long long getsum(int n) {
		int y,x,i;
		ll ret=0;
		for(y=1;y<=26;y++) for(x=1;x<y;x++) {
			ll v=1;
			ll x2=x,y2=y;
			for(i=1;i<y;i++) if(i!=x) v*=i/__gcd(v,(ll)i);
			x2/=__gcd(v,(ll)x);
			y2/=__gcd(v,(ll)y);
			if(v<=n) {
				int num[26*26]={};
				for(i=1;i<=x2*y2;i++) num[i]=num[i-1]+(((i%y2)>0)&&((i%x2)>0));
				ll di=n/v;
				ret += y*(di/(x2*y2)*num[x2*y2] + num[di%(x2*y2)]);
			}
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 3LL; verify_case(0, Arg1, getsum(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 7LL; verify_case(1, Arg1, getsum(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 11LL; verify_case(2, Arg1, getsum(Arg0)); }
	void test_case_3() { int Arg0 = 5; long long Arg1 = 19LL; verify_case(3, Arg1, getsum(Arg0)); }
	void test_case_4() { int Arg0 = 8; long long Arg1 = 32LL; verify_case(4, Arg1, getsum(Arg0)); }
	void test_case_5() { int Arg0 = 13; long long Arg1 = 53LL; verify_case(5, Arg1, getsum(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Undiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
