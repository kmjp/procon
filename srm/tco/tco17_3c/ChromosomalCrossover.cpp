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

template<class V> class MaxFlow_Ford {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 205;
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

class ChromosomalCrossover {
	public:
	int maximalLength(string A, string B) {
		int N=A.size();
		
		int ma=0,x,y;
		FOR(x,N) {
			for(int len=1;x+len<=N;len++) {
				if(A[x+len-1]!=B[x+len-1]) break;
				ma=max(ma,len);
			}
		}
		FOR(y,N) FOR(x,y) {
			int dif=y-x;
			for(int len=ma+1;y+len<=N;len++) {
				MaxFlow_Ford<int> mf;
				for(int i=x;i<y+len;i++) {
					if(i%(2*dif)<dif) {
						if(i<y || i>=x+len) {
							mf.add_edge(200,i,1);
						}
						else {
							mf.add_edge(200,i,2);
						}
						mf.add_edge(i,100+i*2,1);
						mf.add_edge(i,100+i*2+1,1);
						
						if(i-dif>=x) {
							if(A[i]==A[i-dif]) mf.add_edge(100+i*2,100+(i-dif)*2,1);
							if(B[i]==A[i-dif]) mf.add_edge(100+i*2+1,100+(i-dif)*2,1);
							if(A[i]==B[i-dif]) mf.add_edge(100+i*2,100+(i-dif)*2+1,1);
							if(B[i]==B[i-dif]) mf.add_edge(100+i*2+1,100+(i-dif)*2+1,1);
						}
						if(i+dif<y+len) {
							if(A[i]==A[i+dif]) mf.add_edge(100+i*2,100+(i+dif)*2,1);
							if(B[i]==A[i+dif]) mf.add_edge(100+i*2+1,100+(i+dif)*2,1);
							if(A[i]==B[i+dif]) mf.add_edge(100+i*2,100+(i+dif)*2+1,1);
							if(B[i]==B[i+dif]) mf.add_edge(100+i*2+1,100+(i+dif)*2+1,1);
						}
					}
					else {
						if(i<y || i>=x+len) {
							mf.add_edge(i,201,1);
						}
						else {
							mf.add_edge(i,201,2);
						}
						mf.add_edge(100+i*2,i,1);
						mf.add_edge(100+i*2+1,i,1);
					}
				}
				int ret=mf.maxflow(200,201);
				if(ret==len) {
					ma=len;
				}
				else break;
			}
		}
		
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAAA"; string Arg1 = "TCGTCG"; int Arg2 = 3; verify_case(0, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAA"; string Arg1 = "CCC"; int Arg2 = 2; verify_case(1, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ATCGATCGATCG"; string Arg1 = "ATCGATCGATCG"; int Arg2 = 12; verify_case(2, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AAAAATTTTTCCCCCGGGGG"; string Arg1 = "ACTTCATGTGCTAGCTGTAG"; int Arg2 = 4; verify_case(3, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "A"; string Arg1 = "G"; int Arg2 = 0; verify_case(4, Arg2, maximalLength(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChromosomalCrossover ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

