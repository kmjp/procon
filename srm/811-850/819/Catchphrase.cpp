#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class Catchphrase {
	public:
	int reconstruct(int A, int B) {
		if(A%100) return -1;
		if(B%100) return -1;
		A/=100;
		B/=100;
		int a1,b1,a2,b2,s1,s2;
		int ret=-1;
		for(a1=0;a1<=9;a1++) {
			for(a2=0;a1+a2<=9;a2++) {
				for(b1=0;b1<=9;b1++) {
					for(b2=0;b1+b2<=9;b2++) {
						FOR(s1,2) {
							FOR(s2,2) {
								int sa=a1+b1*2+(s1==0)*5+(s2==0)*10;
								int sb=a2+b2*2+(s1==1)*5+(s2==1)*10;
								if(A-sa<0||B-sb<0||(A-sa)%5||(B-sb)%5) continue;
								int na=a1+b1+(s1==0)+(s2==0)+(A-sa)/5;
								ret=max(ret,na);
							}
						}
					}
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 900; int Arg1 = 900; int Arg2 = -1; verify_case(0, Arg2, reconstruct(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 47; int Arg1 = 1953; int Arg2 = -1; verify_case(1, Arg2, reconstruct(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1800; int Arg1 = 0; int Arg2 = 5; verify_case(2, Arg2, reconstruct(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1100; int Arg1 = 2000; int Arg2 = 10; verify_case(3, Arg2, reconstruct(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 4300; int Arg1 = 1100; int Arg2 = 19; verify_case(4, Arg2, reconstruct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Catchphrase ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

