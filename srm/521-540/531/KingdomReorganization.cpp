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
	static const int ufmax=502;
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

class KingdomReorganization {
	vector<string> K;
	int B[51][51],D[51][51];
	int N;
	UF duf;
	
	public:
	int prune(int cur) {
		int x,y,r=0;
		FOR(x,N) FOR(y,N) if(duf[x]==cur && K[x][y]=='1' && x<y) r+=D[x][y];
		UF uf;
		
		while(1) {
			int ma=-1;
			int ne=-1;
			
			FOR(x,N) FOR(y,N) if(uf[x]==uf[cur] && uf[y]!=uf[cur] && K[x][y]=='1') {
				if(ma < D[x][y]) ma=D[x][y], ne=y;
			}
			if(ne==-1) break;
			r -= ma;
			uf.unite(ne,cur);
		}
		return r;
	}
	
	int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
		K=kingdom;
		N=K.size();
		int x,y,r=0;
		
		duf.init();
		FOR(x,N) FOR(y,N) {
			if(build[x][y]>='a') B[x][y]=build[x][y]-'a'+26;
			else B[x][y]=(build[x][y]-'A');
			if(destroy[x][y]>='a') D[x][y]=destroy[x][y]-'a'+26;
			else D[x][y]=(destroy[x][y]-'A');
		}
		FOR(x,N) FOR(y,N) if(K[x][y]=='1') duf.unite(x,y);
		FOR(x,N) if(duf[x]==x) r+=prune(x);
		
		while(1) {
			int mi=10000;
			int ne=-1;
			
			FOR(x,N) FOR(y,N) if(duf[x]==duf[0] && duf[y]!=duf[0]){
				if(mi>B[x][y]) mi=B[x][y], ne=y;
			}
			
			if(ne==-1) return r;
			r+=mi;
			duf.unite(0,ne);
		}
		return r;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABD","BAC","DCA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABD","BAC","DCA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"011","101","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABD","BAC","DCA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABD","BAC","DCA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"011000","101000","110000","000011","000101","000110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(2, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"0001","0001","0001","1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AfOj","fAcC","OcAP","jCPA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AWFH","WAxU","FxAV","HUVA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(4, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 65; verify_case(5, Arg3, getCost(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  KingdomReorganization ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

