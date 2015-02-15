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

int keta[10000];
int btm[10000];

class MultiplesWithLimit {
	public:
	int ng[10];
	
	int ok(ll val) {
		while(val) {
			if(ng[val%10]) return 0;
			val /=10;
		}
		return 1;
	}
	
	string minMultiples(int N, vector <int> forbiddenDigits) {
		int i,j,k;
		
		ZERO(ng);
		FOR(i,forbiddenDigits.size()) ng[forbiddenDigits[i]]=1;
		
		FOR(i,10000) keta[i]=1000000,btm[i]=0;
		
		j=1;k=0;
		set<pair<int,pair<int,int> > > S;
		for(int a=N;a<100000000LL;a+=N) {
			if(N<=10 && a>=10000000) break;
			if(ok(a)) {
				char hoge[20];
				sprintf(hoge,"%d",a);
				return string(hoge);
			}
			if(a>=j*10000) j*=10,k++;
			if(j>=1000 && keta[a/j]>k && ok(a%j)) {
				
				if(ng[0]&&(a%j)<j/10) continue;
				keta[a/j]=k;
				btm[a/j]=a%1000;
				S.insert(make_pair(k,make_pair(a/j,btm[a/j])));
			}
		}
		
		if(N==10000) return "IMPOSSIBLE";
		
		while(!S.empty()) {
			k=S.begin()->first;
			int to=S.begin()->second.first;
			int bt=S.begin()->second.second;
			S.erase(S.begin());
			
			if(!ng[to%10] && !ng[to/10%10] && !ng[to/100%10] && !ng[to/1000%10]) {
				char hoge[20];
				sprintf(hoge,"%d%d%d...%d%d%d(%d digits)",
					to/1000%10,to/100%10,to/10%10,
					bt/100%10,bt/10%10,bt%10,k+4);
				return string(hoge);
			}
			FOR(i,10000) {
				int to2=to+N*(1+i);
				int k2=k;
				while(to2>=10000) {
					if(ng[to2%10]) goto out;
					to2/=10;
					k2++;
				}
				if(keta[to2]>k2) {
					keta[to2]=k2;
					btm[to2]=bt;
					S.insert(make_pair(k2,make_pair(to2,bt)));
				}
				out:
				;
			}
		}
		return "IMPOSSIBLE";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arr1[] = {2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1000"; verify_case(0, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 9; int Arr1[] = {1,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "222...222(9 digits)"; verify_case(1, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 524; int Arr1[] = {5,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "3668"; verify_case(2, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10000; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(3, Arg2, minMultiples(Arg0, Arg1)); }
	//void test_case_4() { int Arg0 = 1; int Arr1[] = {0,1,2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(4, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9931; int Arr1[] = {0,1,2,3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(4, Arg2, minMultiples(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MultiplesWithLimit ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

