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

class GeometricProgressions {
	public:
	
	vector<ll> enumdiv(ll n) {
		vector<ll> V;
		if(n==1) return vector<ll>(1,1);
		for(ll i=2;i*i<=n;i++) while(n%i==0) V.push_back(i),n/=i;
		if(n>1) V.push_back(n);
		return V;
	}
	
	int count(int b1, int q1, int n1, int b2, int q2, int n2) {
		int i,t,B[2],Q[2],N[2];
		
		B[0]=b1,B[1]=b2;
		Q[0]=q1,Q[1]=q2;
		N[0]=n1,N[1]=n2;
		
		set<vector<pair<int,int> > > S;
		
		FOR(t,2) {
			vector<ll> vb,vq;
			map<int,int> M;
			
			if(B[t]==0) {
				vector<pair<int,int> > V;
				V.push_back(make_pair(0,1));
				S.insert(V);
				continue;
			}
			
			vb=enumdiv(B[t]);
			vq=enumdiv(Q[t]);
			ITR(it,vb) M[*it]++;
			
			FOR(i,N[t]) {
				vector<pair<int,int> > V;
				ITR(it,M) V.push_back(make_pair(it->first,it->second));
				S.insert(V);
				
				if(Q[t]==0 && i<N[t]-1) {
					vector<pair<int,int> > V;
					V.push_back(make_pair(0,1));
					S.insert(V);
					break;
				}
				if(Q[t]==1) continue;
				
				ITR(it,vq) M[*it]++;
			}
		}
		
		return S.size();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = 6; int Arg4 = 2; int Arg5 = 5; int Arg6 = 6; verify_case(0, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = 2; int Arg4 = 3; int Arg5 = 5; int Arg6 = 9; verify_case(1, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 2; verify_case(2, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 100500; int Arg3 = 48; int Arg4 = 1024; int Arg5 = 1000; int Arg6 = 100500; verify_case(3, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GeometricProgressions ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

