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

const int prime_max = 10000000;
vector<int> prime;
int NP;
bool divp[prime_max];

void cprime() {
	if(NP) return;
	divp[1]=1;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=1;
	}
}

class PrimeSubstrings {
	public:
	int L;
	int ok(int p,int L) {
		string S=to_string(p),T;
		while(T.size()<S.size()+L) T+=S;
		int i;
		FOR(i,S.size()) {
			if(T[i]=='0') return 0;
			int v=atoi(T.substr(i,L).c_str());
			if(divp[v]) return 0;
		}
		return 1;
	}
	
	int dfs(int p,int d) {
		if(ok(p,L)) return p;
		if(d==8) return 0;
		
		int i,v;
		FOR(i,5) {
			v=dfs(p*10+i*2+1,d+1);
			if(v) return v;
		}
		return 0;
	}
	
	string construct(int N, int L) {
		this->L=L;
		cprime();

		string S=to_string(dfs(0,0)),T;
		int i;
		FOR(i,N) T+=S[i%S.size()];
		return T;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; string Arg2 = "5317"; verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 7; string Arg2 = "1301779"; verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 4; string Arg2 = "13079"; verify_case(2, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PrimeSubstrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

