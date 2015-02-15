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

int CC,NB;
int N[51];
int B[51];
int T[51][51],C[51][51],IP[51][51];
double P[51][51],TP[51][51];

double dpdp[25][25][1<<12];
int TN[51],TID[51];

class NewItemShop {
	public:
	
	double dodo(int tim, int sw, int mask) {
		
		if(tim>=24 || sw<=0) return 0;
		if(dpdp[tim][sw][mask]>=0) return dpdp[tim][sw][mask];
		
		if(TN[tim]==-1) return dpdp[tim][sw][mask] = dodo(tim+1, sw, mask);
		if(B[TN[tim]]>=0 && (mask & (1<<B[TN[tim]]))) return dpdp[tim][sw][mask] = dodo(tim+1, sw, mask); 
		
		double happen=P[TN[tim]][TID[tim]]/(1-TP[TN[tim]][tim]);
		
		double ntp = dodo(tim+1, sw, mask);
		int nm=mask;
		if(B[TN[tim]]>=0) nm |= 1<<B[TN[tim]];
		double take = 0;
		if(sw>0) take = C[TN[tim]][TID[tim]] + dodo(tim+1,sw-1,nm);
		double notake = dodo(tim+1,sw,nm);
		
		return dpdp[tim][sw][mask] = happen*max(take,notake) + (1-happen)*ntp;
		
		
	}
	
	double getMaximum(int swords, vector <string> customers) {
		int i,j,x,y,t;
		string s;
		
		CC=customers.size();
		NB=0;
		ZERO(N);MINUS(B);
		ZERO(T);ZERO(C);ZERO(P);ZERO(IP);
		MINUS(TN),MINUS(TID);ZERO(TP);
		FOR(i,CC) {
			int d=0,j;
			N[i]=0;
			
			ITR(it,customers[i]) {
				if(*it==',') d++;
				else if(*it==' ') d=0,N[i]++;
				else if(d==0) T[i][N[i]]=T[i][N[i]]*10+*it-'0';
				else if(d==1) C[i][N[i]]=C[i][N[i]]*10+*it-'0';
				else if(d==2) IP[i][N[i]]=IP[i][N[i]]*10+*it-'0';
			}
			N[i]++;
			FOR(j,N[i]) TN[T[i][j]]=i,TID[T[i][j]]=j,P[i][j]=IP[i][j]/100.0;
			FOR(j,N[i]) for(x=T[i][j]+1;x<=24;x++) TP[i][x] += P[i][j];
			if(N[i]>1) B[i]=NB++;
		}
		
		FOR(i,25) FOR(j,25) FOR(x,1<<12) dpdp[i][j][x]=-1;
		return dodo(0,swords,0);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arr1[] = { "8,1,80 16,100,11", "12,10,100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 19.0; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = { "8,1,80 16,100,11", "12,10,100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 21.8; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; string Arr1[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 90.0; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = { "17,31,41 20,59,26 23,53,5", "19,89,79", "16,32,38 22,46,26", "18,43,38 21,32,7" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 135.5121414; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; string Arr1[] = { "1,1,10", "2,2,9", "3,3,8", "4,4,7", "5,5,6", "6,6,5", "7,7,4", "8,8,3", "9,9,2", "10,10,1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.1999744634845344; verify_case(4, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NewItemShop ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

