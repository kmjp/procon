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

template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to; V capacity; V cost; int reve;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV];
	void add_edge(int x,int y, V cap, V cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	V mincost(int from, int to, ll flow) {
		V res=0; int i,v;
		ZERO(prev_v); ZERO(prev_e);
		while(flow>0) {
			fill(dist, dist+NV, numeric_limits<V>::max()/2);
			dist[from]=0;
			priority_queue<pair<V,int> > Q;
			Q.push(make_pair(0,from));
			while(Q.size()) {
				V d=-Q.top().first;
				int cur=Q.top().second;
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
			ll lc=flow;
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


class ShoppingSpree {
	public:
	int maxValue(int k, vector <int> shirtValue, vector <int> jeansValue, vector <int> shirtType, vector <int> jeansType) {
		MinCostFlow<250,ll> mcf;
		int N=shirtValue.size();
		int M=jeansValue.size();
		int D=shirtType.size();
		int i;
		FOR(i,N) {
			mcf.add_edge(0,i+2,1,1000000-shirtValue[i]);
			mcf.add_edge(0,i+2,100,1000000);
		}
		FOR(i,M) {
			mcf.add_edge(i+102,1,1,1000000-jeansValue[i]);
			mcf.add_edge(i+102,1,100,1000000);
		}
		FOR(i,D) {
			mcf.add_edge(2+shirtType[i],102+jeansType[i],100,0);
		}
		
		return 2*k*1000000-mcf.mincost(0,1,k);
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; verify_case(0, Arg5, maxValue(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 0, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 14; verify_case(1, Arg5, maxValue(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 0, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 6; verify_case(2, Arg5, maxValue(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ShoppingSpree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

