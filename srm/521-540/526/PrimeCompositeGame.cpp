#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

//-------------------------------------------------------

int NP,prime[100000];
const int prime_max = 474750;
int p[prime_max];
void cprime() {
	
	int i,j;
	NP=0;
	for(i=2;i<prime_max;i++) {
		if(p[i]) continue;
		prime[NP++]=i;
		for(j=i*2;j<prime_max;j+=i) p[j]=i;
	}
}

bool win[500000];
int turn[500000];

class PrimeCompositeGame {
	public:
	int theOutcome(int N, int K) {
		int i,j,k,x,y;
		
		ZERO(p);
		cprime();
		for(i=1;i<N;i++) p[i]=(p[i]==0);
		p[N]=0;
		
		ZERO(turn);
		ZERO(win);
		set<pair<int,int> > fw,fl,sw,sl;
		set<pair<int,int> >::iterator it;
		
		for(i=2;i<=N;i++) {
			j=i-K-1;
			if(j>1) {
				if(p[j]) {
					if(win[j]) sw.erase(make_pair(turn[j],j));
					else sl.erase(make_pair(turn[j],j));
				}
				else {
					if(win[j]) fw.erase(make_pair(turn[j],j));
					else fl.erase(make_pair(turn[j],j));
				}
			}
			
			if(p[i]) {
				if(!fl.empty()) {
					win[i]=1;
					it=fl.begin();
					turn[i]=it->first+1;
					sw.insert(make_pair(turn[i],i));
				}
				else {
					if(!fw.empty()) {
						it=fw.end();
						it--;
						turn[i]=it->first+1;
					}
					sl.insert(make_pair(turn[i],i));
				}
			}
			else {
				if(!sl.empty()) {
					win[i]=1;
					it=sl.begin();
					turn[i]=it->first+1;
					fw.insert(make_pair(turn[i],i));
				}
				else {
					if(!sw.empty()) {
						it=sw.end();
						it--;
						turn[i]=it->first+1;
					}
					fl.insert(make_pair(turn[i],i));
				}
			}
		}
		
		if(win[N]) return turn[N];
		return -turn[N];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 58; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 3; int Arg2 = -2; verify_case(2, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 1; verify_case(3, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 526; int Arg1 = 58; int Arg2 = 19; verify_case(4, Arg2, theOutcome(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PrimeCompositeGame ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
