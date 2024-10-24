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

int from[3030];
int to[3030];
string H[3030];
int T[3030];
int N,Q;

void move(int a,int b,int c,int cur) {
	if(a==c) {
		chmin(to[b],cur);
		return;
	}
	//a��c�ɓ������Ab���ז�
	if(b==c) {
		if(a<c) {
			//����
			chmin(to[(c+1)%N],cur+c-a+1);
			chmin(to[(c+N-1)%N],cur+a+N-c+1);
		}
		else {
			chmin(to[(c+1)%N],cur+c+N-a+1);
			chmin(to[(c+N-1)%N],cur+a-c+1);
		}
	}
	else {
		if(b<a&&b<c) {
			//���
			chmin(to[b],cur+abs(c-a));
			if(c<=a) {
				//����
				chmin(to[(c+1)%N],cur+(c+N-a)+(c-b+1));
			}
			else {
				chmin(to[(c+N-1)%N],cur+(a+N-c)+(b+N-c+1));
			}
		}
		else if(c<b&&a<b) {
			chmin(to[b],cur+abs(c-a));
			if(c<=a) {
				//����
				chmin(to[(c+1)%N],cur+(c+N-a)+(c+N-b+1));
			}
			else {
				chmin(to[(c+N-1)%N],cur+(a+N-c)+(b-c+1));
			}
		}
		else if(a<b) {
			//����
			chmin(to[(c+1)%N],cur+c-a+c+1-b);
			//���
			chmin(to[b],cur+a+N-c);
		}
		else {
			//����
			chmin(to[(c+N-1)%N],cur+a-c+b-c+1);
			//���
			chmin(to[b],cur+c+N-a);
		}
	}
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) from[i]=1<<30;
	from[1]=0;
	
	H[0]="L";
	T[0]=0;
	for(i=1;i<=Q;i++) {
		cin>>H[i]>>T[i];
		T[i]--;
		FOR(j,N) to[j]=1<<30;
		x=T[i-1];
		y=T[i];
		if(H[i]==H[i-1]) {
			FOR(j,N) if(j!=x) move(x,j,y,from[j]);
		}
		else {
			FOR(j,N) if(j!=x) move(j,x,y,from[j]);
			//j��y�ɓ�����
		}
		
		swap(from,to);
	}
	int ret=1<<30;
	FOR(i,N) ret=min(ret,from[i]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
