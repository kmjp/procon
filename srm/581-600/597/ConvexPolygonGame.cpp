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

class ConvexPolygonGame {
	public:
	int N;
	pair<int,int> RR[200001];
	int okok(vector <int> X, vector <int> Y) {
		int i;
		int mix=X[0],miy=Y[0],maxx=0,x;
		FOR(i,N) mix=min(mix,X[i]),miy=min(miy,Y[i]);
		FOR(i,N) X[i]-=mix,Y[i]-=miy;
		FOR(i,N) maxx=max(maxx,X[i]);
		FOR(i,maxx+1) RR[i].first=1000000,RR[i].second=-1000000;
		
		FOR(i,N) RR[X[i]].first=min(RR[X[i]].first,Y[i]+1),RR[X[i]].second=max(RR[X[i]].second,Y[i]-1);
		FOR(i,N) {
			if(X[i]==X[(i+1)%N]) continue;
			for(x=min(X[i],X[(i+1)%N])+1;x<max(X[i],X[(i+1)%N]);x++) {
				ll dy=(Y[(i+1)%N]-Y[i])*(ll)(x-X[i])+Y[i]*(ll)(X[(i+1)%N]-X[i]);
				ll dx=X[(i+1)%N]-X[i];
				if(dy%dx==0) {
					RR[x].first=min(RR[x].first,(int)(dy/dx));
					RR[x].second=max(RR[x].second,(int)(dy/dx));
				}
				else {
					RR[x].first=min(RR[x].first,(int)(dy/dx)+1);
					RR[x].second=max(RR[x].second,(int)(dy/dx));
				}
			}
		}
		int num2=0,num1=0;
		vector<pair<int,int> > SS;
		FOR(i,maxx+1) {
			//_P("%d %d %d\n",i+mix,RR[i].first+miy,RR[i].second+miy);
			if(RR[i].second-RR[i].first>=1) num2++;
			if(RR[i].second-RR[i].first==0) {
				num1++;
				SS.push_back(make_pair(i,RR[i].first));
			}
		}
		
		if(num2>=2 || (num2&&num1)) return 1;
		if(num1<3) return 0;
		
		for(i=2;i<num1;i++) {
			if((SS[1].first-SS[0].first)*(ll)(SS[i].second-SS[0].second)-(SS[i].first-SS[0].first)*(ll)(SS[1].second-SS[0].second))
				return 1;
		}
		
		
		return 0;
		
	}
	
	
	
	string winner(vector <int> X, vector <int> Y) {
		N=X.size();
		if(okok(X,Y) || okok(Y,X)) return "Masha";
		return "Petya";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(0, Arg2, winner(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(1, Arg2, winner(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 100, 100, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(2, Arg2, winner(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 50, 100, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(3, Arg2, winner(Arg0, Arg1)); }
	void test_case_42() { int Arr0[] = {-100000, 100000, 100000, -100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, -1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(4, Arg2, winner(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {99990, 99990, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {99996,99997, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(4, Arg2, winner(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ConvexPolygonGame ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

