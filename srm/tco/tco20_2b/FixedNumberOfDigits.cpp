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



class FixedNumberOfDigits {
	public:
	long long sum(int start, int step, long long numberOfDigits) {
		p10[0]=1;
		int i;
		int len=1;
		FOR(i,18) {
			p10[i+1]=p10[i]*10;
			if(start>=p10[i+1]) len=i+2;
		}
		ll cur=start;
		while(1) {
			ll nex=p10[len];
			ll num=(nex-cur+step-1)/step;
			if(num*len<numberOfDigits) {
				numberOfDigits-=num*len;
				cur+=num*step;
				len++;
				continue;
			}
			numberOfDigits--;
			ll s=numberOfDigits/len;
			cur+=s*step;
			numberOfDigits-=s*len;
			return cur/p10[len-1-numberOfDigits];
		}
		return -1;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 47; int Arg1 = 10; long long Arg2 = 7LL; long long Arg3 = 7LL; verify_case(0, Arg3, sum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 98; int Arg1 = 1; long long Arg2 = 10LL; long long Arg3 = 101LL; verify_case(1, Arg3, sum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 1; long long Arg2 = 7LL; long long Arg3 = 6LL; verify_case(2, Arg3, sum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 123456789; int Arg1 = 10; long long Arg2 = 5LL; long long Arg3 = 12345LL; verify_case(3, Arg3, sum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 123456789; int Arg1 = 10; long long Arg2 = 17LL; long long Arg3 = 12345679LL; verify_case(4, Arg3, sum(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FixedNumberOfDigits ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

