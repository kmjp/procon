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

ll Q[2500];

class Diophantine {
	public:
	long long countSolutions(int N, int D) {
		cprime();
		int i,x,y,z;
		FOR(i,N) Q[i]=1LL*prime[i]*prime[i+D];
		unordered_map<int,int> M;
		ll ret=0;
		FOR(y,N) FOR(x,y+1) M[Q[0]+Q[x]+Q[y]]++;
		for(y=N-1;y>=0;y--) {
			for(z=y+1;z<N;z++) if(M.count(Q[z]-Q[y])) ret+=M[Q[z]-Q[y]];
			for(z=0;z<=y;z++) M[Q[0]+Q[y]+Q[z]]--;
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 15; int Arg1 = 1; long long Arg2 = 2LL; verify_case(0, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2470; int Arg1 = 0; long long Arg2 = 0LL; verify_case(1, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 500; long long Arg2 = 1LL; verify_case(2, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 7; long long Arg2 = 14LL; verify_case(3, Arg2, countSolutions(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Diophantine ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

