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
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long s64;
typedef unsigned long long u64;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


class RotatingBot {
	public: 
	int mm[500][500]; 
	int minx,miny,maxx,maxy; 

	int minArea(vector <int> moves) { 
		int cx,cy,step,dx,dy,s,rr,i; 
		ZERO(mm); 
		int ddx[4]={1,0,-1,0}; 
		int ddy[4]={0,-1,0,1}; 

		minx=maxx=-99999; 
		miny=maxy=-99999; 
		cx=250; 
		cy=250; 

		mm[cx][cy]=1; 
		rr=0; 
		FOR(step,moves.size()) { 
			s = moves[step]; 
			FOR(i,s) { 
				cx+=ddx[rr]; 
				cy+=ddy[rr]; 
				if(mm[cx][cy]==1) return -1; 
				mm[cx][cy]=1; 
				if(minx!=-99999 && cx<minx) return -1; 
				if(miny!=-99999 && cy<miny) return -1; 
				if(maxx!=-99999 && cx>maxx) return -1; 
				if(maxy!=-99999 && cy>maxy) return -1; 
			} 
			if(step==moves.size()-1) { 
				if(maxx==-99999 && cx>250) maxx=cx; 
				if(maxy==-99999 && cy>250) maxy=cy; 
				if(minx==-99999 && cx<250) minx=cx; 
				if(miny==-99999 && cy<250) miny=cy; 
				break; 
			} 
		
			if(mm[cx+ddx[rr]][cy+ddy[rr]]==0) { 
				if(ddx[rr]>0) { 
					if(cx<250) return -1; 
					if(maxx==-99999) { 
						maxx=cx; 
					} 
					else { 
						if(cx!=maxx) return -1; 
					} 
				} 
				
				if(ddx[rr]<0) { 
					if(cx>250) return -1; 
					if(minx==-99999) { 
						minx=cx; 
					} 
					else { 
						if(cx!=minx) return -1; 
					} 
				} 
				
				if(ddy[rr]>0) { 
					if(cy<250) return -1; 
					if(maxy==-99999) { 
						maxy=cy; 
					} 
					else { 
						if(cy!=maxy) return -1; 
					} 
				} 
				
				if(ddy[rr]<0) { 
					if(cy>250) return -1; 
					if(miny==-99999) { 
						miny=cy; 
					} 
					else { 
						if(cy!=miny) return -1; 
					} 
				} 
			} 

			//rot; 
			rr=(rr+1)%4; 
			FOR(i,3) { 
				if(mm[cx+ddx[rr]][cy+ddy[rr]]==0) break; 
			} 
			if(i==3) return -1; 
		} 

		if(maxx==-99999) maxx=250; 
		if(maxy==-99999) maxy=250; 
		if(minx==-99999) minx=250; 
		if(miny==-99999) miny=250; 

		return (maxx+1-minx)*(maxy+1-miny); 
	} 

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, minArea(Arg0)); }
	void test_case_1() { int Arr0[] = {3,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(1, Arg1, minArea(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, minArea(Arg0)); }
	void test_case_3() { int Arr0[] = {9,5,11,10,11,4,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 132; verify_case(3, Arg1, minArea(Arg0)); }
	void test_case_4() { int Arr0[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420; verify_case(4, Arg1, minArea(Arg0)); }
	void test_case_5() { int Arr0[] = {8,6,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, minArea(Arg0)); }
	void test_case_6() { int Arr0[] = {8,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 63; verify_case(6, Arg1, minArea(Arg0)); }
	void test_case_7() { int Arr0[] = {5,4,5,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(7, Arg1, minArea(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  RotatingBot ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
