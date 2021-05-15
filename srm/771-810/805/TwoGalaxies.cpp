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


map<pair<int,int>,bitset<128>> M;
map<pair<int,int>,vector<pair<int,int>>> V;

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 202;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	void bfs(int cur) {
		MINUS(lev);
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			FORR(e,E[v]) if(e.cap>0 && lev[e.to]<0) lev[e.to]=lev[v]+1, q.push(e.to);
		}
	}
	V dfs(int from,int to,V cf) {
		if(from==to) return cf;
		for(;itr[from]<E[from].size();itr[from]++) {
			edge* e=&E[from][itr[from]];
			if(e->cap>0 && lev[from]<lev[e->to]) {
				V f=dfs(e->to,to,min(cf,e->cap));
				if(f>0) {
					e->cap-=f;
					E[e->to][e->reve].cap += f;
					return f;
				}
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

class TwoGalaxies {
	public:
	int count(vector <int> X, vector <int> Y) {
		M.clear();
		V.clear();
		int N=X.size();
		int i,x,y;
		FOR(y,N) FOR(x,y+1) {
			M[{X[x]+X[y],Y[x]+Y[y]}][x]=1;
			M[{X[x]+X[y],Y[x]+Y[y]}][y]=1;
			V[{X[x]+X[y],Y[x]+Y[y]}].push_back({x,y});
		}
		int ret=0;
		
		for(auto it=M.begin();it!=M.end();it++) {
			if(it->second.count()==N) continue;
			for(auto it2=M.begin();it2!=it;it2++) {
				if(it2->second.count()==N) continue;
				bitset<128> a=it->second | it2->second;
				if(a.count()!=N) continue;
				MaxFlow_dinic<int> mf;
				int i;
				FOR(i,N) mf.add_edge(2*N,i,1),mf.add_edge(N+i,2*N+1,1);
				FORR(p,V[it->first]) {
					mf.add_edge(p.first,N+p.second,1);
					if(p.first!=p.second) mf.add_edge(p.second,N+p.first,1);
				}
				FORR(p,V[it2->first]) {
					mf.add_edge(p.first,N+p.second,1);
					if(p.first!=p.second) mf.add_edge(p.second,N+p.first,1);
				}
				if(mf.maxflow(2*N,2*N+1)==N) ret++;
			}
		}
		return ret;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 2, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 0, 1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 1, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {47, 10, 11, 12, 13, 15, 14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {47, 42, 42, 42, 42, 42, 42}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 4, 9, 16, 25, 36, 49}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4_() { int Arr0[] = {0, 0, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 10, 0, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_4__() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1804289383,846930886,1681692777,1714636915,1957747793,424238335,719885386,1649760492,596516649,1189641421,1025202362,1350490027,783368690,1102520059,2044897763,1967513926,1365180540,1540383426,304089172,1303455736,35005211,521595368,294702567,1726956429,336465782,861021530,278722862,233665123,2145174067,468703135,1101513929,1801979802,1315634022,635723058,1369133069,1125898167,1059961393,2089018456,628175011,1656478042,1131176229,1653377373,859484421,1914544919,608413784,756898537,1734575198,1973594324,149798315,2038664370,1129566413,184803526,412776091,1424268980,1911759956,749241873,137806862,42999170,982906996,135497281,511702305,2084420925,1937477084,1827336327,572660336,1159126505,805750846,1632621729,1100661313,1433925857,1141616124,84353895,939819582,2001100545,1998898814,1548233367,610515434,1585990364,1374344043,760313750,1477171087,356426808,945117276,1889947178,1780695788,709393584,491705403,1918502651,752392754,1474612399,2053999932,1264095060,1411549676,1843993368,943947739,1984210012,855636226,1749698586,1469348094,1956297539}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1036140795,463480570,2040651434,1975960378,317097467,1892066601,1376710097,927612902,1330573317,603570492,1687926652,660260756,959997301,485560280,402724286,593209441,1194953865,894429689,364228444,1947346619,221558440,270744729,1063958031,1633108117,2114738097,2007905771,1469834481,822890675,1610120709,791698927,631704567,498777856,1255179497,524872353,327254586,1572276965,269455306,1703964683,352406219,1600028624,160051528,2040332871,112805732,1120048829,378409503,515530019,1713258270,1573363368,1409959708,2077486715,1373226340,1631518149,200747796,289700723,1117142618,168002245,150122846,439493451,990892921,1760243555,1231192379,1622597488,111537764,338888228,2147469841,438792350,1911165193,269441500,2142757034,116087764,1869470124,155324914,8936987,1982275856,1275373743,387346491,350322227,841148365,1960709859,1760281936,771151432,1186452551,1244316437,971899228,1476153275,213975407,1139901474,1626276121,653468858,2130794395,1239036029,1884661237,1605908235,1350573793,76065818,1605894428,1789366143,1987231011,1875335928,1784639529}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TwoGalaxies ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

