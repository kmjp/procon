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
int S[505][9090];
int T[9090];
int pos[9090];
vector<int> D[9090];

vector<pair<ll,string>> event;

void add(int x,int y,int f,string T) {
	ll key=1LL*x*1000000000LL+1LL*y*100000+(f+10000);
	event.push_back({key,T});
	
	int cur=event.size();
	assert(x>=0 && y>=0 && x<cur && y<cur && T.size()==N);
	
	int i;
	FOR(i,N) {
		if(T[i]=='x') S[cur][i]=S[x][i];
		else {
			assert(i-f>=0 && i-f<N);
			S[cur][i]=S[y][i-f];
		}
	}
}

void hoge(vector<int> dest) {
	int i;
	
	for(int step=N/2;step>=1;step/=2) {
		vector<int> NS(N);
		FOR(i,N) NS[i]=(dest[i]&step)!=0;
		for(int sh=1;sh<=step;sh*=2) {
			string C[2];
			C[0]=C[1]=string(N,'x');
			
			for(int cur=0;cur<N;cur+=step*2) {
				for(int dif=0;dif<sh;dif++) {
					int notsame=0;
					for(i=cur+dif;i<cur+(step*2);i+=sh*2) {
						if(NS[i]!=NS[i^sh]) notsame++;
					}
					notsame/=2;
					
					for(i=cur+dif;i<cur+(step*2);i+=sh*2) {
						if(NS[i]==0 && NS[i^sh]==1) {
							if(sh!=step && notsame<=0) {
								swap(NS[i],NS[i^sh]);
								swap(dest[i],dest[i^sh]);
								C[0][i^sh]='y';
								C[1][i]='y';
							}
							notsame--;
						}
						else if(NS[i]==1 && NS[i^sh]==0) {
							if(sh==step || notsame>0) {
								swap(NS[i],NS[i^sh]);
								swap(dest[i],dest[i^sh]);
								C[0][i^sh]='y';
								C[1][i]='y';
								notsame--;
							}
						}
					}
				}
			}
			int cur=event.size();
			add(cur,cur,sh,C[0]);
			add(cur+1,cur,-sh,C[1]);
		}
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(pos);
	FOR(i,N) {
		cin>>S[0][i];
		S[0][i]--;
		pos[S[0][i]]=i;
	}
	FOR(i,N) {
		cin>>T[i];
		T[i]--;
		if(pos[T[i]]==-1) return _P("-1\n");
		D[T[i]].push_back(i);
	}
	
	vector<int> dest(N,-1);
	set<int> unused;
	FOR(i,N) unused.insert(i);
	int ok=0;
	FOR(i,N) {
		if(D[i].size()>0) {
			unused.erase(ok);
			dest[pos[i]]=ok;
			ok+=D[i].size();
		}
	}
	FOR(i,N) if(dest[i]==-1) {
		dest[i]=*unused.begin();
		S[0][i]=-1;
		unused.erase(unused.begin());
	}

	hoge(dest);
	
	vector<int> from(N,0);
	int pre=0;
	FOR(i,N) {
		if(S[event.size()][i]>=0) pre=i;
		else from[i]=i-pre;
	}
	
	for(int step=1;step<=N/2;step*=2) {
		string T=string(N,'x');
		FOR(i,N) if((from[i]&step)&&step*2>from[i]) T[i]='y';
		add(event.size(),event.size(),step,T);
	}
	
	FOR(i,N) {
		dest[i]=D[S[event.size()][i]].back();
		D[S[event.size()][i]].pop_back();
	}

	hoge(dest);

	FOR(i,N) assert(S[event.size()][i]==T[i]);
	cout<<event.size()<<endl;
	FORR(e,event) {
		ll x=e.first/1000000000LL;
		ll y=e.first/100000LL%10000;
		ll f=e.first%100000-10000;
		cout<<x<<" "<<y<<" "<<f<<" "<<e.second<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
