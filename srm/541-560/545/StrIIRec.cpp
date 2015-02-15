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

int mainv[1<<20];


class StrIIRec {
	public:
	int n,minInv;
	string SS;
	
	int inv(string s) {
		int i=0,x,y;
		FOR(x,s.size()) for(y=x+1;y<s.size();y++) i+=(s[x]>s[y]);
		return i;
	}
	
	string dfs(int cur,int mask,int same,string cs) {
		int j,x;
		if(cur==n) return "";
		int ci=inv(cs);
		
		FOR(j,n) {
			
			if(mask & (1<<j)) continue;
			if(same&&SS[cur]>'a'+j) continue;
			
			int ci2=ci;
			for(x=j+1;x<n;x++) if(mask & (1<<x)) ci2++;
			
			if(ci2+mainv[mask | (1<<j)] >= minInv) {
				string s;
				s += (char)('a'+j);
				if(same && SS[cur]=='a'+j) {
					string re=dfs(cur+1,mask | (1<<j), 1, cs + s);
					string tot = cs+s+re;
					if(tot.size()==n && inv(tot)>=minInv) return s+re;
				}
				else return s+dfs(cur+1,mask | (1<<j),0,cs+s);
			}
		}
		return "";
	}
	
	string recovstr(int n, int minInv, string minStr) {
		int x,y,i,j,k;
		
		while(minStr.size()<n) minStr += "@";
		SS=minStr;
		this->n=n;
		this->minInv=minInv;
		
		FOR(i,1<<n) {
			int fb=__builtin_popcount(i);
			int lb=n-fb;
			mainv[i]=lb*(lb-1)/2;
			FOR(x,n) for(y=x+1;y<n;y++) if((i&(1<<y)) && ((i&(1<<x))==0)) mainv[i]++;
		}
		
		string s=dfs(0,0,1,"");
		if(s.size()<n || inv(s)<minStr) return "";
		return s;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arg2 = "ab"; string Arg3 = "ba"; verify_case(0, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 1; string Arg2 = "efcdgab"; string Arg3 = "efcdgabhi"; verify_case(1, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 55; string Arg2 = "debgikjfc"; string Arg3 = "kjihgfedcba"; verify_case(2, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 0; string Arg2 = "e"; string Arg3 = "eabcdfghijklmno"; verify_case(3, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 20; string Arg2 = "fcdebiha"; string Arg3 = "fcdehigba"; verify_case(4, Arg3, recovstr(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  StrIIRec ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

