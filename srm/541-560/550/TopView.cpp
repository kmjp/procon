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

int L[256],R[256],T[256],B[256],N[256],CN;
int over[256][256];

class TopView {
	public:
	int H,W;
	string findOrder(vector <string> grid) {
		int y,x,i;
		
		CN=0;
		H=grid.size();
		W=grid[0].size();
		set<char> S;
		FOR(i,256) L[i]=T[i]=100,R[i]=B[i]=-1,N[i]=0;
		
		FOR(y,H) FOR(x,W) if(grid[y][x]!='.') {
			L[grid[y][x]] = min(L[grid[y][x]],x);
			R[grid[y][x]] = max(R[grid[y][x]],x);
			T[grid[y][x]] = min(T[grid[y][x]],y);
			B[grid[y][x]] = max(B[grid[y][x]],y);
			N[grid[y][x]]++;
			CN++;
		}
		ZERO(over);
		ZERO(inb);
		FOR(i,256) if(N[i]) {
			for(y=T[i];y<=B[i];y++) for(x=L[i];x<=R[i];x++) {
				if(grid[y][x]=='.') return "ERROR!";
				if(grid[y][x]!=i) over[i][grid[y][x]]=1;
			}
		}
		
		string res;
		while(1) {
			FOR(i,256) if(N[i]) {
				int ng=0;
				FOR(x,256) ng |= (N[x] && over[x][i]);
				if(ng==0) break;
			}
			if(i==256) break;
			
			res += (char)i;
			CN -= N[i];
			N[i]=0;
		}
		
		if(CN==0) return res;
		else return "ERROR!";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..AA..",
 ".CAAC.",
 ".CAAC."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CA"; verify_case(0, Arg1, findOrder(Arg0)); }
	void test_case_1() { string Arr0[] = {"..47..",
 "..74.."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ERROR!"; verify_case(1, Arg1, findOrder(Arg0)); }
	void test_case_2() { string Arr0[] = {"bbb666",
 ".655X5",
 "a65AA5",
 "a65AA5",
 "a65555"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "65AXab"; verify_case(2, Arg1, findOrder(Arg0)); }
	void test_case_32() { string Arr0[] = {"aabbaaaaaaaaaaaaaaaaaa",
 "aabbccccccccccccccaaaa",
 "aab11111ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ddddddddddaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aa.11111DDDDDDDDDDaaaa",
 "aaaaaaaaaaaaaaaaaaaaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ERROR!"; verify_case(3, Arg1, findOrder(Arg0)); }
	void test_case_3() { string Arr0[] = {
 "z9999999999999999999999999999999999999999999999991",
 "2A888888888888888888888888888888888888888888888888",
 "5ABEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEC8",
 "5ADEFGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG8",
 "5ADEJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJHHG8",
 "5ADEJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJHHG8",
 "5ADEJKMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNIIG8",
 "5ADEJLPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPONIIG8",
 "5ADEJLPQSTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTNIIG8",
 "5ADEJLPRUVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVTNIIG8",
 "7ADEJLPRXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXWVTNIIG8",
 "7ADEJLPRXYYYZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZVTNIIG8",
 "7ADEJLPRXYYYZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZVTNIIG8",
 "7ADEJLPRXYYYZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZVTNIIG8",
 "7ADEJLPRXYYYZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZVTNIIG8",
 "7ADEJLPRXaffffffffffffffffffffffffffffffeZZVTNIIG8",
 "7ADEJLPRXbfimnnnnnnnnnnnnnrrrrrrrrrrrrrrqZZVTNIIG8",
 "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8",
 "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8",
 "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8",
 "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8",
 "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8",
 "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8",
 "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8",
 "7ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8",
 "5ADEJLPRXbfj0000000000000nrwwwwwwwwwwwwwwZZVTNIIG8",
 "5ADEJLPRXbfj0000000000000mqwwwwwwwwwwwwwwZZVTNIIG8",
 "5ADEJLPRXbejjjjjjjjjjjjjjjjjjjjjjjjjjjjjiZZVTNIIG8",
 "5ADEJLPRXbcddddddddddddddddddddddddddddddZZVTNIIG8",
 "5ADEJLPRXbgklllllllllllllllllllllllllllldZZVTNIIG8",
 "5ADEJLPRXbhovvvvvvvvvvvvvvvuttttttttttsldZZVTNIIG8",
 "5ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8",
 "5ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8",
 "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8",
 "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8",
 "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8",
 "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8",
 "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8",
 "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8",
 "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8",
 "6ADEJLPRXbhpvyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8",
 "6ADEJLPRXbhpuyyyyyyyyyyyyyyytxxxxxxxxxxldZZVTNIIG8",
 "6ADEJLPRXbhpppppppppppppppposxxxxxxxxxxkdZZVTNIIG8",
 "6ADEJLPRXbhhhhhhhhhhhhhhhhhhhhhhhhhhhhhgcYYVTNIIG8",
 "5ADEJLPRWbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbaYYUSNIIG8",
 "5ADEJLORRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRQMIIG8",
 "5ADEJLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLKIIG8",
 "5ADCHIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIF8",
 "51DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDB8",
 "2333333333333333334444444444444444443333333333333z"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "z123456789ABDCEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmn0opqrstuvwxy"; verify_case(3, Arg1, findOrder(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TopView ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

