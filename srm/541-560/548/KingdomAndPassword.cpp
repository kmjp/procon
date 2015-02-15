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


ll mins[1<<17],maxs[1<<17];
ll mint[1<<17],maxt[1<<17];

class KingdomAndPassword {
	int L;
	vector<int> rd;
	ll op,d10[20];
	vector<int> num;
	
	public:
	long long dfs(int mask, ll val) {
		int bt = __builtin_popcount(mask)-1;
		ll best = -1LL<<61;
		int vis[10];
		
		if(mask==0) return val;
		ZERO(vis);
		
		int i;
		FOR(i,L) {
			if((mask & (1<<i))==0) continue;
			if(num[i]==rd[L-1-bt]) continue;
			if(vis[num[i]]) continue;
			vis[num[i]]++;
			
			ll t;
			if(num[i]<num[bt]) t = val + d10[bt]*num[i] + maxs[mask ^ (1<<i)];
			else if(num[i]>num[bt]) t = val + d10[bt]*num[i] + mins[mask ^ (1<<i)];
			else t = dfs(mask ^ (1<<i), val + d10[bt]*num[i]);
			
			if(abs(t)>=1LL<<60) continue;
			//if(bt==L-2) _P("%x %x %lld %lld\n",mask,i,val,t);
			if((abs(best-op) > abs(t-op)) || ((abs(best-op) == abs(t-op))&&op<best))
				best = t;
		}
		if(best<0) return -1LL<<60;
		return best;
	}
	
	long long newPassword(long long oldPassword, vector <int> restrictedDigits) {
		int i,j,x,y,bt;
		L = restrictedDigits.size();
		
		op=oldPassword;
		rd=restrictedDigits;
		
		d10[0]=1;
		FOR(i,L) d10[i+1]=d10[i]*10;
		num.clear();
		FOR(i,L) num.push_back(oldPassword%10),oldPassword/=10;
		
		FOR(i,1<<L) mins[i]=1LL<<60,maxs[i]=-1LL<<60;
		for(y=1;y<=L;y++) {
			FOR(i,1<<L) mint[i]=1LL<<60,maxt[i]=-1LL<<60;
			mint[0]=maxt[0]=0;
			FOR(i,1<<L) {
				bt = y-1-__builtin_popcount(i);
				if(__builtin_popcount(i)==y) mins[i]=mint[i],maxs[i]=maxt[i];
				if(bt<0) continue;
				FOR(x,L) if((i&(1<<x))==0 && num[x]!=rd[L-1-bt]) {
					if(mint[i]!=1LL<<60) {
						mint[i|(1<<x)] = min(mint[i|(1<<x)], mint[i]+num[x]*d10[bt]);
						maxt[i|(1<<x)] = max(maxt[i|(1<<x)], mint[i]+num[x]*d10[bt]);
					}
					if(maxt[i]!=-1LL<<60) {
						mint[i|(1<<x)] = min(mint[i|(1<<x)], maxt[i]+num[x]*d10[bt]);
						maxt[i|(1<<x)] = max(maxt[i|(1<<x)], maxt[i]+num[x]*d10[bt]);
					}
				}
			}
		}
		ll ret = dfs((1<<L)-1,0);
		if(ret<0) return -1;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 548LL; int Arr1[] = {5, 1, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 485LL; verify_case(0, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 7777LL; int Arr1[] = {4, 7, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = -1LL; verify_case(1, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 58LL; int Arr1[] = {4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 58LL; verify_case(2, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 172LL; int Arr1[] = {4, 7, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 127LL; verify_case(3, Arg2, newPassword(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 241529363573463LL; int Arr1[] = {1, 4, 5, 7, 3, 9, 8, 1, 7, 6, 3, 2, 6, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 239676554423331LL; verify_case(4, Arg2, newPassword(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  KingdomAndPassword ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

