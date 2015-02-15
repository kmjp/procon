#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

//-------------------------------------------------------

class RandomGraph {
	public:
	int N;
	map<int,double> memo;
	double con[4];
	
	double dfs(int cur, int num) {
		if(cur>=N) return 1;
		int key=cur*1000000+num;
		if(memo.find(key)!=memo.end()) return memo[key];
		
		int nn[3]={num%100,num/100%100,num/10000};
		vector<int> V;
		int i,x,y;
		FOR(i,nn[0]) V.push_back(1);
		FOR(i,nn[1]) V.push_back(2);
		FOR(i,nn[2]) V.push_back(3);
		
		double ret=0;
		// pick 0
		double tp=0;
		double prob=1;
		FOR(i,V.size()) prob *= (1-con[V[i]]);
		tp=prob;
		ret += prob*dfs(cur+1,num+1);
		// pick 1
		FOR(i,V.size()) {
			double np=prob/(1-con[V[i]])*con[V[i]];
			if(V[i]==1) ret += np*dfs(cur+1,num-1+100);
			if(V[i]==2) ret += np*dfs(cur+1,num-100+10000);
		}
		// pick 2
		FOR(x,V.size()) for(y=x+1;y<V.size();y++) {
			double np=prob/(1-con[V[x]])/(1-con[V[y]])*con[V[x]]*con[V[y]];
			if(V[x]==1 && V[y]==1) ret += np*dfs(cur+1,num-2+10000);
		}
		return memo[key]=ret;
	}
	
	
	double probability(int n, int p) {
		int x,y,z;
		
		if(p==1000) return (n>=3);
		
		N=n;
		double P=p/1000.0;
		
		con[1]=1-(1-P);
		con[2]=1-(1-P)*(1-P);
		con[3]=1-(1-P)*(1-P)*(1-P);
		
		memo.clear();
		return 1-dfs(1,1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 0; double Arg2 = 0.0; verify_case(0, Arg2, probability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 620; double Arg2 = 0.0; verify_case(1, Arg2, probability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 500; double Arg2 = 0.59375; verify_case(2, Arg2, probability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 100; double Arg2 = 0.33566851611343496; verify_case(3, Arg2, probability(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 15; int Arg1 = 50; double Arg2 = 0.5686761670525845; verify_case(4, Arg2, probability(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 10; double Arg2 = 0.7494276522159893; verify_case(5, Arg2, probability(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 50; int Arg1 = 1000; double Arg2 = 1.0; verify_case(6, Arg2, probability(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RandomGraph ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
