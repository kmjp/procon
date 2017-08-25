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

ll mo=1000000007;
ll combi(ll N_, ll C_) {
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
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:combi(P_+Q_-1,Q_);}

ll from[210];
ll to[210];

class SumProduct {
	public:
	int findSum(vector <int> amount, int blank1, int blank2) {
		ll pat[2]={1,1};
		int i;
		FOR(i,blank1-1) pat[0]=(pat[0]*10+1)%mo;
		FOR(i,blank2-1) pat[1]=(pat[1]*10+1)%mo;
		
		int x,y,j,z;
		ll ret=0;
		for(x=1;x<=9;x++) if(amount[x]) {
			amount[x]--;
			for(y=1;y<=9;y++) if(amount[y]) {
				amount[y]--;
				
				ZERO(from);
				from[blank1+blank2-2]=1;
				FOR(i,10) {
					ZERO(to);
					
					for(j=0;j<=blank1+blank2-2;j++) if(from[j]) {
						FOR(z,min(j,amount[i])+1) (to[j-z]+=from[j]*combi(j,z))%=mo;
					}
					swap(from,to);
				}
				
				(ret += x*y*pat[0]%mo*pat[1]%mo*from[0])%=mo;
				amount[y]++;
			}
			amount[x]++;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,2,1,1,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 4114; verify_case(0, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,6,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 22; verify_case(1, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 3; int Arg3 = 340242570; verify_case(2, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {3,14,15,92,65,35,89,79,32,38}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; int Arg2 = 26; int Arg3 = 417461139; verify_case(3, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {100,100,100,100,100,100,100,100,100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 100; int Arg3 = 372980218; verify_case(4, Arg3, findSum(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SumProduct ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

