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

int DB[10]={1,0,0,0,0,0,1,0,2,1};

ll p10[23];
ll dp1[23][23];
ll dp2[23][23];

class EnclosedArea {
	public:
	long long construct(int E, int N) {
		int i,d,x;
		
		ZERO(dp1);
		ZERO(dp2);
		p10[0]=1;
		dp1[0][0]=dp2[0][0]=1;
		for(i=0;i<=15;i++) {
			p10[i+1]=p10[i]*10;
			FOR(d,10) {
				FOR(x,21) {
					dp1[x+DB[d]][i+1]+=dp1[x][i];
					if(d) {
						dp2[x+DB[d]][i+1]+=dp1[x][i];
					}
					else {
						dp2[x][i+1]+=dp2[x][i];
					}
				}
			}
		}
		if(E==0) N++;
		
		ll cur=0;
		N++;
		for(d=15;d>=0;d--) {
			FOR(x,10) {
				if(cur||x) {
					if(DB[x]<=E) {
						if(N<=dp1[E-DB[x]][d]) {
							cur+=x*p10[d];
							E-=DB[x];
							break;
						}
						else {
							N-=dp1[E-DB[x]][d];
						}
					}
				}
				else {
					if(N<=dp2[E][d]) break;
					N-=dp2[E][d];
				}
			}
		}
		return cur;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; long long Arg2 = 6LL; verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 1; long long Arg2 = 8088LL; verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 8; long long Arg2 = 8898LL; verify_case(2, Arg2, construct(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 123456789; long long Arg2 = 17125735114LL; verify_case(3, Arg2, construct(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 123456; long long Arg2 = 805519LL; verify_case(4, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EnclosedArea ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

