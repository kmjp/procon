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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,18> num,sum;



class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(ALL(flowers));
        ZERO(num.bit);
        ZERO(sum.bit);
        ll fix=0;
        FORR(f,flowers) {
			if(f>=target) {
				fix+=full;
			}
			else {
				num.add(f,1);
				sum.add(f,f);
			}
		}
        while(flowers.size()&&flowers.back()>=target) flowers.pop_back();
        
        
        if(flowers.empty()) return fix;
        
        ll s=0;
        int cur=0;
        int i;
		while(cur<target-1) {
			ll need=1LL*num(cur+1)*(cur+1)-sum(cur+1);
			if(need+s>newFlowers) break;
			cur++;
		}
		ll ma=1LL*cur*partial;
		
        for(i=flowers.size()-1;i>=0;i--) {
			s+=target-flowers[i];
			num.add(flowers[i],-1);
			sum.add(flowers[i],-flowers[i]);
			if(s>newFlowers) break;
			ll sc=1LL*(flowers.size()-i)*full;
			ma=max(ma,sc);
			if(i) {
				while(cur<target-1) {
					ll need=1LL*num(cur+1)*(cur+1)-sum(cur+1);
					if(need+s>newFlowers) break;
					cur++;
				}
				while(cur) {
					ll need=1LL*num(cur)*(cur)-sum(cur);
					if(need+s<=newFlowers) break;
					cur--;
				}
				ma=max(ma,sc+1LL*cur*partial);
			}
		}
        
        
        return ma+fix;
    }
};
