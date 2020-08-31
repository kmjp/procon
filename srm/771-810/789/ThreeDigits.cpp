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

ll modpow(ll a, ll n,ll mo) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class ThreeDigits {
	public:
	string calculate(int X, int Y, int Z) {
		
		ll a=modpow(X,Y,Z*1000);
		char buf[256];
		sprintf(buf,"%.12lf",(a%Z)*1.0/Z);
		string S=to_string(a/Z)+(buf+1);
		
		if(exp(log(X)*Y-log(Z))>999) S="00000"+S;
		
		int i,j;
		string T;
		FOR(i,S.size()) {
			if(S[i]=='.') {
				for(j=max(0,i-3);j<=i+3;j++) T+=S[j];
				return T;
			}
		}
		return "";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 7; string Arg3 = "34.714"; verify_case(0, Arg3, calculate(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 32; string Arg3 = "512.000"; verify_case(1, Arg3, calculate(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 36; string Arg3 = "0.250"; verify_case(2, Arg3, calculate(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 47; string Arg3 = "51.085"; verify_case(3, Arg3, calculate(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 13; int Arg1 = 6; int Arg2 = 479; string Arg3 = "076.845"; verify_case(4, Arg3, calculate(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1234; int Arg1 = 56789; int Arg2 = 123456; string Arg3 = "133.942"; verify_case(5, Arg3, calculate(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 999999999; int Arg1 = 128; int Arg2 = 1000000; string Arg3 = "000.000"; verify_case(6, Arg3, calculate(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ThreeDigits ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

