#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000009;

ll combi(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int dp[201][201][405][2];
ll dp2[405];

class ColourHolic {
	public:
	
	
	int countSequences(vector <int> n) {
		int i,j,x,y,z;
		sort(n.begin(),n.end());
		if(n[0]==0 && n[1]==0) {
			if(n[2]==n[3]) return 2;
			return (n[2]==n[3]-1);
		}
		
		ZERO(dp);
		ZERO(dp2);
		FOR(x,402) { // plus
			y = x+n[3]-n[2]; // minus
			FOR(z,402) if(x+y+z<=n[0]+n[1]+1 && x+y+z>0) { //same
				int left=n[3]-y-z;
				if(left<0) continue;
				ll tot=combi(x+y+z,x)*combi(y+z,y)%mo*modpow(2,z)%mo*combi(left+(x+y+z-1),(x+y+z-1));
				dp2[x+y+z]=(dp2[x+y+z]+tot)%mo;
			}
		}
		
		if(n[0]>0) dp[n[0]-1][n[1]][0][0]=1;
		if(n[1]>0) dp[n[0]][n[1]-1][0][1]=1;
		for(x=n[0];x>=0;x--) for(y=n[1];y>=0;y--) FOR(i,401) {
			if(dp[x][y][i][0] && x>0) (dp[x-1][y][i+1][0]+=dp[x][y][i][0])%=mo;
			if(dp[x][y][i][0] && y>0) (dp[x][y-1][i][1]+=dp[x][y][i][0])%=mo;
			if(dp[x][y][i][1] && x>0) (dp[x-1][y][i][0]+=dp[x][y][i][1])%=mo;
			if(dp[x][y][i][1] && y>0) (dp[x][y-1][i+1][1]+=dp[x][y][i][1])%=mo;
		}
		ll ret=0;
		FOR(i,402) {
			ll pat=(dp[0][0][i][0]+dp[0][0][i][1])%mo;
			ll t=0;
			for(x=i;x<=401;x++) (t+=dp2[x]*combi(n[0]+n[1]+1-i , x-i))%=mo;
			ret=(ret+pat*t)%mo;
		}
		return (int)ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, countSequences(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(1, Arg1, countSequences(Arg0)); }
	void test_case_2() { int Arr0[] = {42,42,42,9001}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countSequences(Arg0)); }
	void test_case_3() { int Arr0[] = {8,0,0,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, countSequences(Arg0)); }
	void test_case_4() { int Arr0[] = {0,5,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, countSequences(Arg0)); }
	void test_case_5() { int Arr0[] = {4,2,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1074; verify_case(5, Arg1, countSequences(Arg0)); }
	void test_case_6() { int Arr0[] = {15,900,357,22}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, countSequences(Arg0)); }
	void test_case_7() { int Arr0[] = {110,30000,200,29999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 118115350; verify_case(7, Arg1, countSequences(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ColourHolic ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
