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


class EllysBulls {
	public:
	int N,L;
	string res;
	map<string, vector<string> > FF,LL;
	vector<string> G;
	ll dig[10];
	
	string getNumber(vector <string> guesses, vector <int> bulls) {
		G=guesses;
		N=guesses.size();
		L=guesses[0].size();
		int i,x,y,z;
		char hoge[10];
		string res="Liar";
		
		dig[0]=1;
		FOR(i,9) dig[i+1]=dig[i]*10;
		ZERO(hoge);
		FF.clear();
		LL.clear();
		
		if(L<=5) {
			int num=-1;
			
			FOR(i,dig[L]) {
				FOR(x,L) hoge[x]='0'+(i/dig[x])%10;
				int ng=0;
				FOR(x,N) {
					z=bulls[x];
					FOR(y,L) if(G[x][y]==hoge[y]) z--;
					if(z!=0) ng++;
				}
				
				if(ng==0) {
					if(res!="Liar") return "Ambiguity";
					res=string(hoge);
				}
			}
		}
		else {
			//‘O”¼5ƒPƒ^
			char Bs[100];
			
			FOR(i,dig[5]) {
				FOR(x,5) hoge[x]='0'+(i/dig[x])%10;
				FOR(x,N) Bs[x]='0'+bulls[x];
				Bs[N]=0;
				
				int ng=0;
				FOR(x,N) {
					FOR(y,5) if(G[x][y]==hoge[y]) Bs[x]--;
					if(Bs[x]<'0') ng++;
				}
				
				if(ng==0) FF[string(Bs)].push_back(string(hoge));
			}
			
			//Œã”¼
			ZERO(hoge);
			FOR(i,dig[L-5]) {
				FOR(x,L-5) hoge[x]='0'+(i/dig[x])%10;
				FOR(x,N) Bs[x]='0';
				Bs[N]=0;
				
				int ng=0;
				FOR(x,N) {
					FOR(y,L-5) if(G[x][5+y]==hoge[y]) Bs[x]++;
					if(Bs[x]>bulls[x]+'0') ng++;
				}
				if(ng==0) LL[string(Bs)].push_back(string(hoge));
			}
			
			int num=0;
			for(map<string, vector<string> >::iterator mit=FF.begin();mit!=FF.end();mit++) {
				map<string, vector<string> >::iterator mit2=LL.find(mit->first);
				
				if(mit2==LL.end()) continue;
				num += mit->second.size() * mit2->second.size();
				if(num>=2) return "Ambiguity";
				res = mit->second[0] + mit2->second[0];
			}
		}
		
		
		
		return res;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1337"; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0000", "1111", "2222"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Liar"; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"666666", "666677", "777777", "999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Ambiguity"; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"000", "987", "654", "321", "100", "010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 0, 0, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "007"; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"28", "92", "70", "30", "67", "63", "06", "65",
 "11", "06", "88", "48", "09", "65", "48", "08"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "54"; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_51() { string Arr0[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
 "4166623", "1166638", "2767693", "8650248", "2486509",
 "6138934", "4018642", "6236742", "2961643", "8407361",
 "2097376", "6575410", "6071777", "3569948", "2606380"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "4266642"; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"00000000", "10000001", "07000008", "02000020", "00600070", "00300300", "00050600", "00044000", "80005000", "87654321"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "12345678"; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  EllysBulls ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
