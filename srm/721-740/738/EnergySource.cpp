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

vector<int> D[91];
set<vector<int>> vis;

class EnergySource {
	public:
	ll ret,sum;
	
	void dfs(vector<int> V) {
		if(vis.count(V)) return;
		vis.insert(V);
		ll t=1;
		FORR(v,V) t*=v;
		ret++;
		sum+=t;
		
		int i,y;
		FOR(i,V.size()) {
			if(i&&V[i]==V[i-1]) continue;
			int x=V[i];
			if(D[x].empty()) continue;
			FORR(d,D[x]) {
				vector<int> W=V;
				W.erase(W.begin()+i);
				FOR(y,x/d) W.push_back(d);
				sort(ALL(W));
				reverse(ALL(W));
				dfs(W);
			}
		}
		
	}
	
	vector<long long> countDifferentSources(int number) {
		for(int i=1;i<=number;i++) {
			D[i].clear();
			for(int x=1;x<i;x++) if(i%x==0) D[i].push_back(x);
		}
		
		vis.clear();
		vector<int> V;
		V.push_back(number);
		ret=sum=0;
		dfs(V);
		return {ret,sum};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; long Arr1[] = {2, 4 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, countDifferentSources(Arg0)); }
	void test_case_1() { int Arg0 = 10; long Arr1[] = {9, 103 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, countDifferentSources(Arg0)); }
	void test_case_2() { int Arg0 = 1; long Arr1[] = {1, 1 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, countDifferentSources(Arg0)); }
	void test_case_3() { int Arg0 = 90; long Arr1[] = {98014, 45465390986863499 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, countDifferentSources(Arg0)); }
	void test_case_4() { int Arg0 = 48; long Arr1[] = {6978, 9697161469 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, countDifferentSources(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EnergySource ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

