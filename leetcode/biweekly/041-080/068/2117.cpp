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



class Solution {
public:
    string abbreviateProduct(int left, int right) {
		double a=0;
		int i;
		
		int e=0;
		ll cur=1;
		int s=0;
		for(i=left;i<=right;i++) {
			cur=cur*i;
			while(cur%10==0) {
				cur/=10;
				e++;
			}
			a+=log10(i);
			while(a>100) a-=1;
			
			if(cur>=100000000000LL) {
				s=1;
				cur=cur%100000000000LL;
			}
		}
		if(cur>=10000000000LL) {
			s=1;
			cur=cur%10000000000LL;
		}
		if(s==0) {
			return to_string(cur)+"e"+to_string(e);
		}
		string suf="0000000"+to_string(cur);
		suf="..."+suf.substr(suf.size()-5)+"e"+to_string(e);
		string prefix=to_string(pow(10,a));
		return prefix.substr(0,5)+suf;
        
    }
};
