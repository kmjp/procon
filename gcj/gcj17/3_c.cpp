#include <bits/stdc++.h>
#include <sys/time.h>
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

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

int C;
int E[1010][2],L[1010][2],D[1010][2],TID[1010][2];
int F[1010][2],T[1010][2],num[1010];
int ret;
int cost[1010][2],pat[1010],sm[1010];


int wait(int f,int t) {
	if(f<=t) return t-f;
	else return 24+t-f;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	UF<4040> uf;
	
	ret=0;
	ZERO(num);
	
	cin>>C;
	FOR(i,C) {
		FOR(j,2) {
			cin>>E[i][j]>>L[i][j]>>D[i][j];
			ret+=D[i][j];
			E[i][j]--;
			TID[i][j] = num[E[i][j]]++;
			F[E[i][j]][TID[i][j]]=i;
			T[E[i][j]][TID[i][j]]=(L[i][j]+D[i][j])%24;
			uf(i*4+2+j,E[i][j]*4+TID[i][j]);
		}
	}
	vector<pair<int,int>> V;
	FOR(i,C) {
		cost[i][0]=wait(T[i][0],L[i][0])+wait(T[i][1],L[i][1]);
		cost[i][1]=wait(T[i][0],L[i][1])+wait(T[i][1],L[i][0]);
		sm[i]=abs(cost[i][1]-cost[i][0]);
		pat[i]=(cost[i][0]>=cost[i][1]);
		if(i) {
			ret+=min(cost[i][0],cost[i][1]);
			V.push_back({sm[i],i});
			if(pat[i]==0) {
				uf(i*4+0,i*4+2);
				uf(i*4+1,i*4+3);
			}
			else {
				uf(i*4+0,i*4+3);
				uf(i*4+1,i*4+2);
			}
		}
	}
	sort(ALL(V));
	
	ll mi=1LL<<60;
	FOR(x,2) FOR(y,2) {
		UF<4040> uf2=uf;
		
		ll tot=ret+wait(0,L[0][y])+wait(T[0][x^1],L[0][y^1]);
		if(x==y) {
			uf2(0,2);
			uf2(1,3);
		}
		else {
			uf2(0,3);
			uf2(1,2);
		}
		FORR(v,V) {
			i=v.second;
			if(uf2[i*4]==uf2[i*4+1]) continue;
			tot+=v.first;
			uf2(i*4,i*4+1);
		}
		mi=min(mi,tot);
	}
	
	_P("Case #%d: %lld\n",_loop,mi);
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


