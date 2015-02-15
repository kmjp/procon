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

int rev[1000];
int vis[1000];
int dpdp[1001][4];

class CandyCollection {
	public:
	int N;
	vector <int> T1,T2,N1,N2;
	int next(int type) {
		int i,j=0;
		FOR(i,N) if(vis[i]==0 && T1[i]==type) return i;
		FOR(i,N) if(vis[i]==0 && T2[i]==type) {
			swap(T1[i],T2[i]);
			swap(N1[i],N2[i]);
			return i;
		}
		return -1;
	}
	
	int solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2) {
		N=Type1.size();
		MINUS(rev);
		int i,j,k;
		T1=Type1,T2=Type2;
		N1=Number1,N2=Number2;
		
		int tot=0;
		ZERO(vis);
		FOR(i,N) if(vis[i]==0) {
			FOR(j,N) FOR(k,4) dpdp[j][k]=10000000;
			dpdp[0][0]=0;
			dpdp[0][1]=N1[i]+1;
			dpdp[0][2]=N2[i]+1;
			dpdp[0][3]=max(N1[i],N2[i])+1;
			vis[i]=1;
			int cur=next(T2[i]);
			
			for(j=1;j<=N+1;j++) {
				vis[cur]=1;
				int tar=next(T2[cur]);
				if(tar==-1) {
					int x=min(dpdp[j-1][3],dpdp[j-1][2]+N2[cur]+1);
					x=min(x,dpdp[j-1][0]+max(N1[cur],N2[cur])+1);
					x=min(x,dpdp[j-1][1]+N1[cur]+1);
					tot+=x;
					break;
				}
				else {
					dpdp[j][0]=min(dpdp[j-1][1],dpdp[j-1][0]+N2[cur]+1);
					dpdp[j][1]=min(dpdp[j-1][1]+N1[cur]+1,dpdp[j-1][0]+max(N1[cur],N2[cur])+1);
					dpdp[j][2]=min(dpdp[j-1][3],dpdp[j-1][2]+N2[cur]+1);
					dpdp[j][3]=min(dpdp[j-1][3]+N1[cur]+1,dpdp[j-1][2]+max(N1[cur],N2[cur])+1);
				}
				cur=tar;
			}
		}
		return tot;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(1, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,0,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,3,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5; verify_case(2, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,10,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8,8,10,15}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 20; verify_case(3, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5101; verify_case(4, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CandyCollection ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

