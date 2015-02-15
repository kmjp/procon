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


class UF {
	public:
	static const int ufmax=22;
	int ufpar[ufmax],ufrank[ufmax];
	UF() { init();}
	void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; } }
	int find(int x) {	return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
	int operator[](int x) {return find(x);}
	void unite(int x,int y) {
		x = find(x); y = find(y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y;
		else {ufpar[y]=x; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

class Egalitarianism2 {
	int N;
	double dist[21][21];
	ll distsq[21][21];
	public:
	double mst(double ave) {
		int x,y;
		vector<pair<double,int> > V;
		FOR(x,N) FOR(y,N) if(x<y) V.push_back(make_pair((ave-dist[x][y])*(ave-dist[x][y]),x*100+y));
		sort(V.begin(),V.end());
		
		UF uf;
		double nave=0;
		ll sum=0;
		ITR(it,V) {
			int k1=it->second/100;
			int k2=it->second%100;
			if(uf.find(k1)==uf.find(k2)) continue;
			nave+=dist[k1][k2];
			sum+=distsq[k1][k2];
			uf.unite(k1,k2);
		}
		nave/=N-1;
		return sqrt(sum/(double)(N-1)-nave*nave);
	}
	
	double minStdev(vector <int> x, vector <int> y) {
		int i,j;
		vector<double> cand;
		N=x.size();
		
		FOR(i,N) FOR(j,N) distsq[i][j]=(x[i]-x[j])*(ll)(x[i]-x[j])+(y[i]-y[j])*(ll)(y[i]-y[j]);
		FOR(i,N) FOR(j,N) if(i!=j) cand.push_back(dist[i][j]=sqrt(distsq[i][j]));
		double ret=1e20;
		FOR(i,cand.size()) FOR(j,cand.size()) if(i>=j) {
			ret=min(ret,mst((cand[i]+cand[j])/2.0));
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(1, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12,46,81,56}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,45,2,67}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.102799971320872; verify_case(2, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,3,9,10,15,16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.9428090415820617; verify_case(3, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {167053, 536770, -590401, 507047, 350178, -274523, -584679, -766795, -664177, 267757, -291856, -765547, 604801, -682922, -404590, 468001, 607925, 503849, -499699, -798637}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-12396, -66098, -56843, 20270, 81510, -23294, 10423, 24007, -24343, -21587, -6318, -7396, -68622, 56304, -85680, -14890, -38373, -25477, -38240, 11736}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 40056.95946451678; verify_case(4, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_52() { int Arr0[] = {-306880, 169480, -558404, -193925, 654444, -300247, -456420, -119436, -620920, -470018, -914272, -691256, -49418, -21054, 603373, -23656, 891691, 258986, -453793, -782940}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-77318, -632629, -344942, -361706, 191982, 349424, 676536, 166124, 291342, -268968, 188262, -537953, -70432, 156803, 166174, 345128, 58614, -671747, 508265, 92324}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 36879.1512763429; verify_case(5, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-3, -3, 2, -5, -5, 10, -8, -7, 2, -3, 3, 9, -6, 4, -2, -1, 0, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, -4, -6, -1, -6, -5, -6, 4, -1, -5, -5, -6, 0, 4, 5, 2, -6, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 36879.1512763429; verify_case(5, Arg2, minStdev(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Egalitarianism2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

