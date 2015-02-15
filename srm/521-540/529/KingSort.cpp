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

class KingSort {
	public:
	
	int num(string s) {
		int r=0;
		if(s.substr(0,1)=="L") r+=50,s=s.substr(1);
		if(s.substr(0,2)=="XL") r+=40,s=s.substr(2);
		if(s.substr(0,3)=="XXX") r+=30,s=s.substr(3);
		if(s.substr(0,2)=="XX") r+=20,s=s.substr(2);
		if(s.substr(0,1)=="X") r+=10,s=s.substr(1);
		if(s=="IX") r+=9;
		if(s=="VIII") r+=8;
		if(s=="VII") r+=7;
		if(s=="VI") r+=6;
		if(s=="V") r+=5;
		if(s=="IV") r+=4;
		if(s=="III") r+=3;
		if(s=="II") r+=2;
		if(s=="I") r+=1;
		return r;
		
	}
	
	vector <string> getSortedList(vector <string> kings) {
		pair<string,pair<int,string> > PP[51];
		int N=kings.size();
		int i,j;
		
		FOR(i,N) {
			FOR(j,kings[i].size()) if(kings[i][j]==' ') break;
			PP[i].first=kings[i].substr(0,j);
			PP[i].second.first=num(kings[i].substr(j+1));
			PP[i].second.second=kings[i];
		}
		sort(PP,PP+N);
		FOR(i,N) kings[i]=PP[i].second.second;
		return kings;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Louis IX", "Louis VIII"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis VIII", "Louis IX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getSortedList(Arg0)); }
	void test_case_1() { string Arr0[] = {"Louis IX", "Philippe II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis IX", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getSortedList(Arg0)); }
	void test_case_2() { string Arr0[] = {"Richard III", "Richard I", "Richard II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Richard I", "Richard II", "Richard III" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getSortedList(Arg0)); }
	void test_case_3() { string Arr0[] = {"John X", "John I", "John L", "John V"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John I", "John V", "John X", "John L" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getSortedList(Arg0)); }
	void test_case_4() { string Arr0[] = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getSortedList(Arg0)); }
	void test_case_5() { string Arr0[] = {"Philippe II", "Philip II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Philip II", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getSortedList(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  KingSort ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

