#include <bits/stdc++.h>
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


vector<int> D[101010];
int vis[101010];

class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
		int i,y,x;
		FOR(i,n) D[i].clear(),vis[i]=0;
		FORR(e,edges) D[e[0]].push_back(e[1]);
		FORR(e,edges) D[e[1]].push_back(e[0]);
		int H,W;
		int E=edges.size();
		vector<vector<int>> R;
		
		if(E==n-1) {
			H=1;
			W=n;
			R.resize(H);
			FOR(y,H) R[y].resize(W);
			
			FOR(i,n) if(D[i].size()==1) break;
			R[0][0]=i;
			vis[i]=1;
			for(x=1;x<W;x++) {
				int tar=-1;
				FORR(e,D[R[0][x-1]]) if(vis[e]==0) tar=e;
				vis[tar]=1;
				R[0][x]=tar;
			}
			return R;
		}
		else {
			vector<int> C;
			FOR(i,n) if(D[i].size()==2) C.push_back(i);
			
			int op=-1;
			FORR(a,D[C[0]]) if(D[a].size()==2) op=a;
			
			if(op!=-1) {
				H=2,W=n/2;
				R.clear();
				R.resize(H);
				FOR(y,H) R[y].resize(W);
				R[0][0]=C[0];
				R[1][0]=op;
				vis[R[0][0]]=1;
				vis[R[1][0]]=1;
				for(x=1;x<W;x++) {
					FOR(y,2) {
						FORR(e,D[R[y][x-1]]) if(vis[e]==0) {
							R[y][x]=e;
							vis[e]=1;
						}
					}
				}
			}
			else {
				vector<int> L;
				L.push_back(C[0]);
				while(1) {
					int cur=L.back();
					vis[cur]=1;
					int up=0;
					FORR(e,D[cur]) if(D[e].size()<=3&&vis[e]==0) {
						cur=e;
						up=1;
						break;
					}
					if(up==0) break;
					L.push_back(cur);
				}
				H=W=-1;
				for(i=1;i<L.size();i++) if(D[L[i]].size()==2) {
					if(W==-1) W=i+1;
					else if(H==-1) H=i-W+2;
				}
				cout<<"#"<<H<<" "<<W<<" "<<L.size()<<endl;
				FORR(a,L) cout<<a;
				cout<<endl;
				R.clear();
				R.resize(H);
				cout<<"#"<<H<<" "<<W<<" "<<L.size()<<endl;
				FOR(y,H) R[y].resize(W);
				int nex=0;
				FOR(x,W) R[0][x]=L[nex++];
				cout<<"#"<<endl;
				for(y=1;y<H;y++) R[y][W-1]=L[nex++];
				for(x=W-2;x>=0;x--) R[H-1][x]=L[nex++];
				for(y=H-2;y>0;y--) R[y][0]=L[nex++];
				cout<<"#"<<endl;
				for(y=1;y<H-1;y++) for(x=1;x<W-1;x++) {
					int a=R[y-1][x];
					int b=R[y][x-1];
					FORR(c,D[a]) FORR(d,D[b]) if(c==d&&vis[c]==0) {
						R[y][x]=c;
						vis[c]=1;
					}
				}
				cout<<"#"<<endl;
			}
			return R;
			
		}
		
		
		
		
        
    }
};
