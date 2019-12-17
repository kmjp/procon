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

string decdec(string A) {
	for(int i=A.size()-1;i>=0;i--) {
		if(A[i]--!='0') break;
		A[i]='9';
	}
	A=A.substr(A[0]=='0');
	if(A.empty()) A="0";
	return A;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


class AntiprimeNumbers {
	public:
	ll po(string N,int D) {
		ll p=0;
		FORR(c,N) {
			p=(p*10+(c-'0'))%(mo-1);
		}
		return modpow(D,p);
	}
	
	int countAntiPrimes(string N, int D) {
		
		if(D>=8) D=3;
		else if(D>=6) D=2;
		else if(D>=4) D=1;
		else D=0;
		
		if(D==0) {
			if(N=="1") return 1;
			else return 0;
		}
		
		if(N=="1") {
			return D+1;
		}
		
		ll ret=po(N,D);
		N=decdec(N);
		ret+=po(N,D);
		if(D==3) {
			N=decdec(N);
			ret+=po(N,D);
		}
		
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "61214027451155456631310754220433707056704675307344311"; int Arg1 = 7; int Arg2 = 328754822; verify_case(0, Arg2, countAntiPrimes(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1"; int Arg1 = 5; int Arg2 = 2; verify_case(1, Arg2, countAntiPrimes(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "2"; int Arg1 = 4; int Arg2 = 2; verify_case(2, Arg2, countAntiPrimes(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "2"; int Arg1 = 3; int Arg2 = 0; verify_case(3, Arg2, countAntiPrimes(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AntiprimeNumbers ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

