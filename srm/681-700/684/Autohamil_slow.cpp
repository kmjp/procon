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

class SCC {
public:
	static const int MV = 55;
	vector<vector<int> > SC; int NV,GR[MV],rev[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu); rev[cu]=ind;
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};

class Autohamil {
	public:
	int N;
	vector<int> E[51];
	vector<ll> M[51];
	
	string check(vector <int> z0, vector <int> z1) {
		int i,j;
		SCC sb;
		
		N=z0.size();
		sb.init(N);
		FOR(i,N) {
			sb.add_edge(i,z0[i]);
			if(z0[i]!=z1[i]) sb.add_edge(i,z1[i]);
			E[i].clear();
			M[i].clear();
		}
		sb.scc();
		
		FOR(i,N) {
			if(sb.rev[i]!=sb.rev[z0[i]]) E[sb.rev[i]].push_back(sb.rev[z0[i]]);
			if(sb.rev[i]!=sb.rev[z1[i]] && sb.rev[z0[i]]!=sb.rev[z1[i]]) E[sb.rev[i]].push_back(sb.rev[z1[i]]);
		}
		N=sb.SC.size();
		
		int in[51]={};
		FOR(i,N) FORR(r,E[i]) in[r]++;
		queue<int> Q;
		if(in[sb.rev[0]]==0) {
			M[sb.rev[0]].push_back(1LL<<sb.rev[0]);
			Q.push(sb.rev[0]);
		}
		
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			
			sort(M[cur].begin(),M[cur].end());
			FOR(i,M[cur].size()-1) if(M[cur][i] & ~M[cur].back()) return "Does not exist";
			ll nmask=M[cur].back() | (1LL<<cur);
			if(nmask==(1LL<<N)-1) return "Exists";
			
			FORR(r,E[cur]) {
				M[r].push_back(nmask);
				if(--in[r]==0) Q.push(r);
			}
		}
		
		return "Does not exist";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Does not exist"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Exists"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Exists"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Does not exist"; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,2,0,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,0,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Exists"; verify_case(4, Arg2, check(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,2,0,4,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,5,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Exists"; verify_case(5, Arg2, check(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {1,2,0,4,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,5,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Does not exist"; verify_case(6, Arg2, check(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Autohamil ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
