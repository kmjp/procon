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

template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to, capacity; V cost; int reve;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV];
	void add_edge(int x,int y, int cap, int cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	V mincost(int from, int to, int flow) {
		V res=0; int i,v;
		ZERO(prev_v); ZERO(prev_e);
		while(flow>0) {
			fill(dist, dist+NV, numeric_limits<V>::max()/2);
			dist[from]=0;
			priority_queue<pair<int,int> > Q;
			Q.push(make_pair(0,from));
			while(Q.size()) {
				int d=-Q.top().first, cur=Q.top().second;
				Q.pop();
				if(dist[cur]!=d) continue;
				if(d==numeric_limits<V>::max()/2) break;
				FOR(i,E[cur].size()) {
					edge &e=E[cur][i];
					if(e.capacity>0 && dist[e.to]>d+e.cost) {
						dist[e.to]=d+e.cost;
						prev_v[e.to]=cur;
						prev_e[e.to]=i;
						Q.push(make_pair(-dist[e.to],e.to));
					}
				}
			}
			
			if(dist[to]==numeric_limits<V>::max()/2) return -1;
			int lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			flow -= lc;
			res += lc*dist[to];
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};

int N;
class StoryFromTCO {
	public:
	int minimumChanges(vector <int> places, vector <int> cutoff) {
		N=places.size();
		int i,j,x,y;
		pair<int,int> P[1001];
		FOR(i,N) P[i]=make_pair(cutoff[i],i);
		sort(P,P+N);
		
		MinCostFlow<3040,int> mcf;
		
		FOR(i,N) mcf.add_edge(0,10+i,1,0);
		FOR(i,N) mcf.add_edge(1020+i,1,1,0);
		FOR(i,N) if(places[i]<=cutoff[i]) mcf.add_edge(10+i,1020+i,1,0);
		FOR(i,N-1) mcf.add_edge(1020+P[i].second,1020+P[i+1].second,1000,0);
		
		FOR(x,N) {
			FOR(y,N) if(places[x]<=P[y].first) break;
			if(y<N) mcf.add_edge(10+x,1020+P[y].second,1,1);
		}
		return mcf.mincost(0,1,N);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {20,100,500,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7500,2250,150,24}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, minimumChanges(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, minimumChanges(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,6,4,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, minimumChanges(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,4,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, minimumChanges(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {14,11,42,9,19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {11,16,37,41,47}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(4, Arg2, minimumChanges(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {4,1,3,3,2,4,5,5,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,3,5,2,4,4,5,4,3,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(5, Arg2, minimumChanges(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {213,177,237,444,497,315,294,104,522,635,13,26,22,276,88,249,374,17,42,245,80,553,121,625,62,105,
53,132,178,250,18,210,492,181,2,99,29,21,62,218,188,584,702,63,41,79,28,452,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33,40,41,48,74,84,117,125,126,164,197,197,201,218,222,231,244,277,290,309,321,321,360,376,440,
442,465,477,491,513,639,645,647,675,706,710,726,736,736,765,801,838,845,854,863,865,887,902,908}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 23; verify_case(6, Arg2, minimumChanges(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  StoryFromTCO ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
