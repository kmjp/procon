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

const ll mo=1000000007;

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
		sort(ALL(inventory));
		vector<pair<int,int>> V;
		V.push_back({0,0});
		V.push_back({0,0});
		FORR(v,inventory) {
			if(V.back().first!=v) V.push_back({v,0});
			V.back().second++;
		}
		
		ll ret=0;
		while(orders) {
			int dif=V.back().first-V[V.size()-2].first;
			ll num=V.back().second;
			if(dif==0) {
				V[V.size()-2].second+=V.back().second;
				V.pop_back();
				continue;
			}
			
			if(dif*num>=orders) {
				ll a=V.back().first;
				ll b=V[V.size()-2].first+1;
				ll s=orders/num;
				(ret+=((a+a-(s-1))*s/2)%mo*num)%=mo;
				orders%=num;
				a-=s;
				(ret+=a*orders)%=mo;
				break;
			}
			else {
				orders-=dif*num;
				ll a=V.back().first;
				ll b=V[V.size()-2].first+1;
				V.pop_back();
				V.back().second+=num;
				(ret+=((a+b)*(a-b+1)/2)%mo*num)%=mo;
			}
			
		}
		return ret;
        
    }
};

