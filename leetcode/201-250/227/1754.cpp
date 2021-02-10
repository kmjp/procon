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

using VT = string;

static const ll mo0=1000000021,mo1=1000000009;
static ll mul0,mul1;
static const ll add0=1000010007, add1=1003333331;
static vector<ll> pmo[2];

struct RollingHash {
	VT s; int l; vector<ll> hash_[2];
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009,mul1=10007;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	pair<ll,ll> hash(int l,int r) { // s[l..r]
		if(l>r) return make_pair(0,0);
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
			             (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
};


class Solution {
public:
    string largestMerge(string word1, string word2) {
        int A=word1.size();
        int B=word2.size();
        RollingHash HA,HB;
        HA.init(word1);
        HB.init(word2);
		
		string S;
		int x=0,y=0;
		int i;
		while(x<A||y<B) {
			if(x==A) {
				S+=word2[y++];
			}
			else if(y==B) {
				S+=word1[x++];
			}
			else {
				int same=0;
				for(i=12;i>=0;i--) {
					if(x+same+(1<<i)>A) continue;
					if(y+same+(1<<i)>B) continue;
					if(HA.hash(x,x+(same+(1<<i)-1))==HB.hash(y,y+(same+(1<<i)-1))) same+=1<<i;
				}
				
				int x2=x+same;
				int y2=y+same;
				if(y2==B) {
					S+=word1[x++];
				}
				else if(x2==A) {
					S+=word2[y++];
				}
				else if(word1[x2]<word2[y2]) {
					S+=word2[y++];
				}
				else {
					S+=word1[x++];
				}
			}
		}
		return S;
        
    }
};
