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


class PrimeStrings {
	public:
	map<pair<ll,ll>,ll> M[60][60];
	
	ll dp(ll x,ll y,int bx,int by) {
		if(by<0) return (x+1);
		if(M[bx][by].count({x,y})) return M[bx][by][{x,y}];
		
		ll ret=0;
		
		if(bx==by) {
			if(y&(1LL<<by)) {
				if(x&(1LL<<bx)) ret = dp(x^(1LL<<bx),y^(1LL<<by),bx-1,by-1) + (1LL<<bx);
				else ret = x+1;
			}
			else {
				if(x&(1LL<<bx)) ret = dp((1LL<<bx)-1,y,bx-1,by-1);
				else ret = dp(x,y,bx-1,by-1);
			}
		}
		else {
			if(y&(1LL<<by)) {
				if(x&(1LL<<bx)) ret = dp(x^(1LL<<bx),y^(1LL<<by),bx-1,by-1) + dp((1LL<<bx)-1,y,bx-1,by);
				else ret += dp(x,y,bx-1,by);   // take0
			}
			else {
				if(x&(1LL<<bx)) ret += dp((1LL<<bx)-1,y,bx-1,by);   // take0
				else ret += dp(x,y,bx-1,by);   // take0
			}
		}
		M[bx][by][{x,y}] = ret;
		return ret;
	}
	
	long long getCount(long long x, long long y, int k) {
		int bx=0,by=0;
		while((1LL<<bx)<=x) bx++;
		while((1LL<<by)<=y) by++;
		ll ret=0;
		int i,j;
		FOR(i,60) FOR(j,60) M[i][j].clear();
		for(i=1;i<=bx;i++) {
			int t=i-k;
			if(t<by) ret+=min((1LL<<i)-1,x)-((1LL<<(i-1))-1);
			if(t==by) {
				if(i==bx) ret+=dp(x^(1LL<<(bx-1)),y^(1LL<<(by-1)),bx-2,by-2);
				else ret+=dp((1LL<<(i-1))-1,y^(1LL<<(by-1)),i-2,by-2);
			}
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 1LL; int Arg2 = 1; long long Arg3 = 2LL; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 6LL; long long Arg1 = 2LL; int Arg2 = 1; long long Arg3 = 4LL; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 6LL; long long Arg1 = 1LL; int Arg2 = 3; long long Arg3 = 6LL; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 31LL; long long Arg1 = 6LL; int Arg2 = 2; long long Arg3 = 20LL; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 413LL; long long Arg1 = 34LL; int Arg2 = 2; long long Arg3 = 130LL; verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { long long Arg0 = 1000000000LL; long long Arg1 = 1000000000LL; int Arg2 = 5; long long Arg3 = 1000000000LL; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_6() { long long Arg0 = 549755813602LL; long long Arg1 = 8369864093LL; int Arg2 = 5; long long Arg3 = 178429547459LL; verify_case(6, Arg3, getCount(Arg0, Arg1, Arg2)); }
//	void test_case_6() { long long Arg0 = 4LL; long long Arg1 = 1LL; int Arg2 = 1; long long Arg3 = 3LL; verify_case(6, Arg3, getCount(Arg0, Arg1, Arg2)); }
	
// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PrimeStrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
