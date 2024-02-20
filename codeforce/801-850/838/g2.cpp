#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

int T,N,A[303030];
int F[302020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(x,T) {
		cin>>N;
		FOR(i,N) F[i]=0;
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			F[A[i]]++;
		}
		FOR(i,N) if(F[i]>(N+1)/2) break;
		if(i!=N) {
			cout<<"NO"<<endl;
			continue;
		}
		int L=0;
		vector<ll> ret(N);
		while(L<N) {
			int LV=A[L];
			vector<int> C[2];
			int cur=L;
			C[A[cur]!=LV].push_back(cur);
			cur++;
			while(cur<N&&(C[0].size()!=C[1].size()))  {
				C[A[cur]!=LV].push_back(cur);
				cur++;
			}
			
			if(C[0].size()==C[1].size()) {
				C[1].pop_back();
				FOR(i,C[0].size()) ret[L+i*2]=C[0][i];
				FOR(i,C[1].size()) ret[L+1+i*2]=C[1][i];
				L+=C[0].size()+C[1].size();
				continue;
			}
			if(C[0].size()==C[1].size()+1&&cur==N) {
				FOR(i,C[0].size()) ret[L+i*2]=C[0][i];
				FOR(i,C[1].size()) ret[L+1+i*2]=C[1][i];
				L+=C[0].size()+C[1].size();
				continue;
			}
			
			//巻き戻し
			cur=L;
			while(1) {
				if(cur==0||C[0].size()==C[1].size()) {
					sort(ALL(C[0]));
					sort(ALL(C[1]));
					if(C[0].size()!=C[1].size()) {
						ret[cur++]=C[0][0];
						C[0].erase(C[0].begin());
					}
					if(cur&&C[1].size()) {
						//サイズは一緒なので、ぶつかるなら反転
						if(A[ret[cur-1]]==A[C[1][0]]) {
							swap(C[0],C[1]);
						}
					}
					FOR(i,C[0].size()) {
						ret[cur++]=C[1][i];
						ret[cur++]=C[0][i];
					}
					break;
				}
				//1手戻す
				cur--;
				C[A[ret[cur]]!=LV].push_back(ret[cur]);
			}
			break;
		}

		cout<<"YES"<<endl;
		FORR(a,ret) cout<<a+1<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
