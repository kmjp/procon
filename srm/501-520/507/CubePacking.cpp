#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

vector<ll> enumdiv(ll n) {
	set<ll> S;
	for(ll i=2;i*i<=n;i++) if(n%i==0) S.insert(i),S.insert(n/i); 
	S.insert(n);
	return vector<ll>(S.begin(),S.end());
}

class CubePacking {
	public:
	int getMinimumVolume(int Ns, int Nb, int L) {
		ll S=Ns+L*L*L*Nb;
		int x,y,z;
		
		while(1) {
			vector<ll> V = enumdiv(S);
			
			FOR(x,V.size()) {
				if(V[x]>S/V[x]) break;
				for(y=x;y<V.size();y++) {
					if(V[y]>S/(V[x]*V[y])) break;
					
					if(S%(V[x]*V[y])==0 && (V[x]/L)*(V[y]/L)*(S/(V[x]*V[y])/L)>=Nb) 
						return (int)S;
				}
			}
			S++;
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 20; verify_case(0, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 19; int Arg1 = 1; int Arg2 = 2; int Arg3 = 27; verify_case(1, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 51; int Arg1 = 7; int Arg2 = 5; int Arg3 = 950; verify_case(2, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 12345; int Arg1 = 987; int Arg2 = 10; int Arg3 = 999400; verify_case(3, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CubePacking ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

