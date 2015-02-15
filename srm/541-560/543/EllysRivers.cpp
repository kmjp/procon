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

double dpdp[51][100001];
double tim[100001];
ll L,R;
class EllysRivers {
	public:
	int N;
	
	double dodo(int cur,ll pos) {
		R=min(R,pos);
		L=max(L-1,0LL);
		while(R-L>=9) {
			ll po1=(L*2+R)/3;
			ll po2=(L+R*2)/3;
			double h1=dpdp[cur][po1]+tim[pos-po1];
			double h2=dpdp[cur][po2]+tim[pos-po2];
			if(h1==h2) L=po1,R=po2;
			else if(h1<h2) R=po2;
			else L=po1;
		}
		
		double hoge=1e20;
		for(ll x=L;x<=R;x++) hoge=min(hoge,dpdp[cur][x]+tim[pos-x]);
		return hoge;
	}
	
	double getMin(int length, int walk, vector <int> width, vector <int> speed) {
		N=width.size();
		int i,x,y;
		ZERO(dpdp);
		FOR(i,length+1) dpdp[0][i]=i/(double)walk;
		
		FOR(x,N) {
			FOR(i,length+1) tim[i]=sqrt(width[x]*(ll)width[x]+i*(ll)i)/(double)speed[x];
			R=length;
			L=0;
			for(i=length;i>=0;i--) dpdp[x+1][i]=dodo(x,i);
		}
		return dpdp[N][length];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; int Arr2[] = {5, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 2, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 3.231651964071508; verify_case(0, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10000; int Arg1 = 211; int Arr2[] = {911}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {207}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 48.24623664712219; verify_case(1, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1337; int Arg1 = 2; int Arr2[] = {100, 200, 300, 400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {11, 12, 13, 14}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 128.57830549575695; verify_case(2, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 77; int Arg1 = 119; int Arr2[] = {11, 12, 13, 14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100, 200, 300, 400}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.3842077071089629; verify_case(3, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 7134; int Arg1 = 1525; int Arr2[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 214.6509731258811; verify_case(4, Arg4, getMin(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysRivers ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
