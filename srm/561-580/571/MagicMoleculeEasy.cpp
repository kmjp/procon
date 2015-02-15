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


class MagicMoleculeEasy {
	public:
	int N,K;
	int matc[60];
	ll mat[60];
	vector<int> P,Q;
	vector<pair<int,int> > order;
	int ret,NQ,NO;
	int tt,tt2;
	int tsum[5][1024];
	
	void check(int left,ll mask) {
		int x,y,cp=0;
		
		if(left>0) cp += Q[left-1];
		
		tt++;
		cp += tsum[0][mask & 1023] + tsum[1][(mask>>10) & 1023] +
		tsum[2][(mask>>20) & 1023] +tsum[3][(mask>>30) & 1023] +tsum[4][(mask>>40) & 1023];
		if(cp<ret) return;
		FOR(x,N) {
			if(mask & (1LL<<x)) continue;
			else if(mat[x] & ~mask) return;
		}
		tt2++;
		ret = max(cp,ret);
	}
	
	void dfs(int ind,ll mask, ll mask2) {
		int x,y,ng=0,cp=0,left;
		int cur;
		
		left = K-__builtin_popcountll(mask);
		if(left<0) return;
		if(ind>=NO) {
			if(left>=0 && left<=NQ) check(left,mask);
			return;
		}
		if(left==0) {
			check(left,mask);
			return;
		}
		
		cur = order[ind].second;
		
		//‘S•”Žæ‚Á‚Äƒ_ƒ‚È‚ç‚à‚¤’Ç‚¢‚©‚¯‚È‚¢
		ll tmask=((1LL<<N)-1) & (mask | ~mask2);
		x=min(NQ,left);
		if(x>0) cp = Q[x-1];
		cp = tsum[0][tmask & 1023] + tsum[1][(tmask>>10) & 1023] +
		tsum[2][(tmask>>20) & 1023] +tsum[3][(tmask>>30) & 1023] +tsum[4][(tmask>>40) & 1023];
		if(cp<=ret) return;
		
		if(!(mask&(1LL<<cur))) {
			// ‚±‚ê‚ðŽæ‚ç‚¸‚Éok‚©H
			if((mask2 & mat[cur] & ~mask)==0) dfs(ind+1,mask | mat[cur], mask2 | (1LL<<cur));
			
			mask |= 1LL<<cur;
			left--;
		}
		
		if(left>=0 && left<=NQ) check(left,mask);
		if(left>0) dfs(ind+1, mask, mask2 | (1LL<<cur));
	}
	
	int maxMagicPower(vector <int> mP, vector <string> mB, int k) {
		
		P=mP;
		N=mP.size();
		K=k;
		ret=-1;
		tt=tt2=0;
		int x,y;
		ZERO(mat);
		FOR(x,N) FOR(y,N) if(mB[x][y]=='Y') mat[x]|=1LL<<y;
		FOR(x,N) matc[x]=__builtin_popcountll(mat[x]);
		Q.clear();
		order.clear();
		FOR(x,N) if(mat[x]==0) Q.push_back(P[x]);
		FOR(x,N) if(mat[x]) order.push_back(make_pair(mat[x],x));
		
		sort(Q.begin(),Q.end());
		reverse(Q.begin(),Q.end());
		
		//sort(order.begin(),order.end());
		//reverse(order.begin(),order.end());
		
		ZERO(tsum);
		FOR(x,N) {
			FOR(y,1024) {
				if(y & (1<<(x%10))) tsum[x/10][y] += P[x];
			}
		}
		
		NQ=Q.size();
		NO=order.size();
		for(x=1;x<=NQ-1;x++) Q[x]+=Q[x-1];
		dfs(0,0,0);
		_P("%d %d\n",tt,tt2);
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NY",
 "YN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {100, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 200; verify_case(2, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_13() { int Arr0[] = {4, 7, 5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNY",
 "YNYN",
 "NYNY",
 "YNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 15; verify_case(3, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {46474, 60848, 98282, 58073, 42670, 50373}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNNY", "YNNYNY", "NNNYYY", "NYYNNN", "NNYNNN", "YYYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 209503; verify_case(4, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYYYNYYNYNNY", "NNYNYYYYYYYNY", "YYNYYNYYYYYYY", "YNYNYYNYYYYYY",
 "YYYYNNYYYYYNY", "NYNYNNYYYYYNN", "YYYNYYNYYYYYY", "YYYYYYYNYNYYY",
 "NYYYYYYYNYYYY", "YYYYYYYNYNNNN", "NYYYYYYYYNNYN", "NNYYNNYYYNYNN", "YYYYYNYYYNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = -1; verify_case(5, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NN", "NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(6, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_17() { int Arr0[] = {1,1,2,5,2,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNNNNN","NNYNNNN","NYNNNYN","NNNNNNY","NNNNNNN","NNYNNNN","NNNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 11; verify_case(7, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {14, 32, 70, 32, 20, 29, 35, 30, 18, 48, 82, 95, 75, 1, 59, 83, 69, 85, 9, 23, 12, 48, 79, 15, 3, 87}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYYYYYYYYYYYYYYYYYYYYYYYYY", "YNYYYYYYYYYYYYYYYYYYYYYYYY", "YYNYYYYYYYYYYYYYYYYYYYYYYY", "YYYNYYYYYYYYYYYYYYYYYYYYYY", "YYYYNYYYYYYYYYYYYYYYYYYYYY", "YYYYYNYYYYYYYYYYYYYYYYYYYY", "YYYYYYNYYYYYYYYYYYYYYYYYYY", "YYYYYYYNYYYYYYYYYYYYYYYYYY", "YYYYYYYYNYYYYYYYYYYYYYYYYY", "YYYYYYYYYNYYYYYYYYYYYYYYYY", "YYYYYYYYYYNYYYYYYYYYYYYYYY", "YYYYYYYYYYYNYYYYYYYYYYYYYY", "YYYYYYYYYYYYNYYYYYYYYYYYYY", "YYYYYYYYYYYYYNYYYYYYYYYYYY", "YYYYYYYYYYYYYYNYYYYYYYYYYY", "YYYYYYYYYYYYYYYNYYYYYYYYYY", "YYYYYYYYYYYYYYYYNYYYYYYYYY", "YYYYYYYYYYYYYYYYYNYYYYYYYY", "YYYYYYYYYYYYYYYYYYNYYYYYYY", "YYYYYYYYYYYYYYYYYYYNYYYYYY", "YYYYYYYYYYYYYYYYYYYYNYYYYY", "YYYYYYYYYYYYYYYYYYYYYNYYYY", "YYYYYYYYYYYYYYYYYYYYYYNYYY", "YYYYYYYYYYYYYYYYYYYYYYYNYY", "YYYYYYYYYYYYYYYYYYYYYYYYNY", "YYYYYYYYYYYYYYYYYYYYYYYYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; int Arg3 = -1; verify_case(3, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_7() { int Arr0[] = {647, 1476, 2444, 6712, 6972, 6989, 7693, 9754, 10216, 11827, 12281, 14586, 15946, 16423, 18190, 22491, 27866, 28706, 31940, 32259, 32489, 35063, 35273, 35688, 36609, 36754, 37731, 38482, 38638, 40309, 45444, 47180, 49983, 50052, 51210, 68122, 68573, 71055, 71538, 78995, 79115, 80864, 82341, 86939, 87265, 88435, 89925, 95539}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNNNNNNNYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NYYYYYYYNYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYY", "YYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYNYYYYNYYYYYYYY", "YYYYYYYYYYNNYYYNYYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYY", "NNNNNNNNYYNNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYNNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "YYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNNNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "YYYYYYYYYYYYYYYYYYYYNYYYNYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNNYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYNYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "YYYNYYYYYYYYYYYYYNYYYYYYYYYYYYNYYYYNYYYYYYYYYYYY", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYNNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYNYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYNYYY", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN", "NNNNNNNNYYYNNNNNYNNNNNNNYNNNNNNNNNNYNNNNNNNNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; int Arg3 = 857344; verify_case(7, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	
// END CUT HERE
};


// BEGIN CUT HERE
int main(int argc, char** argv) {
  MagicMoleculeEasy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
