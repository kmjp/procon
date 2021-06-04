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

class AlternateOddEven {
	public:
	
	long long kth(long long K) {
		int i,d,j,k;
		ll p10[20];
		ll p5[20];
		p10[0]=p5[0]=1;
		FOR(i,19) {
			p10[i+1]=p10[i]*10;
			p5[i+1]=p5[i]*5;
		}
		
		for(d=1;d<=19;d++) {
			for(i=1;i<=9;i++) {
				if(K<=p5[d-1]) {
					ll ret=i*p10[d-1];
					int tar=(i%2)^1;
					for(j=d-1;j>=1;j--) {
						for(k=tar;k<10;k+=2) {
							if(K<=p5[j-1]) {
								ret+=k*p10[j-1];
								break;
							}
							K-=p5[j-1];
						}
						tar^=1;
					}
					return ret;
				}
				K-=p5[d-1];
			}
		}
		
		
		return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 9LL; long long Arg1 = 9LL; verify_case(0, Arg1, kth(Arg0)); }
	void test_case_1() { long long Arg0 = 15LL; long long Arg1 = 21LL; verify_case(1, Arg1, kth(Arg0)); }
	void test_case_2() { long long Arg0 = 60LL; long long Arg1 = 125LL; verify_case(2, Arg1, kth(Arg0)); }
	void test_case_3() { long long Arg0 = 100LL; long long Arg1 = 290LL; verify_case(3, Arg1, kth(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AlternateOddEven ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

