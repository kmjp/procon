#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int prime_max = 2100000;
int NP,prime[200000];
vector<int> divp;

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	
	while(divp[n]>1) {
		V[divp[n]]++;
		n/=divp[n];
	}
	if(n>1) V[n]++;
	return V;
}

class MissingLCM {
	public:
	int getMin(int N) {
		map<ll,int> MM;
		
		NP=0;
		divp.resize(prime_max);
		cprime();
		
		if(N==1) return 2;
		
		int i,mapr=0;
		for(i=1;i<=N;i++) {
			map<ll,int> v=enumpr(i);
			if(divp[i]==0) mapr=i*2;
			FORR(r,v) if(r.second>=2) MM[r.first]=max(MM[r.first],r.second);
		}
		
		for(i=N+1;;i++) {
			map<ll,int> v=enumpr(i);
			FORR(r,v) {
				if(MM.count(r.first)==0) continue;
				if(MM[r.first]<=r.second) {
					MM.erase(r.first);
				}
			}
			if(i>=mapr&&MM.empty()) return i;
		}
		return 0;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 6; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 8; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 10; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { int Arg0 = 42; int Arg1 = 82; verify_case(5, Arg1, getMin(Arg0)); }
	void test_case_6() { int Arg0 = 999999; int Arg1 = 1999966; verify_case(6, Arg1, getMin(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MissingLCM ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
