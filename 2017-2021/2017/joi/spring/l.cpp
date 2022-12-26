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


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,17> bt;

int N,M,Q;
ll X[303030],Y[303030],C[303030],id[303030][2];
vector<int> cand[303030];
int start[303030];
ll SX[2],SY[2];
const int DI=10;

vector<pair<long double,int>> R[2],TR[2];
map<int,int> query[303030],rq[303030];

ll ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	long double PI=atan(1)*4;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>C[i];
		C[i]--;
		cand[C[i]].push_back(i);
	}
	cin>>SX[0]>>SY[0]>>SX[1]>>SY[1];
	FOR(i,M) {
		start[i+1]=start[i]+cand[i].size();
		FORR(c,cand[i]) {
			FOR(j,2) {
				long double d=atan2((long double)SY[j^1]-SY[j],(long double)SX[j^1]-SX[j]);
				long double cd=atan2((long double)Y[c]-SY[j],(long double)X[c]-SX[j]);
				cd-=d;
				while(cd<0) cd+=2*PI;
				while(cd>2*PI) cd-=2*PI;
				R[j].push_back({cd,c});
				if(cd<PI) {
					TR[j].push_back({cd,c});
				}
				else {
					TR[j].push_back({cd-PI,N+c});
				}
			}
		}
		FOR(j,2) {
			sort(R[j].begin()+start[i],R[j].begin()+start[i+1]);
			for(x=start[i];x<start[i+1];x++) id[R[j][x].second][j]=x;
		}
	}
	sort(ALL(TR[0]));
	sort(ALL(TR[1]));
	
	cin>>Q;
	FOR(i,Q) {
		cin>>x>>y;
		x--,y--;
		if(cand[x].size()*cand[y].size()<1000) {
			FORR(cx,cand[x]) {
				ll c1=(X[cx]-SX[0])*(SY[1]-SY[0])-(Y[cx]-SY[0])*(SX[1]-SX[0]);
				FORR(cy,cand[y]) {
					ll c2=(SX[0]-X[cx])*(Y[cy]-Y[cx])-(SY[0]-Y[cx])*(X[cy]-X[cx]);
					if(c1>0!=c2>0) {
						ll c3=(SX[1]-X[cx])*(Y[cy]-Y[cx])-(SY[1]-Y[cx])*(X[cy]-X[cx]);
						if(c1>0 == c3>0) ret[i]++;
					}
				}
			}
		}
		else {
			query[x][y]=i;
		}
	}
	
	FOR(i,M) if(query[i].size()>170) {
		FORR(q,query[i]) rq[q.first][i]=q.second;
		query[i].clear();
	}
	
	FOR(j,2) {
		FORR(v,TR[j]) if(v.second>=N) bt.add(id[v.second-N][j^1],1);
		FORR(v,TR[j]) {
			if(v.second<N) {
				long double d=atan2((long double)SY[j^1]-Y[v.second],(long double)SX[j^1]-X[v.second])-atan2((long double)SY[j]-SY[j^1],(long double)SX[j]-SX[j^1]);
				while(d<0) d+=2*PI;
				while(d>2*PI) d-=2*PI;
				assert(d<PI);
				FORR(q,query[C[v.second]]) {
					y=q.first;
					x=lower_bound(R[j^1].begin()+start[y],R[j^1].begin()+start[y+1],make_pair(d,0))-R[j^1].begin();
					assert(x>=start[y]&&x<=start[y+1]);
					ret[q.second]+=bt(x-1)-bt(start[y]-1);
					x=lower_bound(R[j^1].begin()+start[y],R[j^1].begin()+start[y+1],make_pair(d+PI,0))-R[j^1].begin();
					assert(x>=start[y]&&x<=start[y+1]);
					ret[q.second]+=bt(start[y+1]-1)-bt(x-1);
				}
				bt.add(id[v.second][j^1],1);
			}
			else {
				bt.add(id[v.second-N][j^1],-1);
			}
		}
		FORR(v,TR[j]) if(v.second<N) bt.add(id[v.second][j^1],-1);
	}
	FOR(j,2) {
		ZERO(bt.bit);
		FOR(i,N) bt.add(i,1);
		FORR(v,TR[j]) {
			if(v.second<N) {
				long double d=atan2((long double)Y[v.second]-SY[j^1],(long double)X[v.second]-SX[j^1])-atan2((long double)SY[j]-SY[j^1],(long double)SX[j]-SX[j^1]);
				while(d<0) d+=2*PI;
				while(d>2*PI) d-=2*PI;
				assert(d>PI && d<2*PI);
				FORR(q,rq[C[v.second]]) {
					y=q.first;
					x=lower_bound(R[j^1].begin()+start[y],R[j^1].begin()+start[y+1],make_pair(d-PI,0))-R[j^1].begin();
					assert(x>=start[y]&&x<=start[y+1]);
					ret[q.second]+=bt(x-1)-bt(start[y]-1);
					x=lower_bound(R[j^1].begin()+start[y],R[j^1].begin()+start[y+1],make_pair(d,0))-R[j^1].begin();
					r=lower_bound(R[j^1].begin()+start[y],R[j^1].begin()+start[y+1],make_pair(PI,0))-R[j^1].begin();
					assert(x>=start[y]&&x<=start[y+1]);
					ret[q.second]+=bt(x-1)-bt(r-1);
				}
				bt.add(id[v.second][j^1],-1);
			}
			else {
				bt.add(id[v.second-N][j^1],-1);
			}
		}
	}

	
	FOR(i,Q) {
		cout<<ret[i]<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
