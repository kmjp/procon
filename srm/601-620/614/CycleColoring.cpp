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

ll mo=1000000007;
ll dps[1000010][4],dpd[1000010][4];

class CycleColoring {
	public:
	int countColorings(vector <int> vertexCount, vector <int> fromVertex, vector <int> toVertex, int K) {
		int i,j;
		int N=vertexCount.size();
		
		dps[0][0]=dpd[0][0]=dpd[0][1]=0;
		dps[0][1]=dpd[0][2]=1;
		dps[0][3]=dpd[0][3]=1;
		
		FOR(i,1000000) {
			dps[i+1][3]=dps[i+1][0]=(dps[i][0]*(K-2)+dps[i][1]*(K-1))%mo;
			dps[i+1][1]=(dps[i][0])%mo;
			dpd[i+1][0]=(dpd[i][0]*(K-3)+dpd[i][1]*(K-2)+dpd[i][2]*(K-2))%mo;
			dpd[i+1][1]=(dpd[i][0]+dpd[i][2])%mo;
			dpd[i+1][2]=(dpd[i][0]+dpd[i][1])%mo;
			dpd[i+1][3]=(dpd[i+1][0]+dpd[i+1][2])%mo;
		}
		
		ll sm[51],df[51];
		ZERO(sm);
		ZERO(df);
		sm[0]=K;
		
		FOR(i,N) {
			int t=fromVertex[i]-toVertex[(i+(N-1))%N];
			if(t<0) t+=vertexCount[i];
			
			if(t==0) {
				sm[i+1]=sm[i]*dps[vertexCount[i]-1][3]%mo;
				df[i+1]=df[i]*dps[vertexCount[i]-1][3]%mo;
			}
			else if(t==1 || t==vertexCount[i]-1) {
				df[i+1]=((K-2)*df[i]+(K-1)*sm[i])%mo*dpd[vertexCount[i]-2][3]%mo;
				sm[i+1]=df[i]*dpd[vertexCount[i]-2][3]%mo;
			}
			else {
				int v1=t-1,v2=vertexCount[i]-t-1;
				ll same=dps[v1][3]%mo*dps[v2][3]%mo;
				ll diff=dpd[v1][3]%mo*dpd[v2][3]%mo;
				
				sm[i+1]=(sm[i]*same+df[i]*diff)%mo;
				df[i+1]=(df[i]*same+((K-2)*df[i]+(K-1)*sm[i])%mo*diff)%mo;
			}
		}
		
		return sm[N];
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 12; verify_case(0, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 12; verify_case(1, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 0; verify_case(2, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {9, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; int Arg4 = 589124602; verify_case(3, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {14, 15, 16, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 10, 4, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 3, 14, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 614; int Arg4 = 818050159; verify_case(4, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {482373, 283712, 883, 12834, 5, 5, 482734, 99912, 35881, 277590}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {59283, 49782, 0, 0, 3, 2, 84791, 40017, 2263, 461}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {150173, 709, 11108, 0, 4, 7, 5902, 712, 190232, 390331}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 479360784; int Arg4 = 763634309; verify_case(5, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CycleColoring ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

