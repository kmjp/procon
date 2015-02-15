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
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int NUM[52][52];
ll comb(int P_,int Q_) {
	static const int N_=102;
	static ll C_[N_][N_];
	if(Q_<0 || P_<Q_) return 0;
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
	}
	return C_[P_][Q_];
}

class Excavations {
	int N;
	vector<int> D[51];
	int F[51];
	public:
	
	void uniq(vector<int>& DD) {
		vector<int> VV=DD;
		sort(VV.begin(),VV.end());
		VV.erase(unique(VV.begin(),VV.end()),VV.end());
		int i,j,k;
		FOR(i,DD.size()) {
			k=DD[i];
			FOR(j,VV.size()) if(k==VV[j]) DD[i]=j+1;
		}
	}
	
	ll dfs(int depth, int left) {
		vector<pair<int,int> > V;
		ll dp[51][51];
		int i,j,k,l;
		FOR(i,51) if(F[i]) {
			if(NUM[i][depth]==0) return 0;
			V.push_back(make_pair(NUM[i][depth],NUM[i][51]));
		}
		ZERO(dp);
		dp[0][left]=1;
		FOR(i,V.size()) {
			int j=V[i].second;
			for(k=1;k<=j;k++) {
				for(l=k;l<=left-i;l++) {
					// j個中から、k個選ぶが、先頭V[i].firstから１個以上選びたい
					dp[i+1][l-k] += (comb(j,k)-comb(j-V[i].first,k))*dp[i][l];
				}
			}
		}
		return dp[V.size()][0];
	}
	
	long long count(vector <int> kind, vector <int> depth, vector <int> found, int K) {
		int i,j,k;
		map<int,int> cand;
		
		N=kind.size();
		ZERO(F);
		uniq(depth);
		FOR(i,51) D[i].clear();
		ZERO(NUM);
		
		FOR(i,found.size()) F[found[i]]=1;
		FOR(i,N) {
			if(F[kind[i]]) {
				D[kind[i]].push_back(depth[i]);
				NUM[kind[i]][depth[i]]++;
			}
			else {
				cand[depth[i]]++;
				D[0].push_back(depth[i]);
			}
		}
		
		FOR(i,51) FOR(j,51) NUM[i][j+1]+=NUM[i][j];
		
		FOR(i,51) sort(D[i].begin(),D[i].end());
		ll ret=0;
		// no nofound
		if(K<=N-D[0].size()) ret += dfs(51,K);
		int tot=0;
		ITR(mit,cand) {
			for(i=1;i<=mit->second;i++) {
				for(j=0;j<=min(K-i,(int)D[0].size()-(tot+mit->second));j++) {
					int left=K-(i+j);
					if(left>=found.size() && left<=N-D[0].size()) {
						ll dd=dfs(mit->first-1,left);
						ret += comb(mit->second,i)*comb((int)D[0].size()-(tot+mit->second),j) * dd;
					}
				}
			}
			tot+=mit->second;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 15, 10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 3LL; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 15, 10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 4LL; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 10, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; long long Arg4 = 0LL; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2, 2, 3, 1, 3, 2, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12512, 12859, 125, 1000, 99, 114, 125, 125, 114}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; long long Arg4 = 35LL; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_42() { int Arr0[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 18; long long Arg4 = 9075135300LL; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {43, 45, 44, 43, 43, 10, 2, 9, 43, 45, 24, 32, 22, 11, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {11694, 13945, 22571, 13945, 96402, 46728, 46728, 30230, 18506, 25194, 96402, 61113, 46728, 13945, 32825}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {11,43}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 13; long long Arg4 = 13LL; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  Excavations ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
