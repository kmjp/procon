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

const ll mo=1000000007;
int D[4096];

static const int N_=4020;
static ll C_[N_][N_];

ll dp[4040][13];

class AlmostOptimalBST {
	public:
	vector <int> count(int N) {
		int i,j;
		D[1]=1;
		for(i=2;i<=4000;i++) D[i]=D[i/2]+1;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;

		ZERO(dp);
		dp[0][0]=1;
		for(i=1;i<=N;i++) {
			if((i&(i+1))==0) {
				dp[i][0]=dp[i/2][0]*dp[i/2][0]%mo*C_[i-1][(i-1)/2]%mo;
			}
			else {
				for(int L=0;L<=i-1;L++) {
					int R=i-1-L;
					ll p=C_[L+R][L];
					
					if(max(D[L],D[R])+1!=D[i]) continue;
					if(D[L]==D[R]) {
						(dp[i][0]+=dp[L][0]*dp[R][0]%mo*p)%=mo;
						(dp[i][1]+=dp[L][1]*dp[R][0]%mo*p)%=mo;
						(dp[i][1]+=dp[L][0]*dp[R][1]%mo*p)%=mo;
						(dp[i][1]+=dp[L][1]*dp[R][1]%mo*p)%=mo;
					}
					else {
						int x=max(L,R);
						int y=min(L,R);
						if(D[x]==D[y]+1) {
							(dp[i][1]+=(dp[x][0]+dp[x][1])*dp[y][0]%mo*p)%=mo;
						}
					}
					
					
				}
			}
		}
		ll AC=dp[N][0]+dp[N][1];
		ZERO(dp);
		dp[0][0]=1;
		for(i=1;i<=N;i++) {
			for(int L=0;L<=i-1;L++) {
				int R=i-1-L;
				ll p=C_[L+R][L];
				ll s=0;
				for(int x=0;x<12;x++) {
					(s+=dp[R][x])%=mo;
					(dp[i][x+1]+=dp[L][x]*s%mo*p)%=mo;
				}
				s=0;
				for(int x=0;x<12;x++) {
					if(x) (s+=dp[L][x-1])%=mo;
					(dp[i][x+1]+=dp[R][x]*s%mo*p)%=mo;
				}
			}
		}
		
		ll ret=dp[N][D[N]];
		
		return {(int)((ret+mo-AC%mo)%mo),0};
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {4, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 8; int Arr1[] = {9680, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 31; int Arr1[] = {0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AlmostOptimalBST ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

