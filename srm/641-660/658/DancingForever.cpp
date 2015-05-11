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

template<class V> class MaxFlow_Ford {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 10000;
	vector<edge> E[MV];
	int vis[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	V dfs(int from,int to,V cf) {
		V tf;
		if(from==to) return cf;
		vis[from]=1;
		FORR(e,E[from]) if(vis[e.to]==0 && e.cap>0 && (tf = dfs(e.to,to,min(cf,e.cap)))>0) {
			e.cap -= tf;
			E[e.to][e.reve].cap += tf;
			return tf;
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			ZERO(vis);
			if((tf = dfs(from,to,numeric_limits<V>::max()))==0) return fl;
			fl+=tf;
		}
	}
};

class DancingForever {
	public:
	int vis[203];
	int N;
	string X;
	void dfs(int cur,MaxFlow_Ford<int>& mf) {
		vis[cur]=1;
		FORR(r,mf.E[cur]) if(r.cap>0 && vis[r.to]==0) dfs(r.to,mf);
	}
	
	vector <int> getStablePairs(string X) {
		int i,x,y;
		N=sqrt(X.size()+0.1);
		this->X=X;
		
		MaxFlow_Ford<int> mf,mf2;
		FOR(i,N) mf.add_edge(0,i+1,1);
		FOR(i,N) mf.add_edge(i+101,202,1);
		FOR(x,N) FOR(y,N) if(X[x*N+y]=='Y') mf.add_edge(x+1,y+101,200);
		x=mf.maxflow(0,202);
		
		ZERO(vis);
		if(x==N) {
			FOR(i,N) vis[i+1]=vis[101+i]=1;
		}
		else {
			dfs(0,mf);
		}
		
		vector<int> R;
		FOR(i,N) if(vis[1+i]) mf2.add_edge(0,i+1,1);
		FOR(i,N) if(vis[101+i]) mf2.add_edge(i+101,202,1);
		FOR(x,N) FOR(y,N) if(X[x*N+y]=='Y' && vis[1+x]) mf2.add_edge(x+1,y+101,1);
		mf2.maxflow(0,202);
		FOR(i,N) FORR(r,mf2.E[i+1]) if(vis[1+i] && r.to>=101 && r.cap==0) R.push_back(i),R.push_back(r.to-101);
		
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "YYNNNYYNNNYYYNNY"; int Arr1[] = {0, 0, 1, 1, 2, 2, 3, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getStablePairs(Arg0)); }
	void test_case_1() { string Arg0 = "YNNNYYNNYYNNNNYY"; int Arr1[] = {1, 0, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getStablePairs(Arg0)); }
	void test_case_2() { string Arg0 = "YNYYNYYNY"; int Arr1[] = {1, 0, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getStablePairs(Arg0)); }
	void test_case_3() { string Arg0 = "YYYNNYYYNNNNNYYNNNYYNNNYY"; int Arr1[] = {3, 3, 4, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getStablePairs(Arg0)); }
	//void test_case_4() { string Arg0 = "Y"; int Arr1[] = {0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getStablePairs(Arg0)); }
	void test_case_4() { string Arg0 = "NYNYNNNYYNYNYYYNNYNNNYYNNYNNNNYNNNNYNYYYNNNNNYYYYYNNNYNYYNNNNNYYNNNYNYNNYNNYYYNNYYYYYNNYYYNNNYYNNYNNNYYNYYYNYYNYNYYNNYYYYNYYNNYNYYYYYYYNYNNNNYYYYYYNYYNNNNNYNNYYNNNNNYNNYNNNNNNNYNNNNNNNNNNNYNNNYNNYNNNNNNNNNNNNYNNYNYNNNYYYNNNYNYNNYYYYYYYYYYYYNYYYYYNYNYYNYYYYNNNNYNNNNYYNNYNNNNYNNYNYYYNNNYNNNYNYNYNNNNYNNNYNNYYNYNNYYYYYNNYYNNYYNNNYNNNYNNNNNNNNNNYYNNYYYYNYYYYNYNNNNYNYYYNYNNNYYYNNYNNNYNYYYNYYNYYYNYNYYYNNNYNYYYNNNNYNNNNNYNNNNNNYNYYNYNYNNYYYNNNNYNYNNYNYNNYNNYNNYNNNYNNNNNNNNNNNYNNYNNNNNNYNNNNNNNYNNNNYYNYNYYNNNNYYNNNYNYNNNNNYYYNNNNYYNYNYYNNNYNNYYNNYNYNNNYNYYNNNNYYNNNNNNNYNNYNYNNNYNNYNNNNNNYYNYNNNNYNNNNNYYYYYNNYNNNNNNYYYNYYNNNYNNNYNNYYYYNNNNYYYYYNYYYYYNYYNYNYYYYNYYYNYYNYNNNNNNNNNNYYYYNYYNNYNNYNYYNYNNYNYYNNYYYNNNNNNNNNYYNNYYNYYYNNNNYYNNNYNNYYNYNNYNNNYNNYYNNYNNYNYNNYNNNYYNNNYNNNYNYNNNNNNNYNYYNNNNNNYNNYNYNNNYYNYNNNNYNYNNYNNYNNNNNYNNYNNNYYNYYNYYYNNNYNYNYNYNNNNNNNNNNYNNYYYNNYNYNNNYNNNNNYNYYYNYYNYNNYYYNYYNYYYYNNYYNNYNYYNNNNNNYNYNYYNYNNNYYNYNNNYYYYNYYNNNNYNNNNNNNYYNNYYNYNNNNNNNNNYYYYNYYNNYNNYNNNNYYNYYNNYNYYNNYNYNYYNYYYYYYNYYNYNYYNNNNNNNYNNYYNNNNYYNYNYYYYYYNYYYYYYNYYYNNYYYNYNNNNNNNNNYNNNNNNYNYNNNNNNYNNYNNNYYYNNYNYNNNNNNYNYYYNYNNYYNNNNNNNYNYNNYNYNYYNNYNYNNNNYNYYNNYYNYNYNNNNNNNYNNNYNNNNNYYYNNYYYNYYYYYNYYYYYYNYYYNYYNYYYNYYNYYNYYNNNYYYYYNYYYYNYYYYYNNYYYNNYYYYYYNYYNNNNYYYNNNYNNYNNYNYNYYNYNYNNNYNYNYNNYYNNNYYNYYNNYYYYYYNNYNYNNNYYNYNNYYNNNYNYNNNNYYYYNYYNNNYNNYNNNYYNYNYYNNYYN"; int Arr1[] = {0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getStablePairs(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DancingForever ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
