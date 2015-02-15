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


class FamilyCrest {
	int N;
	vector<int> X1,Y1,X2,Y2;
	set<pair<double,double> > S;
	public:
	
	int cross(int a,int b) {
		// par?
		int dx1=X2[a]-X1[a],dy1=Y2[a]-Y1[a];
		int dx2=X2[b]-X1[b],dy2=Y2[b]-Y1[b];
		if(dx1*dy2-dx2*dy1==0) return 0;
		
		// same point
		if(X1[a]==X1[b] && Y1[a]==Y1[b]) return 0;
		if(X2[a]==X1[b] && Y2[a]==Y1[b]) return 0;
		if(X1[a]==X2[b] && Y1[a]==Y2[b]) return 0;
		if(X2[a]==X2[b] && Y2[a]==Y2[b]) return 0;
		
		ll x11=X1[a],x12=X2[a],y11=Y1[a],y12=Y2[a];
		ll x21=X1[b],x22=X2[b],y21=Y1[b],y22=Y2[b];
		if(	((x12-x11)*(y21-y11)-(y12-y11)*(x21-x11))*
			((x12-x11)*(y22-y11)-(y12-y11)*(x22-x11)) <= 0) {
			if(((x11-x21)*(y22-y21)-(y11-y21)*(x22-x21))*
				((x12-x21)*(y22-y21)-(y12-y21)*(x22-x21)) <= 0) return 1;
		}
		return 0;
	}
	
	void addcand(int dx1,int dy1,int dx2,int dy2) {
		int g=__gcd(abs(dx1),abs(dy1));
		dx1/=g;dy1/=g;
		g=__gcd(abs(dx2),abs(dy2));
		dx2/=g;dy2/=g;
		
		if(dx1==dx2 && dy1==dy2) return;
		
		double d1=atan2(dy1,dx1);
		double d2=atan2(dy2,dx2);
		if(d1<0) d1+=atan(1)*8;
		if(d2<0) d2+=atan(1)*8;
		if(d2<d1) swap(d1,d2);
		if(d2-d1>=atan(1)*4) swap(d1,d2);
		double dif=d2-d1;
		
		double d3=d1+atan(1)*4;
		if(d3>=atan(1)*8) d3-=atan(1)*8;
		S.insert(make_pair(d2,d3));
		
		d3=d2+atan(1)*4;
		if(d3>=atan(1)*8) d3-=atan(1)*8;
		S.insert(make_pair(d3,d1));
	}
	
	string canBeInfinite(vector <int> A, vector <int> B, vector <int> C, vector <int> D) {
		int x,y,i;
		N=A.size();
		X1=A;Y1=B;X2=C;Y2=D;
		
		FOR(x,N) FOR(y,N) if(cross(x,y)) return "Finite";
		S.clear();
		FOR(x,N) FOR(y,N) {
			if(X1[x]==X1[y] && Y1[x]==Y1[y]) addcand(X2[x]-X1[x],Y2[x]-Y1[x],X2[y]-X1[y],Y2[y]-Y1[y]);
			if(X1[x]==X2[y] && Y1[x]==Y2[y]) addcand(X2[x]-X1[x],Y2[x]-Y1[x],X1[y]-X2[y],Y1[y]-Y2[y]);
			if(X2[x]==X1[y] && Y2[x]==Y1[y]) addcand(X1[x]-X2[x],Y1[x]-Y2[x],X2[y]-X1[y],Y2[y]-Y1[y]);
			if(X2[x]==X2[y] && Y2[x]==Y2[y]) addcand(X1[x]-X2[x],Y1[x]-Y2[x],X1[y]-X2[y],Y1[y]-Y2[y]);
		}
		
		if(S.empty()) return "Infinite";
		
		set<double> DD;
		ITR(it,S) DD.insert(it->first),DD.insert(it->second);
		vector<double> V=vector<double>(DD.begin(),DD.end());
		FOR(x,V.size()) FOR(y,V.size()) {
			double deg=(V[x]+V[y])/2;
			FOR(i,2) {
				int ng=0;
				
				ITR(it,S) {
					if(it->first<=it->second && deg>=it->first-1e-9 && deg<=it->second+1e-9) ng++;
					if(it->first>it->second && (deg>=it->first-1e-9 || deg<=it->second+1e-9)) ng++;
				}
				
				if(!ng) return "Infinite";
				
				deg+=atan(1)*4;
				if(deg>=atan(1)*8) deg-=atan(1)*8;
			}
		}
		
		return "Finite";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Infinite"; verify_case(0, Arg4, canBeInfinite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Finite"; verify_case(1, Arg4, canBeInfinite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,3,0,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,0,3,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Infinite"; verify_case(2, Arg4, canBeInfinite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,-1,-3,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,3,0,3,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,-3,-1,-3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,0,3,0,2,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Finite"; verify_case(3, Arg4, canBeInfinite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {0,2,4,6,-1,-2,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0,1,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,4,6,8,-2,-1,-2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,0,1,0,2,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Infinite"; verify_case(4, Arg4, canBeInfinite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0,0,0,2,3,3,4,5,6,7,9,9,9,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,1,0,0,2,0,0,2,0,0,2,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,1,2,3,4,4,5,8,7,9,10,10,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,2,1,2,2,0,2,2,2,2,2,2,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Finite"; verify_case(5, Arg4, canBeInfinite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {-6,-3,3,-6,-3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,-2,-1,-2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-3,3,6,-3,3,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,-2,-1,-2,2,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Finite"; verify_case(6, Arg4, canBeInfinite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arr0[] = {-1,-2,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0,2,-1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Infinite"; verify_case(7, Arg4, canBeInfinite(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FamilyCrest ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

