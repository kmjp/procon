#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll H[505050];
int X1[505050],Y1[505050];
int X2[505050],Y2[505050];
vector<ll> Ys[101010];
int C[505050];

int Q;
int QX[101010],QY[101010];
ll ret[101010];
vector<int> add[101010],del[101010],query[101010];
int cnt[101010];

template<class V, int ME> class BITxor {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s^=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]^=v,e+=e&-e;}
};
BITxor<ll,20> btx;

template<class V, int ME> class BITsum {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BITsum<int,20> bts;

int id[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>H[i];
	FOR(i,N) {
		cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i]>>C[i];
		C[i]--;
		Ys[C[i]].push_back(Y1[i]);
		Ys[C[i]].push_back(Y2[i]);
		add[X1[i]].push_back(i);
		del[X2[i]].push_back(i);
	}
	
	FOR(i,N) {
		sort(ALL(Ys[i]));
		Ys[i].erase(unique(ALL(Ys[i])),Ys[i].end());
		id[i+1]=id[i]+Ys[i].size();
	}
	FOR(i,N) {
		Y1[i]=lower_bound(ALL(Ys[C[i]]),Y1[i])-Ys[C[i]].begin();
		Y2[i]=lower_bound(ALL(Ys[C[i]]),Y2[i])-Ys[C[i]].begin();
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>QX[i]>>QY[i];
		query[QX[i]].push_back(i);
	}
	FOR(x,101000) {
		FORR(a,add[x]) if(Ys[C[a]].size()<=200) {
			for(y=Y1[a];y<Y2[a];y++) if(++cnt[y+id[C[a]]]==1) {
				btx.add(Ys[C[a]][y],H[C[a]]);
				btx.add(Ys[C[a]][y+1],H[C[a]]);
			}
		}
		FORR(a,del[x]) if(Ys[C[a]].size()<=200) {
			for(y=Y1[a];y<Y2[a];y++) if(--cnt[y+id[C[a]]]==0) {
				btx.add(Ys[C[a]][y],H[C[a]]);
				btx.add(Ys[C[a]][y+1],H[C[a]]);
			}
		}
		FORR(q,query[x]) ret[q]=btx(QY[q]);
	}
	FOR(i,101000) if(Ys[i].size()>200) {
		FOR(x,101000) {
			FORR(a,add[x]) if(C[a]==i) {
				bts.add(Ys[i][Y1[a]],1);
				bts.add(Ys[i][Y2[a]],-1);
			}
			FORR(a,del[x]) if(C[a]==i) {
				bts.add(Ys[i][Y1[a]],-1);
				bts.add(Ys[i][Y2[a]],1);
			}
			FORR(q,query[x]) if(bts(QY[q])>0) ret[q]^=H[i];
		}
		
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
