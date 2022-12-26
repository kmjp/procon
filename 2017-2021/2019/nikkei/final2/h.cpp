#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int A[603030];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int num[606060];
int rad[606060];
ll dp[606060];


int nex[606060];
int pre[606060];
int id[606060];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	M++;
	FOR(i,N) cin>>A[i*2+1];
	N=N*2+1;
	
	FOR(i,M+1) id[i]=-1;
	FOR(i,N) {
		pre[i]=id[A[i]];
		id[A[i]]=i;
	}
	FOR(i,M+1) id[i]=N;
	for(i=N-1;i>=0;i--) {
		nex[i]=id[A[i]];
		id[A[i]]=i;
	}
	
	int PR=0;
	num[0]=M-1;
	ll ret=0;
	for(i=1;i<N;i++) {
		int tr=PR+rad[PR]-i;
		if(tr>=0) {
			//前回のmanacherの範囲内
			int mi=PR-(i-PR);
			//鏡位置のコピー
			rad[i]=rad[mi];
			num[i]=num[mi];
			dp[i]=dp[mi];
			//cout<<"!G"<<i<<" "<<rad[i]<<" "<<num[i]<<" "<<dp[i]<<" "<<PR<<" "<<tr<<" "<<mi<<endl;
			if(tr>rad[i]) {
				//範囲外にならないので以前の計算結果を再利用
				
				ret+=dp[i];
				//cout<<"!"<<i<<" "<<rad[i]<<" "<<num[i]<<" "<<dp[i]<<endl;
				continue;
			}
			//左端がRを超えない範囲まで縮める
			while(tr<rad[i]) {
				if(rad[i]&&A[i-rad[i]]==0) dp[i]-=modpow(M-1,num[i]);
				//左端・右端で初めて出てきた要素があれば削除する
				if(nex[mi-rad[i]]>=mi+rad[i]) num[i]++;
				if(pre[mi+rad[i]]<mi-rad[i]) num[i]++; //同じのを2回消さないため統合無し
				rad[i]--;
			}
		}
		else {
			//新規
			rad[i]=0;
			tr=0;
			num[i]=M-1;
		}
		int L=i-tr-1;
		int R=i+tr+1;
		//cout<<"s"<<i<<" "<<L<<" "<<R<<" "<<rad[i]<<" "<<num[i]<<" "<<dp[i]<<endl;
		while(L>=0&&R<N) {
			int cnt=0;
			
			if(nex[L]>=R) {
				//左に新規
				cnt++;
			}
			else {
				//既存の対応と同じかチェック
				x=nex[L];
				y=R-(x-L);
				if(A[y]!=A[R]) cnt=-100;
			}
			if(pre[R]<L) {
				cnt++;
			}
			else {
				//既存の対応と同じかチェック
				x=pre[R];
				y=L+(R-x);
				if(A[y]!=A[L]) cnt=-100;
			}
			//cout<<L<<" "<<R<<" "<<nex[L]<<" "<<pre[R]<<" "<<cnt<<" "<<dp[i]<<endl;
			if(cnt<0) break;
			num[i]-=cnt;
			rad[i]++;
			if(A[L]==0) dp[i]+=modpow(M-1,num[i]);
			L--,R++;
		}
		//右に寄せる
		dp[i]=(dp[i]%mo+mo)%mo;
		ret+=dp[i];
		//cout<<"!"<<i<<" "<<rad[i]<<" "<<num[i]<<" "<<dp[i]<<endl;
		if(i+rad[i]>=PR+rad[PR]) PR=i;
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
