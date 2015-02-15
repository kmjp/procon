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

int dpdp[1<<10];

class EllysCandyGame {
	public:
	string getWinner(vector <int> sweets) {
		int N=sweets.size();
		int i,j,x,y,mask;
		int cs[10];
		
		dpdp[0]=0;
		dpdp[1<<N]=0;
		for(mask=1;mask<1<<N;mask++) {
			int ng=0,step=0;
			FOR(i,N) ng |= (mask&(1<<i)) && sweets[i]==0;
			if(ng) continue;
			
			FOR(i,N) if((mask&(1<<i))==0 && sweets[i]) step++;
			if(step%2) dpdp[mask]=1<<25;
			else dpdp[mask]=-1<<25;
			
			FOR(i,N) if((mask&(1<<i))) {
				int sc=sweets[i];
				if(i>0 && sweets[i-1] && (mask&(1<<(i-1)))==0) sc*=2;
				if(i<N-1 && sweets[i+1] && (mask&(1<<(i+1)))==0) sc*=2;
				if(step%2) dpdp[mask]=min(dpdp[mask],dpdp[mask ^ (1<<i)]-sc);
				else dpdp[mask]=max(dpdp[mask],dpdp[mask ^ (1<<i)]+sc);
			}
			
			if(step==0) break;
		}
		
		if(dpdp[mask]>0) return "Elly";
		if(dpdp[mask]<0) return "Kris";
		return "Draw";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {20, 50, 70, 0, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { int Arr0[] = {42, 13, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Elly"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { int Arr0[] = {10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Draw"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { int Arr0[] = {3, 1, 7, 11, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { int Arr0[] = {41, 449, 328, 474, 150, 501, 467, 329, 536, 440}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(4, Arg1, getWinner(Arg0)); }
	void test_case_5() { int Arr0[] = {177, 131, 142, 171, 411, 391, 17, 222, 100, 298}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Elly"; verify_case(5, Arg1, getWinner(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysCandyGame ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

