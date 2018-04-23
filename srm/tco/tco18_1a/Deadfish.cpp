#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll cost[4040400];

class Deadfish {
	public:
	int change(int v) {
		if(v==0) return 0;
		vector<int> C;
		while(v) {
			C.push_back(v%10);
			v/=10;
		}
		sort(ALL(C));
		reverse(ALL(C));
		v=0;
		FORR(c,C) v=v*10+c;
		return v;
		
	}
	int shortestCode(int N) {
		int i;
		FOR(i,1040000) cost[i]=1LL<<60;
		cost[0]=0;
		queue<int> Q;
		Q.push(0);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			ll co=cost[cur];
			if(cur+1<=1000000 && cost[cur+1]>co+1) {
				cost[cur+1]=co+1;
				Q.push(cur+1);
			}
			if(cur>0 && cost[cur-1]>co+1) {
				cost[cur-1]=co+1;
				Q.push(cur-1);
			}
			if(cur<=1000 && cost[cur*cur]>co+1) {
				cost[cur*cur]=co+1;
				Q.push(cur*cur);
			}
			int x=change(cur);
			if(x<=1000000 && cost[x]>co+1) {
				cost[x]=co+1;
				Q.push(x);
			}
			
		}
		return cost[N];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; verify_case(0, Arg1, shortestCode(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; verify_case(1, Arg1, shortestCode(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 5; verify_case(2, Arg1, shortestCode(Arg0)); }
	void test_case_3() { int Arg0 = 61; int Arg1 = 5; verify_case(3, Arg1, shortestCode(Arg0)); }
	void test_case_4() { int Arg0 = 200000; int Arg1 = 207; verify_case(4, Arg1, shortestCode(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Deadfish ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

