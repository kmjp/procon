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

int N;
vector<int> E[2020];
vector<int> D[2020][2020];
int dist[2020][2020];

class JumpDistancesOnTreeEasy {
	public:
	void dfs(int cur,int pre,int base,int d) {
		dist[base][cur]=d;
		D[base][d].push_back(cur);
		FORR(e,E[cur]) if(e!=pre) dfs(e,cur,base,d+1);
	}
	
	string isPossible(vector <int> p, vector <int> S) {
		int i,x,y;
		N=p.size()+1;
		FOR(i,N) E[i].clear();
		FOR(x,N) FOR(y,N) D[x][y].clear();
		FOR(i,p.size()) {
			E[i+1].push_back(p[i]);
			E[p[i]].push_back(i+1);
		}
		
		FOR(i,N) dfs(i,i,i,0);
		
		bitset<2020> A;
		A[0]=1;
		queue<int> Q;
		Q.push(0);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(d,S) FORR(e,D[cur][d]) if(A[e]==0) {
				A[e]=1;
				Q.push(e);
			}
		}
		
		set<int> T;
		FORR(r,S) T.insert(r);
		
		FOR(x,N) FOR(y,N) if(A[x]&&A[y]) T.erase(dist[x][y]);
		
		if(T.empty()) return "Possible";
		return "Impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,1,0,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,1,1,0,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(1, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,1,1,0,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,4,0,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,6,8,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(3, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(4, Arg2, isPossible(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  JumpDistancesOnTreeEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

