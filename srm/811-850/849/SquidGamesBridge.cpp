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

class SquidGamesBridge {
	public:
	int cross(int P, int S) {
		set<int> L[2];
		L[0]={0,1};
		cprime();
		int i;
		for(i=2;i<S;i++) {
			L[divp[i]==0].insert(i);
		}
		int num=0;
		int ret=0;
		int ma=-1;
		while(num<P&&ma<S) {
			FOR(i,2) while(L[i].size()&&*L[i].begin()<=ma) L[i].erase(L[i].begin());
			if(L[num%2].empty()) return P-num;
			ma=*L[num%2].begin();
			L[num%2].erase(ma);
			num++;
		}
		
		return P-num;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, cross(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 1; verify_case(1, Arg2, cross(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 0; verify_case(2, Arg2, cross(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1234567; int Arg1 = 1; int Arg2 = 1234566; verify_case(3, Arg2, cross(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1234; int Arg1 = 567; int Arg2 = 1029; verify_case(4, Arg2, cross(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SquidGamesBridge ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

