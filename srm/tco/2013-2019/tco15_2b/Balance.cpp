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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

pair<ll,ll> tree_normalize(vector<int> T) {
	ll momo[2]={1000000007,1000000009};
	const int MP=5000,prime_max = 100000;
	static int prime[MP+10],NP,divp[prime_max+10];
	
	int i,j;
	if(NP==0) {
		for(i=2;NP<MP;i++) if(divp[i]==0) {
			assert(i<prime_max);
			if(i>5000) prime[NP++]=i;
			for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
		}
		assert(NP==MP);
	}
	
	vector<vector<pair<ll,ll>>> V;
	V.resize(T.size());
	for(i=T.size()-1;i>=0;i--) {
		V[i].push_back({1,1});
		sort(V[i].begin(),V[i].end());
		pair<ll,ll> p={0,0};
		FOR(j,V[i].size()) {
			(p.first+=V[i][j].first*prime[j])%=momo[0];
			(p.second+=V[i][j].second*prime[j])%=momo[1];
		}
		V[T[i]].push_back(p);
	}
	return V[0].back();
}



class Balance {
	public:
	int N;
	int vis[4000];
	UF<10000> uf;
	vector<int> mem[4000];
	
	
	void dfs(vector<int>& R,int id,int g) {
		int i;
		vector<int> c;
		vis[g]=1;
		FORR(r,mem[g]) {
			int cy=r/60,cx=r%60;
			FOR(i,4) {
				int dd[4]={1,0,-1,0};
				int ty=cy+dd[i],tx=cx+dd[i^1];
				if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
				int g2=uf[ty*60+tx];
				if(vis[g2]==0) vis[g2]=1, c.push_back(g2);
			}
		}
		int cur=R.size();
		R.resize(cur+c.size());
		FOR(i,c.size()) R[cur+i]=id, dfs(R,cur+i, c[i]);
	}

	vector<int> maketree(vector<string> S) {
		vector<vector<int>> D;
		int y,x;
		
		N=S.size()+2;
		D.resize(N);
		FOR(y,N) D[y].resize(N);
		FOR(y,N-2) FOR(x,N-2) D[y+1][x+1]=S[y][x]=='.';
		
		uf.reinit();
		ZERO(vis);
		
		FOR(y,N) FOR(x,N) {
			mem[y*60+x].clear();
			if(x<N-1 && D[y][x]==D[y][x+1]) uf(y*60+x,y*60+x+1);
			if(y<N-1 && D[y][x]==D[y+1][x]) uf(y*60+x,y*60+x+60);
		}
		FOR(y,N) FOR(x,N) mem[uf[y*60+x]].push_back(y*60+x);
		vector<int> R;
		R.push_back(0);
		dfs(R,0,uf[0]);
		return R;
	}
	
	string canTransform(vector <string> initial, vector <string> target) {
		vector<int> T[2];
		T[0]=maketree(initial);
		T[1]=maketree(target);
		
		if(tree_normalize(T[0])==tree_normalize(T[1])) return "Possible";
		return "Impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(0, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".#",
 "##"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...",
 ".#.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"###",
 "#.#",
 "###"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".#.#.......",
 "####.###...",
 ".....####..",
 "..##.#.##.#",
 ".##..#.##.#",
 ".#######...",
 ".#....###.#",
 ".##.#.#....",
 "..#...#...#",
 "..#####...#",
 "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"...........",
 ".###....#..",
 ".#.#..#....",
 ".###.......",
 ".#####.....",
 ".#...#####.",
 ".#.#.....#.",
 ".#.#####.#.",
 ".#.......#.",
 ".#########.",
 "..........."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(3, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"..................................................", ".################################################.", ".#..............................................#.", ".#.############################################.#.", ".#.#..........................................#.#.", ".#.#.########################################.#.#.", ".#.#.#......................................#.#.#.", ".#.#.#.####################################.#.#.#.", ".#.#.#.#..................................#.#.#.#.", ".#.#.#.#.################################.#.#.#.#.", ".#.#.#.#.#..............................#.#.#.#.#.", ".#.#.#.#.#.############################.#.#.#.#.#.", ".#.#.#.#.#.#..........................#.#.#.#.#.#.", ".#.#.#.#.#.#.########################.#.#.#.#.#.#.", ".#.#.#.#.#.#.#......................#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#..#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.....................##.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#..#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#...........#..........#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.#.#...#.#...#.#.#.#.##.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.....#.....#.........##.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.#.#.....#.#.#..##.#..#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#......................#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.#.#.#...#.#.#.#.#.#.##.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.....................##.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.#.##.##.#.#.#.#..##..#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#......................#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.##.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.....................##.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.#.#...#.#.#.#.#.#.#.##.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.....................##.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.#.#...#.#.#.#.#.#.#..#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.............#........#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#..#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#......................#.#.#.#.#.#.#.", ".#.#.#.#.#.#.##.#.#..##.##...#.####.#.#.#.#.#.#.#.", ".#.#.#.#.#.#..#######################.#.#.#.#.#.#.", ".#.#.#.#.#.#..........................#.#.#.#.#.#.", ".#.#.#.#.#.############################.#.#.#.#.#.", ".#.#.#.#.#..............................#.#.#.#.#.", ".#.#.#.#.################################.#.#.#.#.", ".#.#.#.#..................................#.#.#.#.", ".#.#.#.####################################.#.#.#.", ".#.#.#......................................#.#.#.", ".#.#.########################################.#.#.", ".#.#..........................................#.#.", ".#.############################################.#.", ".#..............................................#.", ".################################################.", ".................................................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..................................................", ".################################################.", ".#..............................................#.", ".#.############################################.#.", ".#.#..........................................#.#.", ".#.#.########################################.#.#.", ".#.#.#......................................#.#.#.", ".#.#.#.####################################.#.#.#.", ".#.#.#.#..................................#.#.#.#.", ".#.#.#.#.################################.#.#.#.#.", ".#.#.#.#.#..............................#.#.#.#.#.", ".#.#.#.#.#.############################.#.#.#.#.#.", ".#.#.#.#.#.#..........................#.#.#.#.#.#.", ".#.#.#.#.#.#.########################.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.............#.##...#.#.#.#.#.#.#.#.", ".#.#.#.#.#.#.##...#.#...#.......#...#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#..#.#.#.#...#.#...#.#.#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#....#...........#.....#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#..#....#.#.##.#...#.#.#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#......................#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#..#.#.#.#...#.#.#.#..##.#.#.#.#.#.#.", ".#.#.#.#.#.#.#..........#..........##.#.#.#.#.#.#.", ".#.#.#.#.#.#.#..#.#.#.#.#.#.#.#.##..#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#......................#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#.#..#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#......................#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#..#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#......................#.#.#.#.#.#.#.", ".#.#.#.#.#.#.##.#.#.#.#.#.#.#.#...#.#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#......................#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#..#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.", ".#.#.#.#.#.#.##.....................#.#.#.#.#.#.#.", ".#.#.#.#.#.#.##.#.#.#.##.#..#..##.#.#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#......................#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#..#.#.#.#.#.#.#.#...#.#.#.#.#.#.#.#.", ".#.#.#.#.#.#.#..................#...#.#.#.#.#.#.#.", ".#.#.#.#.#.#.########################.#.#.#.#.#.#.", ".#.#.#.#.#.#..........................#.#.#.#.#.#.", ".#.#.#.#.#.############################.#.#.#.#.#.", ".#.#.#.#.#..............................#.#.#.#.#.", ".#.#.#.#.################################.#.#.#.#.", ".#.#.#.#..................................#.#.#.#.", ".#.#.#.####################################.#.#.#.", ".#.#.#......................................#.#.#.", ".#.#.########################################.#.#.", ".#.#..........................................#.#.", ".#.############################################.#.", ".#..............................................#.", ".################################################.", ".................................................."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(4, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_42() { string Arr0[] = {".....",
 ".###.",
 ".....",
 ".###.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".....",
 ".#.#.",
 ".#.#.",
 ".#.#.",
 "....."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(4, Arg2, canTransform(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Balance ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}