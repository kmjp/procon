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
int L[1010101],R[1010101];
const ll mo=1000000007;
int ev[2020202];

int col[1010101];
vector<int> cand;
int val[2][22][1<<22];
int num[2][1<<22];



template<int NV> class SegTree {
public:
	void getval(int x,int y,int l=0,int r=NV,int k=1,int o=0) { // x<=i<y
		if(r<=x || y<=l) return;
		if(x<=l && r<=y) {
			while(num[0][k]&&L[val[0][o][l+num[0][k]-1]]<x) {
				num[0][k]--;
				int cur=val[0][o][l+num[0][k]];
				if(col[cur]==-1) {
					col[cur]=0;
					cand.push_back(cur);
				}
			}
			while(num[1][k]&&R[val[1][o][l+num[1][k]-1]]>y) {
				num[1][k]--;
				int cur=val[1][o][l+num[1][k]];
				if(col[cur]==-1) {
					col[cur]=0;
					cand.push_back(cur);
				}
			}
			
			return;
		}
		getval(x,y,l,(l+r)/2,k*2,o+1);
		getval(x,y,(l+r)/2,r,k*2+1,o+1);
	}
	void update(int entry,int id,int v) {
		int x=entry;
		entry += NV;
		int o=21;
		while(entry>=1) {
			val[id][o][x+num[id][entry]]=v;
			num[id][entry]++;
			entry>>=1;
			x&=~(1<<(21-o));
			o--;
		}
		assert(o==-1&&x==0);
	}
};
SegTree<1<<21> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		L[i]--,R[i]--;
		ev[L[i]]=i;
		ev[R[i]]=i+N;
		col[i]=-1;
	}
	FOR(i,2*N) {
		x=ev[i];
		if(x>=N) {
			x-=N;
			st.update(L[x],1,x);
		}
	}
	for(i=2*N-1;i>=0;i--) {
		x=ev[i];
		if(x<N) {
			st.update(R[x],0,x);
		}
	}
	
	ll ret=1;
	FOR(i,N) if(col[i]==-1) {
		ret=ret*2%mo;
		col[i]=0;
		queue<int> Q;
		Q.push(i);
		//cout<<"!"<<i<<endl;
		while(Q.size()) {
			x=Q.front();
			//cout<<x<<" "<<col[x]<<" : ";
			cand.clear();
			Q.pop();
			st.getval(L[x],R[x]);
			
			FORR(c,cand) {
				//cout<<c;
				col[c]=col[x]^1;
				Q.push(c);
			}
			//cout<<endl;
		}
		
	}
	
	vector<int> S[2];
	FOR(i,2*N) {
		x=ev[i];
		if(x<N) {
			S[col[x]].push_back(x);
		}
		else {
			x-=N;
			if(S[col[x]].back()!=x) return _P("0\n");
			S[col[x]].pop_back();
			
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
