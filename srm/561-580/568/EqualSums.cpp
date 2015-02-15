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

typedef signed long long ll;
typedef unsigned long long ull;

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

ll mo=1000000007;

class EqualSums {
	int N;
	vector <string> B;
	int vis[101];
	int num[101];
	public:
	
	int okok(int cur) {
		int ok=1;
		int x,y,z;
		
		vis[cur]++;
		if(cur<N) {
			// row
			FOR(x,N) {
				if(B[cur][x]=='-') continue;
				z=B[cur][x]-'0'-num[cur];
				if(z<0) return 0;
				
				if(num[x+N]==-1) {
					num[x+N]=z;
					if(okok(x+N)==0) return 0;
				}
				else if(num[x+N]!=z) return 0;
			}
		}
		else {
			// col
			cur-=N;
			FOR(y,N) {
				if(B[y][cur]=='-') continue;
				z=B[y][cur]-'0'-num[cur+N];
				if(z<0) return 0;
				
				if(num[y]==-1) {
					num[y]=z;
					if(okok(y)==0) return 0;
				}
				else if(num[y]!=z) return 0;
			}
		}
		return 1;
	}
	
	
	int count(vector <string> board) {
		int y,x,x2,y2,l,i;
		ll tot=1,totz=1;
		N=board.size();
		B=board;
		
		ZERO(vis);
		FOR(i,2*N) {
			if(vis[i]) continue;
			
			int z=0,noz=0;
			
			FOR(x,10) {
				fill(num,num+2*N,-1);
				num[i]=x;
				if(okok(i)) {
					y=0;
					FOR(l,N) if(num[l]==0) y++;
					if(y) z++;
					else noz++;
				}
			}
			tot=(tot*(noz+z)) % mo;
			totz=(totz*noz) % mo;
		}
		
		return (tot+mo-totz)%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1-",
 "-2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"123",
 "4--",
 "--9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"9--",
 "-9-",
 "--9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 271; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"11",
 "12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"-4--",
 "-0-2",
 "--1-",
 "4---"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(4, Arg1, count(Arg0)); }
	void test_case_5() { string Arr0[] = {"--2",
 "02-",
 "-10"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, count(Arg0)); }
	void test_case_6() { string Arr0[] = {"----------1---------------0-----7-----------------",
 "-----4--------------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------2----------1-------------------------------",
 "-----4--------------------------------------------",
 "-----3--------------------------------------------",
 "-6----------5-------------------------------------",
 "-------------------------------7---5----------6---",
 "--------6-------------6-4---6---------------7-----",
 "-------------4----------------5-------------------",
 "3------------------------------------------6------",
 "3------------------------------------------6------",
 "-------------4----------------5-------------------",
 "---------------2-------------------------3--------",
 "--2------------------------------------------2----",
 "---8---------------1-------------------3----------",
 "---------------3----------------------------------",
 "----7----------------5---0-----------------------5",
 "----------------5-------------------------3-----1-",
 "----------1---------------0-----7-----------------",
 "-------------5----------------6-------------------",
 "-7----------6-------------------------------------",
 "---8---------------1-------------------3----------",
 "-----------------------3--------------------------",
 "----8----------------6---1-----------------------6",
 "------------------------------------------4-----2-",
 "-----------5---------------5----------------------",
 "-----------------------------6--------------------",
 "----8----------------6---1-----------------------6",
 "----------------5-------------------------3-----1-",
 "-------------------------------6---4--2-------5---",
 "-6----------5-------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------------5----------------6-------------------",
 "-----3--------------------------------------------",
 "---------------2-------------------------3--------",
 "---------4---------------------------6------------",
 "-------------------------------6---4--2-------5---",
 "------2-------------1------------22---------------",
 "--------5-------------5-3---5---------------6-----",
 "-----------5--3------------5----------------------",
 "--2------------------------------------------2----",
 "---------5---------------------------7------------",
 "-------------4----------------5-------------------",
 "-----------------5------------------4---6------2--",
 "-------------------------------6---4--2-------5---",
 "-----------------------2--------------------------",
 "----------------6-------------------------4-----2-", 
 "-------------------------------6---4--2-------5---",
 "--------5-------------5-3---5---------------6-----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 45094393; verify_case(6, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  EqualSums ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
