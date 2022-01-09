#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


vector<int> E[96];
vector<int> cand[96];
int vis[96];


class ConnectTheWorld {
	public:
	int MAX;
	void dfs(int cur,int start) {
		if(vis[cur]) return;
		vis[cur]=1;
		int i;
		FOR(i,MAX-E[cur].size()) cand[start].push_back(cur);
		FORR(e,E[cur]) dfs(e,start);
	}
	
	vector <string> connect(vector <string> terminalA, vector <string> terminalB, vector <string> isolated) {
		map<string,int> M;
		MAX=0;
		FORR(a,terminalA) M[a]++;
		FORR(a,terminalB) M[a]++;
		FORR(a,isolated) M[a]=0;
		
		vector<string> C;
		map<int,int> num;
		FORR(m,M) {
			if(m.second) num[m.second]++;
			MAX=max(MAX,m.second);
			M[m.first]=C.size();
			E[M[m.first]].clear();
			cand[M[m.first]].clear();
			C.push_back(m.first);
		}
		cout<<MAX<<endl;
		int i;
		FOR(i,terminalA.size()) {
			E[M[terminalA[i]]].push_back(M[terminalB[i]]);
			E[M[terminalB[i]]].push_back(M[terminalA[i]]);
		}
		
		ZERO(vis);
		priority_queue<pair<int,int>> con;
		FOR(i,C.size()) if(vis[i]==0) {
			dfs(i,i);
			con.push({cand[i].size(),i});
		}
		
		vector<string> R;
		while(con.size()>1) {
			int x=con.top().second;
			con.pop();
			int y=con.top().second;
			con.pop();
			if(cand[x].empty()||cand[y].empty()) return {};
			R.push_back(C[cand[x].back()]);
			R.push_back(C[cand[y].back()]);
			cand[x].pop_back();
			cand[y].pop_back();
			FORR(a,cand[y]) cand[x].push_back(a);
			con.push({cand[x].size(),x});
		}
		
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Paris", "Paris"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"London", "NYC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Dhaka"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"London", "Dhaka" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"Tokyo", "Prague"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Sydney", "Bern"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"Tokyo", "Prague", "Bern"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Sydney", "Bern", "Vienna"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"Tokyo", "Prague" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"Madrid"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Porto"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Bogota", "Lima", "Kigali", "Ottawa", "Manila"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"BRNO", "Brno"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Brno", "brno"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"brNO", "bRNo"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"BRNO", "bRNo", "brNO", "brno" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, connect(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ConnectTheWorld ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

