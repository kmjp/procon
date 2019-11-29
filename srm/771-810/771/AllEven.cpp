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

ll p10[20];
ll memo[2][2][20][1<<10];

class AllEven {
	public:
	ll hoge(ll v,int lead,int le,int d,int mask) {
		if(d==-1) return lead==0 && mask==0;
		if(memo[lead][le][d][mask]>=0) return memo[lead][le][d][mask];
		
		ll ret=0;
		int i;
		if(le==1) {
			FOR(i,10) {
				if(i==0 && lead) ret+=hoge(v,lead,le,d-1,mask);
				else ret+=hoge(v,0,le,d-1,mask^(1<<i));
			}
		}
		else {
			ll a=v/p10[d]%10;
			if(lead==0) {
				FOR(i,a) ret+=hoge(v,lead,1,d-1,mask^(1<<i));
				ret+=hoge(v,lead,0,d-1,mask^(1<<a));
			}
			else {
				FOR(i,a) {
					if(i==0 && lead==1) ret+=hoge(v,1,1,d-1,mask);
					else ret+=hoge(v,0,1,d-1,mask^(1<<i));
				}
				if(a==0 && lead==1) ret+=hoge(v,1,0,d-1,mask);
				else ret+=hoge(v,0,0,d-1,mask^(1<<a));
				
			}
		}
		
		return memo[lead][le][d][mask]=ret;
	}
	
	long long countInRange(long long lo, long long hi) {
		int i;
		p10[0]=1;
		FOR(i,18) p10[i+1]=p10[i]*10;
		MINUS(memo);
		ll ret=0;
		if(hi>=10) ret+=hoge(hi,1,0,17,0);
		MINUS(memo);
		if(lo>=10) ret-=hoge(lo-1,1,0,17,0);
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 47LL; long long Arg1 = 999LL; long long Arg2 = 5LL; verify_case(0, Arg2, countInRange(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 47LL; long long Arg1 = 1010LL; long long Arg2 = 7LL; verify_case(1, Arg2, countInRange(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 12345678901LL; long long Arg1 = 98765432109LL; long long Arg2 = 0LL; verify_case(2, Arg2, countInRange(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1234LL; long long Arg1 = 654321LL; long long Arg2 = 6862LL; verify_case(3, Arg2, countInRange(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 0LL; long long Arg1 = 10LL; long long Arg2 = 0LL; verify_case(4, Arg2, countInRange(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AllEven ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

