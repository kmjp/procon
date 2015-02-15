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

class Rumor {
	public:
	string K;
	vector<string> G;
	int spm[16];
	int N;
	
	int dodo(int mask) {
		int i,j,k,x,y;
		int sp1,sp2;
		int kn1,kn2,nkn1,nkn2;
		
		sp1=sp2=0;
		kn1=kn2=0;
		FOR(i,N) kn1|=(K[i]=='Y')<<i;
		FOR(i,N) kn2|=(K[i]=='Y')<<i;
		nkn1=kn1;
		nkn2=kn2;
		
		FOR(i,20) {
			if(nkn1==(1<<N)-1 && nkn2==(1<<N)-1) break;
			
			FOR(j,N) {
				int sp=0;
				if((sp1&(1<<j))==0 && (sp2&(1<<j))==0) {
					if(mask&(1<<j)) {
						if(kn2&(1<<j)) sp=2;
						else if(kn1&(1<<j)) sp=1;
					}
					else {
						if(kn1&(1<<j)) sp=1;
						else if(kn2&(1<<j)) sp=2;
					}
				}
				else if((sp1&(1<<j))==0 && (kn1&(1<<j))) sp=1;
				else if((sp2&(1<<j))==0 && (kn2&(1<<j))) sp=2;
				
				if(sp==1) nkn1 |= spm[j],sp1 |= 1<<j;
				if(sp==2) nkn2 |= spm[j],sp2 |= 1<<j;
			}
			kn1=nkn1;
			kn2=nkn2;
		}
		return i;
	}
	
	int getMinimum(string knowledge, vector <string> graph) {
		K=knowledge;
		G=graph;
		N=K.size();
		int mi=20;
		
		int i,j;
		ZERO(spm);
		FOR(i,N) FOR(j,N) spm[i] |= (graph[i][j]=='Y')<<j;
		for(int mask=0;mask<1<<N;mask++) mi=min(mi,dodo(mask));
		
		if(mi>=20) return -1;
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNN"; string Arr1[] = {"NYN"
,"NNY"
,"NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "YNNY"; string Arr1[] = {"NYYN"
,"YNNY"
,"YNNY"
,"NYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "YYYY"; string Arr1[] = {"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "YYYYYN"; string Arr1[] = {"NYYYYN"
,"YNYYYN"
,"YYNYYN"
,"YYYNYN"
,"YYYYNN"
,"NNNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "NNNY"; string Arr1[] = {"NNNN"
,"YNNN"
,"YNNN"
,"NYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_5() { string Arg0 =  "NNNNNNNYYY"; string Arr1[] = {"NYNNYNNYNN"
,"NNYNYNNNNY"
,"YYNNNYNNNN"
,"YNNNYNYNNN"
,"NNYNNYNNYN"
,"NNNNYNNNYY"
,"NYNYNYNNNN"
,"NNNNNNYNYY"
,"NNNYNNNYNY"
,"NYYNNNNYNN"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(5, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Rumor ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
