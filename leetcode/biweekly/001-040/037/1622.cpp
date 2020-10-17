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


ll mo=1000000007;
template<class V,int NV> class SegTree_MulAdd {
public:
	vector<V> sum,mul,add; // sum stores val after muladd
	void init(){
		sum.clear();
		mul.clear();
		add.clear();
		sum.resize(NV*2,0); mul.resize(NV*2,1); add.resize(NV*2,0);
	};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return (ret*mul[k]+add[k]*(y-x))%mo;
	}
	void propagate(int k,int s) {
		(mul[k*2]*=mul[k])%=mo;
		(add[k*2]*=mul[k])%=mo;
		(sum[k*2]*=mul[k])%=mo;
		(add[k*2]+=add[k])%=mo;
		(sum[k*2]+=add[k]*s/2)%=mo;
		(mul[k*2+1]*=mul[k])%=mo;
		(add[k*2+1]*=mul[k])%=mo;
		(sum[k*2+1]*=mul[k])%=mo;
		(add[k*2+1]+=add[k])%=mo;
		(sum[k*2+1]+=add[k]*s/2)%=mo;
		
		mul[k]=1;
		add[k]=0;
	}

	void domul(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(mul[k]*=v)%=mo;
			(add[k]*=v)%=mo;
			(sum[k]*=v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			domul(x,y,v,l,(l+r)/2,k*2);
			domul(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(sum[k*2]+sum[k*2+1])%mo;
		}
	}
	void doadd(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(add[k]+=v)%=mo;
			(sum[k]+=(r-l)*v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			doadd(x,y,v/mul[k],l,(l+r)/2,k*2);
			doadd(x,y,v/mul[k],(l+r)/2,r,k*2+1);
			sum[k]=(sum[k*2]+sum[k*2+1])%mo;
		}
	}
};

SegTree_MulAdd<ll, 1<<18> st;

class Fancy {
public:
int id;
    Fancy() {
		id=0;
		st.init();
        
    }
    
    void append(int val) {
        st.doadd(id,id+1,val);
        id++;
    }
    
    void addAll(int inc) {
        st.doadd(0,id,inc);
    }
    
    void multAll(int m) {
        st.domul(0,id,m);
    }
    
    int getIndex(int idx) {
		if(idx>=id) return -1;
        return st.getval(idx,idx+1);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);


class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
		pair<int,int> P;
		int V=-1;
		int N=towers.size();
		int i,j;
		FOR(i,N) {
			int sum=0;
			FOR(j,N) {
				double d=hypot(towers[i][0]-towers[j][0],towers[i][1]-towers[j][1]);
				if(d<=radius) sum+=floor(towers[j][2]/(1+d));
			}
			cout<<i<<" "<<sum<<endl;
			if(V<sum) {
				V=sum;
				P={towers[i][0],towers[i][1]};
			}
			else if(V==sum) {
				P=min(P,{towers[i][0],towers[i][1]});
			}
		}
		return {P.first,P.second};
		
        
    }
};

 */
