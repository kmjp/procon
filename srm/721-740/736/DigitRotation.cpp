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

ll mo=998244353;
ll p10[551];

class DigitRotation {
	public:
	int sumRotations(string X) {
		int N=X.size();
		int i;
		p10[0]=1;
		FOR(i,501) p10[i+1]=p10[i]*10%mo;
		ll tot=0;
		FOR(i,N) {
			X[i]-='0';
			tot=(tot*10+X[i])%mo;
		}
		
		int a,b,c;
		ll ret=0;
		FOR(c,N) FOR(b,c) {
			FOR(a,b) {
				if(a==0 && X[c]==0) continue;
				ret += tot;
				ret -= X[a]*p10[N-1-a];
				ret -= X[b]*p10[N-1-b];
				ret -= X[c]*p10[N-1-c];
				ret += X[c]*p10[N-1-a];
				ret += X[a]*p10[N-1-b];
				ret += X[b]*p10[N-1-c];
			}
			ret=(ret%mo+mo)%mo;
		}
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123"; int Arg1 = 312; verify_case(0, Arg1, sumRotations(Arg0)); }
	void test_case_1() { string Arg0 = "3570"; int Arg1 = 10407; verify_case(1, Arg1, sumRotations(Arg0)); }
	void test_case_2() { string Arg0 = "5545"; int Arg1 = 21208; verify_case(2, Arg1, sumRotations(Arg0)); }
	void test_case_3() { string Arg0 = "1283749218734901238749213847902"; int Arg1 = 867286291; verify_case(3, Arg1, sumRotations(Arg0)); }
	void test_case_4() { string Arg0 = "4"; int Arg1 = 0; verify_case(4, Arg1, sumRotations(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DigitRotation ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

