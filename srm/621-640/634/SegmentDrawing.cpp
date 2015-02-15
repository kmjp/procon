#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 1100;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	
	void add_edge(int x,int y,V cap) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,0}); /* rev edge */
	}
	
	void bfs(int cur) {
		MINUS(lev);
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			ITR(e,E[v]) if(e->cap>0 && lev[e->to]<0) lev[e->to]=lev[v]+1, q.push(e->to);
		}
	}
	
	int dfs(int from,int to,V cf) {
		if(from==to) return cf;
		ITR(e,E[from]) if(e->cap>0 && lev[from]<lev[e->to]) {
			V f=dfs(e->to,to,min(cf,e->cap));
			if(f>0) {
				e->cap-=f;
				E[e->to][e->reve].cap += f;
				return f;
			}
		}
		return 0;
	}
	
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			bfs(from);
			if(lev[to]<0) return fl;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
	}
};

class SegmentDrawing {
	public:
	int N;
	ll X[21],Y[21];
	
	int cross(int a,int b,int c,int d) {
		ll XX[3],YY[3];
		XX[0]=X[b]-X[a]; YY[0]=Y[b]-Y[a];
		XX[1]=X[c]-X[a]; YY[1]=Y[c]-Y[a];
		XX[2]=X[d]-X[a]; YY[2]=Y[d]-Y[a];
		ll c1=XX[0]*YY[1]-XX[1]*YY[0];
		ll c2=XX[0]*YY[2]-XX[2]*YY[0];
		if(c1*c2>0) return 0;
		XX[0]=X[d]-X[c]; YY[0]=Y[d]-Y[c];
		XX[1]=X[a]-X[c]; YY[1]=Y[a]-Y[c];
		XX[2]=X[b]-X[c]; YY[2]=Y[b]-Y[c];
		c1=XX[0]*YY[1]-XX[1]*YY[0];
		c2=XX[0]*YY[2]-XX[2]*YY[0];
		if(c1*c2>0) return 0;
		return 1;
	}
	
	int maxScore(vector <int> x_, vector <int> y_, vector <int> redScore, vector <int> blueScore) {
		N=x_.size();
		int x,y,a,b,c,d,i;
		FOR(x,N) X[x]=x_[x],Y[x]=y_[x];
		
		ll tot=0;
		MaxFlow_dinic<int> mf;
		FOR(a,N) for(b=a+1;b<N;b++) {
			tot+=redScore[a*N+b]+blueScore[a*N+b];
			mf.add_edge(0,2+a*20+b,redScore[a*N+b]);
			mf.add_edge(500+a*20+b,1,blueScore[a*N+b]);
			mf.add_edge(2+a*20+b,500+a*20+b,1<<28);
			FOR(c,N) for(d=c+1;d<N;d++) {
				if(cross(a,b,c,d)==1) mf.add_edge(2+a*20+b,500+c*20+d,1<<28);
			}
		}
		
		return tot-mf.maxflow(0,1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,0,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,0,-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3,
 1, 0, 6, 4,
 2, 6, 0, 5,
 3, 4, 5, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 2, 3, 7,
 2, 0, 4, 6,
 3, 4, 0, 5,
 7, 6, 5, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 27; verify_case(0, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 101, 101, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 100, 100, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 101; verify_case(1, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {-3, -1, -1,  1,  1,  3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, -2,  2, -2,  2,  0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2, 1, 2, 1, 2,
 2, 0, 2, 1, 2, 1,
 1, 2, 0, 2, 1, 2,
 2, 1, 2, 0, 2, 1,
 1, 2, 1, 2, 0, 2,
 2, 1, 2, 1, 2, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0,
 0, 0, 0, 21, 0, 0,
 0, 0, 21, 0, 0, 0,
 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 25; verify_case(2, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {-100, 100, 0, -10, 10, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 100, 10, 10, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0, 96, 96, 25, 25, 25,
 96,  0, 96, 25, 25, 25,
 96, 96,  0, 25, 25, 25,
 25, 25, 25,  0, 10, 10,
 25, 25, 25, 10,  0, 10,
 25, 25, 25, 10, 10,  0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 30, 30, 20, 20, 20,
 30,  0, 30, 20, 20, 20,
 30, 30,  0, 20, 20, 20,
 20, 20, 20,  0, 86, 86,
 20, 20, 20, 86,  0, 86,
 20, 20, 20, 86, 86,  0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 546; verify_case(3, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 15, 2, 3, 4, 5, 6, 7, 8, 9,
 15, 0, 15, 2, 3, 4, 5, 6, 7, 8,
 2, 15, 0, 15, 2, 3, 4, 5, 6, 7,
 3, 2, 15, 0, 15, 2, 3, 4, 5, 6,
 4, 3, 2, 15, 0, 15, 2, 3, 4, 5,
 5, 4, 3, 2, 15, 0, 15, 2, 3, 4,
 6, 5, 4, 3, 2, 15, 0, 15, 2, 3,
 7, 6, 5, 4, 3, 2, 15, 0, 15, 2,
 8, 7, 6, 5, 4, 3, 2, 15, 0, 15,
 9, 8, 7, 6, 5, 4, 3, 2, 15, 0}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 2, 3, 4, 5, 6, 7, 8, 9,
 0, 0, 0, 2, 3, 4, 5, 6, 7, 8,
 2, 0, 0, 0, 2, 3, 4, 5, 6, 7,
 3, 2, 0, 0, 0, 2, 3, 4, 5, 6,
 4, 3, 2, 0, 0, 100, 2, 3, 4, 5,
 5, 4, 3, 2, 100, 0, 0, 2, 3, 4,
 6, 5, 4, 3, 2, 0, 0, 0, 2, 3,
 7, 6, 5, 4, 3, 2, 0, 0, 0, 2,
 8, 7, 6, 5, 4, 3, 2, 0, 0, 0,
 9, 8, 7, 6, 5, 4, 3, 2, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 300; verify_case(4, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SegmentDrawing ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
