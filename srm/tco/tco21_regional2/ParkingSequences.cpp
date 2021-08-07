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

ll from[2][21][51][202];
ll to[2][21][51][202];

const ll mo=1000000007;
static const int N_=102;
static ll C_[N_][N_];
int fix[51][51];

class ParkingSequences {
	public:
	int count(int N, int B) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
		
		FOR(i,50) {
			for(j=1;j<=50;j++) {
				fix[i][j]=fix[i][j-1]+max(0,(i-j));
			}
		}
		
		ll ret=0;
		for(i=0;i<=min(N-1,20);i++) {
			ZERO(from);
			from[0][i][N][0]=1;
			FOR(j,N) {
				ZERO(to);
				for(int NZ=0;NZ<=1;NZ++) {
					for(int C=0;C<=20;C++) {
						for(int S=0;S+fix[C][N-j]<=B;S++) {
							for(int L=0;L<=N;L++) if(from[NZ][C][L][S]) {
								for(int add=(C==0?1:0);add<=L&&S+fix[C+add][N-j]<=B;add++) {
									(to[NZ|(C+add-1==0)][C+add-1][L-add][S+(C+add-1)]+=from[NZ][C][L][S]*C_[L][add])%=mo;
								}
							}
						}
					}
				}
				swap(from,to);
			}
			ret+=from[1][i][0][B];
		}
		return ret%mo;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 13; int Arg1 = 0; int Arg2 = 227020758; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 48; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 200; int Arg2 = 25; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ParkingSequences ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

