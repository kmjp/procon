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

ll N,mo;
const int NUM_=7000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	ll C[4]={};
	//0��
	C[0]=1;
	//1��
	//�ǂ���ł��ǂ�
	C[1]=fact[N]-1;
	//�O���łȂ��Ƃ���
	C[1]+=fact[2*N]-fact[N];
	//�㔼�łȂ��Ƃ���
	C[1]+=fact[2*N]-fact[N];
	C[1]=(C[1]%mo+mo)%mo;

	//2��
	//�O�����
	//�擪N�Ɍ㔼N��1�ȏ゠��A�㔼�ɐ擪N���Ȃ�
	//�㔼�ɐ擪N���Ȃ�
	C[2]+=2*comb(2*N,N)*fact[N]%mo*fact[2*N]%mo;

	//�ǂ����ł������P�[�X
	//�㔼�̂��̂��O���ɂȂ��A�O���̂��̂��㔼�ɂȂ�
	//�㔼�̂��̂��^�񒆂ɗ��鐔�𐔂���
	FOR(i,N+1) {
		ll a=comb(N,i); //�^�񒆂ɑ���㔼��N��I��
		ll b=comb(N,i); //���ɑ���^�񒆂�N��I��
		ll c=comb(N,i)*fact[i]%mo; //�^�񒆒��̈ʒu�ƕ���
		ll d=fact[N]; //���N�̕���
		ll e=fact[2*N-i]; //�O�ƌ��̎c��̃P�[�X
		(C[2]-=a*b%mo*c%mo*d%mo*e%mo)%=mo;
	}
	//1��̃P�[�X��߂�
	C[2]-=C[0];
	C[2]-=C[1];
	C[2]=(C[2]%mo+mo)%mo;

	//3��
	C[3]=fact[3*N]-C[0]-C[1]-C[2];
	
	ll ret=0;
	FOR(i,4) ret+=i*C[i];
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
