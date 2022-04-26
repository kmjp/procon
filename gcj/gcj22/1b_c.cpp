#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int to[256];

vector<int> C[9],cand;
map<vector<int>,vector<vector<int>>> E[256];
map<vector<int>,vector<vector<int>>> RE;
map<vector<int>,int> best;
map<vector<int>,int> D;
map<vector<int>,int> from;

string tobin(int x,int len) {
	string s;
	if(x==0) return string(len,'0');
	while(x) {
		s+='0'+(x&1);
		x/=2;
	}
	if(s.size()<len) s+=string(len-s.size(),'0');
	reverse(ALL(s));
	return s;
}

vector<vector<int>> proc(vector<int> cur,int pat) {
	vector<vector<int>> V(9);
	int i;
	FORR(c,cur) {
		FOR(i,8) {
			pat=(pat>>1)|((pat&1)<<7);
			int x=pat^c;
			V[__builtin_popcount(x)].push_back(to[x]);
		}
	}
	FORR(v,V) {
		sort(ALL(v));
		v.erase(unique(ALL(v)),v.end());
	}
	return V;
}


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cout<<"00000001"<<endl;
	cin>>x;
	vector<int> cur=C[x];
	int turn=0;
	while(x) {
		turn++;
		int mi=1000;
		int id=-1;
		FOR(x,256) if(x&&to[x]==x) {
			int ma=0;
			FORR(e,E[x][cur]) {
				if(e.size()&&D.count(e)) ma=max(ma,D[e]);
				if(e==cur) ma=10000;
			}
			if(ma<mi) mi=ma, id=x;
		}
		
		cout<<tobin(id,8)<<endl;
		cin>>x;
		if(x==0) break;
		if(x==-1) exit(0);
		cur=E[id][cur][x];
	}
	cerr<<"!"<<turn<<endl;
}

void init() {
	int i,j,x;;
	FOR(i,256) {
		x=i;
		int mi=x;
		FOR(j,8) {
			x=(x>>1)|((x&1)<<7);
			mi=min(mi,x);
		}
		to[i]=mi;
		if(mi==i) C[__builtin_popcount(i)].push_back(i);
	}
	
	FOR(i,9) {
		int mask;
		FOR(mask,1<<C[i].size()) if(mask) {
			vector<int> TC;
			FOR(j,C[i].size()) if(mask&(1<<j)) TC.push_back(C[i][j]);
			FOR(x,256) if(x&&to[x]==x) {
				E[x][TC]=proc(TC,x);
				FOR(j,9) RE[E[x][TC][j]].push_back(TC);
			}
		}
	}
	
	D[{0}]=best[{0}]=0;
	queue<vector<int>> Q;
	Q.push({0});
	while(Q.size()) {
		vector<int> cur=Q.front();
		Q.pop();
		
		FORR(e,RE[cur]) if(D.count(e)==0) {
			int mi=1000;
			int id=-1;
			FOR(x,256) if(x&&to[x]==x) {
				int ma=0;
				FORR(v,E[x][e]) {
					if(v.size()&&D.count(v)==0) ma=1000;
					else if(v==e) ma=1000;
					else ma=max(ma,D[v]);
				}
				if(ma<mi) mi=ma, id=x;
			}
			if(mi<1000) {
				D[e]=mi+1;
				from[e]=id;
				Q.push(e);
			}
		}
	}
	
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		//fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


