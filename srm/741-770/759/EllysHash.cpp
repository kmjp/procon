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

ll mo=1000000000000037LL;

ll V[28][3];

class EllysHash {
	public:
	long long getHash(int N, string A, string B, string C) {
		ZERO(V);
		
		int i;
		ll v=1;
		FOR(i,N) {
			V[i][0]=v*A[N-1-i]%mo;
			V[i][1]=v*B[N-1-i]%mo;
			V[i][2]=v*C[N-1-i]%mo;
			v=v*127%mo;
		}
		
		vector<ll> X,Y;
		X.push_back(0);
		Y.push_back(0);
		FOR(i,14) {
			vector<ll> X2,Y2;
			FORR(x,X) {
				X2.push_back((x+V[i][0])%mo);
				X2.push_back((x+V[i][1])%mo);
				X2.push_back((x+V[i][2])%mo);
			}
			FORR(x,Y) {
				Y2.push_back((x+V[i+14][0])%mo);
				Y2.push_back((x+V[i+14][1])%mo);
				Y2.push_back((x+V[i+14][2])%mo);
			}
			swap(X,X2);
			swap(Y,Y2);
		}
		sort(ALL(X));
		sort(ALL(Y));
		ll mi=1LL<<60;
		FORR(x,X) {
			ll di=(mo-x)%mo;
			i=lower_bound(ALL(Y),di)-Y.begin();
			if(i==Y.size()) i=0;
			mi=min(mi,(x+Y[i])%mo);
		}
		return mi;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; string Arg1 = "ELLY"; string Arg2 = "KRIS"; string Arg3 = "STAN"; long long Arg4 = 142572564LL; verify_case(0, Arg4, getHash(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 11; string Arg1 = "TOPCODERSRM"; string Arg2 = "INTHEMIDDLE"; string Arg3 = "OFTHEDAYNOO"; long long Arg4 = 2840613885160LL; verify_case(1, Arg4, getHash(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 18; string Arg1 = "EVERYSTEPTHATITAKE"; string Arg2 = "ISANOTHERMISTAKETO"; string Arg3 = "YOOOOOOOOOOOOOOOOO"; long long Arg4 = 325013178LL; verify_case(2, Arg4, getHash(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 28; string Arg1 = "ANDNEVERMINDTHENOISEYOUHEARD"; string Arg2 = "ITSJUSTTHEBEASTSUNDERYOURBED"; string Arg3 = "INYOURCLOSETINYOURHEAAAAAAAD"; long long Arg4 = 745LL; verify_case(3, Arg4, getHash(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysHash ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

