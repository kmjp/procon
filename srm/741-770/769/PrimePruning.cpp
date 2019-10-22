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

const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int nex[20202][26];

class PrimePruning {
	public:
	string maximize(int N, int E) {
		cprime();
		int x;
		if(N>=20000) return string(N-E,'z');
		int i,j;
		
		FOR(i,26) nex[N][i]=N+1;
		for(i=N-1;i>=0;i--) {
			FOR(j,26) nex[i][j]=nex[i+1][j];
			nex[i][prime[i]%26]=i+1;
		}
		
		string R;
		int cur=0;
		int del=E;
		while(cur<N) {
			if(N-cur==del) break;
			for(i=25;i>=0;i--) {
				if(nex[cur][i]-1-cur<=del) break;
			}
			R.push_back('a'+i);
			del-=nex[cur][i]-cur-1;
			cur=nex[cur][i];
		}
		
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 0; string Arg2 = "cdfhlnrtxd"; verify_case(0, Arg2, maximize(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 30; int Arg1 = 5; string Arg2 = "nrtxdflprvbhjptvbfltxzdfj"; verify_case(1, Arg2, maximize(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 15; string Arg2 = "xvjptvbfltxzdfj"; verify_case(2, Arg2, maximize(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PrimePruning ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

