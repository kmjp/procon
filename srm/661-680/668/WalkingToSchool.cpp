#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class WalkingToSchool {
	public:
	vector<int> E[2020];
	int dist[2][2020];
	int pre[2020];
	
	
	string canWalkExactly(int N, vector <int> from, vector <int> to) {
		int i;
		FOR(i,N) E[i].clear(),dist[0][i]=dist[1][i]=5050;
		FOR(i,from.size()) E[from[i]].push_back(to[i]);
		
		dist[0][0]=dist[1][1]=0;
		queue<int> Q;
		Q.push(0);
		Q.push(10001);
		while(Q.size()) {
			int cur=Q.front()%10000;
			int ph=Q.front()/10000;
			Q.pop();
			FORR(tar,E[cur]) if(dist[ph][tar]>dist[ph][cur]+1) {
				dist[ph][tar]=dist[ph][cur]+1;
				Q.push(ph*10000 + tar);
			}
		}
		if(dist[0][1]>5000 || dist[1][0]>5000) return "Chores";
		
		int par=dist[0][1]+dist[1][0];
		
		vector<int> S;
		S.push_back(0);
		
		ZERO(pre);
		for(i=1;i<=5000;i++) {
			vector<int> S2;
			FORR(r,S) FORR(r2,E[r]) if(pre[r2]<i) {
				if(r2==0) par=__gcd(par,i);
				else S2.push_back(r2), pre[r2]=i;
			}
			swap(S,S2);
		}
		
		return par==1?"Freedom":"Chores";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Chores"; verify_case(0, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0, 1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0, 2, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Freedom"; verify_case(1, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {0, 2, 2, 3, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 3, 0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Chores"; verify_case(2, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 5, 5, 5, 6, 6, 6, 7, 8, 9, 9, 9, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 5, 6, 7, 9, 4, 6, 0, 1, 3, 8, 4, 6, 1, 4, 8, 1, 7, 8, 1, 4, 2, 5, 6, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Chores"; verify_case(3, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 8; int Arr1[] = {0, 1, 4, 6, 7, 5, 2, 3, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 4, 6, 7, 5, 2, 3, 0, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Freedom"; verify_case(4, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 2000; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Chores"; verify_case(5, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WalkingToSchool ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
