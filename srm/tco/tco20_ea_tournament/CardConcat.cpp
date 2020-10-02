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

ll L[105][105];
ll R[105][105];
ll p10[1010],fact[1010];
const ll mo=1000000007;
ll lef[101];

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

class CardConcat {
	public:
	int sum(vector <int> cards) {
		ZERO(L);
		ZERO(R);
		int N=cards.size();
		vector<int> D;
		FORR(c,cards) {
			int d=0;
			int x=c;
			while(x) d++, x/=10;
			D.push_back(d);
		}
		p10[0]=fact[0]=1;
		int i,j;
		FOR(i,101) {
			p10[i+1]=p10[i]*10%mo;
			fact[i+1]=fact[i]*(i+1)%mo;
			lef[i]=0;
			FOR(j,i+1) (lef[i]+=comb(i,j)*fact[j])%=mo;
		}
		
		L[0][0]=1;
		R[N+1][0]=1;
		for(i=1;i<=N;i++) {
			FOR(j,101) L[i][j]=L[i-1][j];
			FOR(j,101) (L[i][j+1]+=L[i-1][j]*p10[D[i-1]])%=mo;
		}
		for(i=N;i>=1;i--) {
			FOR(j,101) R[i][j]=R[i+1][j];
			FOR(j,101) (R[i][j+1]+=R[i+1][j]*p10[D[i-1]])%=mo;
		}
		
		ll ret=0;
		int x,y;
		for(i=1;i<=N;i++) {
			FOR(x,100) FOR(y,100) if(L[i-1][x]&&R[i+1][y]) {
				ll pat=L[i-1][x]*R[i+1][y]%mo*fact[x+y]%mo*lef[N-(1+x+y)]%mo;
				ret+=pat*cards[i-1]%mo;
			}
		}
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4, 23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 684; verify_case(0, Arg1, sum(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 735; verify_case(1, Arg1, sum(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1, 2, 3, 5, 8, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 721590587; verify_case(2, Arg1, sum(Arg0)); }
	void test_case_3() { int Arr0[] = {1000, 1000, 2000, 3000, 5000, 8000, 13000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 427973430; verify_case(3, Arg1, sum(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CardConcat ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

