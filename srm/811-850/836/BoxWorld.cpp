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


ll from[1<<14][100];
ll to[1<<14][100];
const ll mo=1000000007;
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
ll hcomb(ll P_,ll Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}


class BoxWorld {
	public:
	int count(int R, int C, int N) {
		ZERO(from);
		int y,x,mask,num;
		FOR(mask,1<<C) if((mask&(mask>>1))==0) from[mask][__builtin_popcount(mask)]++;
		FOR(y,R-1) {
			FOR(x,C) {
				ZERO(to);
				FOR(mask,1<<C) for(num=0;num<=98;num++) if(from[mask][num]) {
					int up=mask&(1<<x);
					int lef=(x==0?0:(mask>>(x-1))&1);
					if(up) {
						to[mask^up][num]+=from[mask][num];
					}
					else {
						to[mask][num]+=from[mask][num];
						if(lef==0) to[mask^(1<<x)][num+1]+=from[mask][num];
					}
				}
				FOR(mask,1<<C) for(num=0;num<=99;num++) from[mask][num]=to[mask][num]%mo;
			}
		}
		for(x=99;x>=0;x--) {
			int ok=0;
			ll ret=0;
			FOR(mask,1<<C) if(x&&x<=N&&from[mask][x]) {
				ok=1;
				ret+=hcomb(x,N-x)*from[mask][x]%mo;
			}
			if(ok) return ret%mo;
		}
		return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 10; int Arg2 = 1; int Arg3 = 70; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 47; int Arg3 = 1; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 2; int Arg3 = 1; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 3; int Arg3 = 1276; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 3; int Arg3 = 2; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BoxWorld ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

