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

ll p[7][20];

vector<int> split(int v,int n) {
	vector<int> R;
	while(n--) {
		R.push_back(v%3);
		v/=3;
	}
	return R;
}
ll build(vector<int> v,int base) {
	ll ret=0;
	int i;
	FOR(i,v.size()) ret+=v[i]*p[base][i];
	return ret;
}

template<class V> V ext_gcd(V p,V q,V& x, V& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	V g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

template<class V> pair<V,V> crt(V a1,V mo1,V a2,V mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	V g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<V,V>(-1,0); // N/A
	V lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<V,V>(-2,0); // overflow
	
	V v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	for(i=1;i<=6;i++) {
		p[i][0]=1;
		for(j=1;j<=16;j++) p[i][j]=p[i][j-1]*i;
	}
	
	for(i=1;i<=15;i++) {
		map<ll,vector<ll>> cand;
		ll p2=p[2][i];
		ll p3=p[3][i];
		ll p4=p[4][i];
		
		FOR(x,p[3][i]) {
			vector<int> v=split(x,i);
			ll v3=build(v,3);
			ll v4=build(v,4);
			ll v6=build(v,6);
			ll dif46=((v4-v6)%p2+p2)%p2;
			ll dif36=((v3-v6)%p3+p3)%p3;
			auto vv=crt<__int128>(v3,p3,v4,p4);
			cand[dif46*1000000000+dif36].push_back(vv.first);
		}
		map<ll,ll> ret;
		FORR2(a,b,cand) {
			auto V=b;
			sort(ALL(V));
			V.push_back(V[0]+p3*p4);
			FOR(j,V.size()-1) ret[V[j+1]-V[j]]++;
		}
		FORR2(a,b,ret) _P("{%d,%lld,%lld},\n",i,a,b);
	}
	*/
	ll table[][3]={
{1,1,2},
{1,10,1},
{2,1,6},
{2,142,3},
{3,1,18},
{3,286,3},
{3,1438,3},
{3,1726,3},
{4,1,54},
{4,5470,6},
{4,15262,6},
{4,20734,15},
{5,1,162},
{5,15262,18},
{5,26206,6},
{5,41470,15},
{5,192094,6},
{5,207358,15},
{5,233566,6},
{5,248830,15},
{6,1,486},
{6,264094,18},
{6,705022,54},
{6,2016862,12},
{6,2280958,42},
{6,2721886,6},
{6,2985982,111},
{7,1,1458},
{7,3250078,18},
{7,5971966,243},
{7,9222046,18},
{7,20637790,18},
{7,26609758,18},
{7,29859838,207},
{7,35831806,207},
{8,1,4374},
{8,80885662,108},
{8,182409118,18},
{8,194353054,18},
{8,235628638,18},
{8,247572574,18},
{8,349096030,108},
{8,429981694,1899},
{9,1,13122},
{9,859963390,2187},
{9,4299816958,2187},
{9,5159780350,2187},
{10,1,39366},
{10,16339304446,4374},
{10,45578059774,4374},
{10,61917364222,10935},
{11,1,118098},
{11,123834728446,19683},
{11,619173642238,19683},
{11,743008370686,19683},
{12,1,354294},
{12,2105190383614,39366},
{12,6810910064638,39366},
{12,8916100448254,98415},
{13,1,1062882},
{13,17832200896510,177147},
{13,89161004482558,177147},
{13,106993205379070,177147},
{14,1,3188646},
{14,1283918464548862,1594323},
{15,1,9565938},
{15,2567836929097726,1594323},
{15,12839184645488638,1594323},
{15,15407021574586366,1594323},
{0,15407021574586366,1594323},
	};
	int N;
	ll M;
	cin>>N>>M;
	ll ret=0;
	FOR(i,1000) {
		if(table[i][0]==0) break;
		if(table[i][0]==N&&table[i][1]>M) ret+=table[i][2];
	}
	cout<<ret<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
