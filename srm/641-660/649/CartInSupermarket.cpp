#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class CartInSupermarket {
	public:
	
	ll numdiv(ll L,ll T) {
		if(L<=T) return 1;
		for(int i=1;i<=29;i++) {
			if(1LL<<i > L) break;
			if(T<=i+1) break;
			ll a=(L-(1<<i));
			ll b=T-(i+1);
			ll N=(a+b-1)/b;
			if(N>(1<<(i-1)) && N<=1<<i) return N;
		}
		return 1LL<<30;
	}
	
	ll tdiv(int v,vector <int> a) {
		ll tot=0;
		ITR(it,a) tot += numdiv(*it,v)-1;
		return tot;
	}
	
	int calcmin(vector <int> a, int b) {
		sort(a.begin(),a.end());
		ll ret=(1LL<<30)-1,i;
		for(i=29;i>=0;i--) if(tdiv(ret-(1<<i),a)<=b) ret -= 1<<i;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; verify_case(0, Arg2, calcmin(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {6,6,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; verify_case(1, Arg2, calcmin(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12,5,6,2,6,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 6; verify_case(2, Arg2, calcmin(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {15,20,11,13,18,24,25,21,22,10,15,14,19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 25; verify_case(3, Arg2, calcmin(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {671122748,846444748,84701624,608579554,672060899,967957440,31438849,734849843,376589643,904285209
,80693344,211737743,85405464,444633541,293184188,935462519,146753109,972886045,496631016,601669536
,257574086,958464570,6294570,546189534,668105964,601197313,784337929,921840143,70408284,722040626
,253400894,56411549,811940644,152086353,122638884,776352066,118932182,177589709,538122558,127914469
,523761221,290027568,734517444,819458123,699130727,784698122,810265337,283326309,593596316,368671876}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6478; int Arg2 = 3805054; verify_case(4, Arg2, calcmin(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CartInSupermarket ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
