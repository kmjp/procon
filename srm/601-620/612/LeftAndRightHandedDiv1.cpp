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

int T[2000006];
int NL[2000006],NR[2000006];
ll SL[2000006],SR[2000006];

class LeftAndRightHandedDiv1 {
	public:
	int N;
	ll calc(int cur,int sp) {
		int nlR=sp-(NL[cur+sp]-NL[cur]);
		int nrR=(N-sp)-(NR[cur+N+1-(N-sp)]-NR[cur+N+1]);
		ll lv=SL[cur+sp]-SL[cur]-NL[cur]*(ll)nlR;
		ll rv=SR[cur+N+1-(N-sp)]-SR[cur+N+1]-NR[cur+N+1]*(ll)nrR;
		return lv+rv;
	}
	
	long long countSwaps(string Y, int A, int B, int C, int D, int N) {
		int i,j;
		this->N=N;
		ll mi=1LL<<50;
		FOR(i,N) {
			T[i]=T[i+N]=Y[A%Y.size()]=='L';
			A=(A*(ll)B+C)%D;
		}
		T[2*N]=T[0];
		T[2*N+1]=T[1];
		if(count(T,T+N,0)==0) return 0;
		if(count(T,T+N,1)==0) return 0;
		
		FOR(i,2*N+2) {
			NL[i]=(i?NL[i-1]:0);
			SL[i]=(i?SL[i-1]:0);
			if(T[i]) NL[i]++;
			else SL[i]+=NL[i];
		}
		for(i=2*N+1;i>=0;i--) {
			NR[i]=NR[i+1];
			SR[i]=SR[i+1];
			if(T[i]) NR[i]++;
			else SR[i]+=NR[i];
		}
		
		FOR(i,N) {
			int le=0,ri=N;
			mi=min(mi,min(calc(i,le),calc(i,ri)));
			FOR(j,35) {
				int po1=(le*2+ri)/3;
				int po2=(le+ri*2)/3;
				ll hoge1=calc(i,po1);
				ll hoge2=calc(i,po2);
				mi=min(mi,min(hoge1,hoge2));
				if(hoge1<hoge2) ri=po2;
				else le=po1;
			}
			mi=min(mi,min(calc(i,le),calc(i,ri)));
		}
		return mi;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LR"; int Arg1 = 1; int Arg2 = 0; int Arg3 = 1; int Arg4 = 2; int Arg5 = 1; long long Arg6 = 0LL; verify_case(0, Arg6, countSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arg0 = "LRLR"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 3; int Arg5 = 4; long long Arg6 = 0LL; verify_case(1, Arg6, countSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arg0 = "LRRLLR"; int Arg1 = 2; int Arg2 = 3; int Arg3 = 4; int Arg4 = 5; int Arg5 = 6; long long Arg6 = 1LL; verify_case(2, Arg6, countSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arg0 = "LRRLRLLRLRLRLLRLR"; int Arg1 = 12; int Arg2 = 15; int Arg3 = 3; int Arg4 = 22; int Arg5 = 10; long long Arg6 = 2LL; verify_case(3, Arg6, countSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arg0 = "LLLLLLLLL"; int Arg1 = 0; int Arg2 = 1; int Arg3 = 2; int Arg4 = 3; int Arg5 = 1000000; long long Arg6 = 0LL; verify_case(4, Arg6, countSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { string Arg0 = "RLRRRLLLRLRLLRLRLLRLRLLLLLRRLRLRLRLRLLRRRLRRLLLLLRRRLRRLRLRRLLLLRLRRLRLRRLRRLRLLRRLRLRRRLRLLRLLLLRLLLLRLLRRLLRRRRLLRLLRLRLRRLL"; int Arg1 = 48658960; int Arg2 = 221863772; int Arg3 = 385355602; int Arg4 = 393787970; int Arg5 = 980265; long long Arg6 = 59619692663LL; verify_case(5, Arg6, countSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LeftAndRightHandedDiv1 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

