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
		E[y].push_back((edge){x,(int)E[x].size()-1,0}); // directed
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
	
	V dfs(int from,int to,V cf) {
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

int co[101][101];
const ll mama=1LL<<50;
class ConvenientBlock {
	public:
	long long minCost(int N, vector <int> from, vector <int> to, vector <int> cost) {
		int i,x,y;
		
		ZERO(co);
		FOR(x,N) co[x][x]=1;
		
		FOR(i,from.size()) co[from[i]][to[i]]=1;
		FOR(i,N) FOR(x,N) FOR(y,N) co[x][y]|=co[x][i]&&co[i][y];
		
		MaxFlow_dinic<ll> mf;
		FOR(i,from.size()) {
			if(co[0][from[i]]==0) continue;
			if(co[to[i]][N-1]==0) continue;
			mf.add_edge(from[i],to[i],cost[i]);
			mf.add_edge(to[i],from[i],mama);
			
		}
		
		ll m=mf.maxflow(0,N-1);
		return (m<mama)?m:-1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arr1[] = {0,0,1,2,4,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,1,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,5,1,1,1,5,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 6LL; verify_case(0, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {0,1,2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6,7,8,9,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = -1LL; verify_case(1, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {0,0,0,1,2,3,4,5,5,5,6,7,8,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,4,4,5,6,7,8,9,9,9,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,5,5,10,10,10,1,10,10,10,1,5,5,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 11LL; verify_case(2, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 14; int Arr1[] = {0,3,6,2,5,1,4,7,10,13,9,12,8,11,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,6,2,5,1,4,0,10,13,9,12,8,11,7,11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,932384}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 932384LL; verify_case(3, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10; int Arr1[] = {7,3,2,0,0,6,7,9,5,4,8,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,5,3,6,4,9,1,3,9,2,9,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {94,57,66,83,97,31,87,90,66,71,92,78}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 97LL; verify_case(4, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 24; int Arr1[] = {17,8,5,14,13,6,17,21,12,22,11,1,18,20,20,4,11,11,21,
3,19,21,17,2,17,6,12,7,19,9,14,4,22,3,18,20,1,3,6,21,
14,0,4,16,22,11,16,20,16,22,14,5,17,15,7,13,5,20,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,19,15,6,2,1,0,13,18,16,9,12,23,9,1,20,15,2,1,5,9,2,
7,17,10,14,5,2,14,22,10,2,14,18,16,11,8,20,3,3,18,3,15,
7,4,1,23,4,6,12,0,7,2,2,17,22,0,21,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {7,97743,40693,8,7844,2,110,13507,735,25,24,264,1069,
92,7908,11971,142,2242,287969,268562,112,4,14064,184,
9,17,2610,61,188,26978,7,1542,133,2,75,1,191,43893,73717,
2174,2,21668,87095,4434,128,1,13257,35,791118,11,669682,
637153,163,15968,217527,50,168,72694,418644}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 14326LL; verify_case(5, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 100; int Arr1[] = {95,71,20,37,78,7,34,26,78,91,18,52,11,19,79,76,8,90,69,67,
37,18,20,58,31,48,5,75,52,37,98,64,99,34,24,35,30,72,28,73,
85,75,2,5,12,22,41,6,28,34,82,79,77,53,93,76,75,62,61,26,12,
16,3,70,50,88,17,24,98,81,23,9,38,52,66,44,49,36,76,24,60,97,
35,68,20,14,7,61,42,41,55,20,67,18,17,58,59,15,15,91,12,15,18,
40,27,26,93,91,71,65,0,13,45,67,44,60,10,74,86,47,35,79,63,77,
50,90,46,26,89,6,62,39,81,64,16,38,77,38,35,32,36,38,55,48,34,
85,97,27,41,69,86,7,12,62,24,26,52,94,49,98,49,8,21,47,91,24,22,
14,94,14,65,54,20,51,37,4,73,73,46,82,73,8,20,39,66,10,84,1,24,
36,31,38,23,46,43,75,24,4,31,20,82,35,15,65,61,33,40,17,36,45,
16,19,97,78,27,10,0,99,36,10,25,15,91,30,26,66,8,63,2,77,78,76,
12,19,34,30,8,7,77,99,71,27,25,49,73,54,65,10,88,27,99}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {48,65,94,18,79,32,94,18,46,77,52,40,51,41,38,91,1,58,94,92,78,
37,45,73,36,60,64,83,76,43,97,40,10,20,2,30,98,51,75,23,12,69,
71,85,86,1,21,83,29,46,23,24,85,64,73,40,56,53,43,28,28,49,45,
73,58,38,35,3,29,41,87,87,19,71,14,63,25,21,56,92,27,25,7,73,
5,73,48,80,68,39,65,4,95,35,72,56,62,64,26,52,64,65,77,50,17,
39,69,93,29,13,75,83,91,71,48,72,30,20,74,4,94,78,99,56,88,91,
25,24,68,8,40,37,11,76,67,61,20,15,29,72,8,5,48,86,60,48,2,87,
77,39,67,99,42,68,52,96,77,93,46,61,82,65,56,29,72,4,83,76,67,
49,78,37,74,25,72,72,93,11,65,7,32,99,36,22,81,77,82,57,33,72,
25,67,12,38,33,46,51,85,32,85,51,73,30,61,91,8,65,48,85,40,42,
14,96,39,40,33,54,73,87,25,49,58,39,24,88,29,17,9,30,48,80,63,
45,59,39,46,72,57,49,92,53,22,22,67,72,41,52,47,44,18,51}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {37128,1,86,7856,942,55,504,4,1663,25142,3166,2881,24238,5,53,
1773,1181,64,454734,5406,29022,4,67626,5641,256489,13,37223,340,
3,2585,7462,85,1,83751,939915,741519,13521,36879,1776,274509,
571821,70003,794,129,1168,1336,127592,5267,8,315,117243,493198,
523,72676,2,10727,113664,102,1,24096,170,41467,1,2011,7,868987,
140027,382259,107,12,2306,138785,156,450194,896034,4,755,950,5,
4,1271,5,89,7011,1,50657,200,16,159,637870,8246,334324,621,74,
54163,3089,336,3800,1,507181,48093,3215,216403,7,6131,42182,151,
2,155,1,4436,2498,59158,11,628510,218003,1,16383,258124,1294,
226279,16,27,470171,282834,11038,767,563224,112001,227,11224,
94,213534,664932,1128,1280,337,11,52709,536,1,25,646,2091,110,
2570,40543,113183,317,901,4628,1420,14525,201865,265135,86,1,
8541,10023,10871,61,47844,2,26,164,13417,30084,13,6923,2,57796,
466,1,1988,4100,119,362,8,160708,37,42655,88,12288,73,746447,
851216,36,4740,2,11,7381,1837,522217,1,384368,1,70,1,43,2,6,
260,275200,11,1182,7,450764,583480,38,565,1064,458,12,128090,
3,548913,19,35,19990,6,260815,112,174,125452,184178,12497,2,
12069,568226,8,122,10,5645,395,1883,7,153,5243,1,273,34,52959,
25,157,74650,14987,1263,4491,15476,4,924077}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 4455LL; verify_case(6, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arg0 = 4; int Arr1[] = {0, 0, 0, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 3000000000LL; verify_case(7, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ConvenientBlock ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
