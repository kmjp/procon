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

class MultiplyAddPuzzle {
	public:
	long long minimalSteps(long long s, long long t, long long a, long long b) {
		
		if(s==t) return 0;
		
		if(b<=1) {
			if(b==0 && t==0) return 1;
			if(a) {
				if(s<=t && (t-s)%a==0) return (t-s)/a;
				if(b==0 && t%a==0) return 1+t/a;
			}
			return -1;
		}
		// a>=1, b>=2
		ll mi=1LL<<60;
		ll cur=1,num=0;
		while(1) {
			if(s*cur/cur!=s) break;
			if(s*cur>t) break;
			
			if(t==s*cur) {
				mi=min(mi,num);
			}
			if(a && (t-s*cur)%a==0) {
				ll left=(t-s*cur)/a;
				ll step=num,r=1;
				int i;
				while(r<cur) {
					step += left%b;
					r*=b;
					left/=b;
				}
				step+=left;
				mi=min(mi,step);
			}
			
			if(cur*b>t || cur*b/b!=cur) break;
			cur*=b;
			num++;
		}
		if(mi==1LL<<60) mi=-1;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; long long Arg1 = 40LL; long long Arg2 = 4LL; long long Arg3 = 2LL; long long Arg4 = 2LL; verify_case(0, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = 28LL; long long Arg2 = 4LL; long long Arg3 = 2LL; long long Arg4 = 2LL; verify_case(1, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 10LL; long long Arg1 = 99LL; long long Arg2 = 4LL; long long Arg3 = 2LL; long long Arg4 = -1LL; verify_case(2, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 345LL; long long Arg1 = 12345LL; long long Arg2 = 1LL; long long Arg3 = 10LL; long long Arg4 = 895LL; verify_case(3, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 1000000000000000000LL; long long Arg2 = 1000000000000000000LL; long long Arg3 = 1000000000000000000LL; long long Arg4 = 0LL; verify_case(4, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MultiplyAddPuzzle ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

