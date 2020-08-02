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

class RectangularObstacle {
	public:
	long long countReachable(int x1, int x2, int y1, int y2, int s) {
		ll ret=0;
		
		// 0 - -s
		ret += 1LL*(s+1)*(s+1);
		ll y;
		for(y=1;y<=y2;y++) {
			if(y<y1) {
				if(y<=s) {
					ret+=1+(s-y)*2;
				}
			}
			else {
				int x=s-y;
				if(x>x2) ret+=x-x2;
				if(-x<x1) ret+=x-(-x1);
			}
		}
		
		ll L=s-(y2+1)-(-x1+1);
		ll R=s-(y2+1)-(x2+1);
		ll D=x2-x1+1;
		if(L>R) swap(L,R);
		cout<<L<<" "<<R<<" "<<D<<endl;
		if(L<0 && R>=0) {
			ret+=1LL*(R+1)*(R+1);
		}
		else if(L>=0) {
			ret+=1LL*(R+1)*(R+1);
			ret+=1LL*(L+1)*(L+1);
			ll C=R+L-D;
			if(C>0) {
				if(C%2==1) {
					C=(C+1)/2;
					ret-=1LL*C*C;
				}
				else {
					C/=2;
					ret-=1LL*C*(C+1);
				}
			}
		}
		
		
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = -5; int Arg1 = 5; int Arg2 = 3; int Arg3 = 3; int Arg4 = 2; long long Arg5 = 13LL; verify_case(0, Arg5, countReachable(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = -5; int Arg1 = 5; int Arg2 = 3; int Arg3 = 3; int Arg4 = 3; long long Arg5 = 24LL; verify_case(1, Arg5, countReachable(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = -4; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 6; long long Arg5 = 61LL; verify_case(2, Arg5, countReachable(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 4; long long Arg5 = 38LL; verify_case(3, Arg5, countReachable(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void _test_case_4() { int Arg0 = -100; int Arg1 = 100; int Arg2 = 42; int Arg3 = 47; int Arg4 = 0; long long Arg5 = 1LL; verify_case(4, Arg5, countReachable(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = -400000; int Arg1 = 100000; int Arg2 = 200000; int Arg3 = 300000; int Arg4 = 800000; long long Arg5 = 1LL; verify_case(4, Arg5, countReachable(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RectangularObstacle ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

