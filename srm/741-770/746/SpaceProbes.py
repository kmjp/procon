
from decimal import *

class SpaceProbes:
	def focusDistance(self, x, y, z):
		getcontext().prec=1000
		x=[Decimal(a) for a in x]
		y=[Decimal(a) for a in y]
		z=[Decimal(a) for a in z]
		
		d1=[x[1]-x[0],y[1]-y[0],z[1]-z[0]]
		d2=[x[3]-x[2],y[3]-y[2],z[3]-z[2]]
		
		cr=(d1[0]*d2[0]+d1[1]*d2[1]+d1[2]*d2[2])**2
		r2=(d1[0]*d1[0]+d1[1]*d1[1]+d1[2]*d1[2])*(d2[0]*d2[0]+d2[1]*d2[1]+d2[2]*d2[2])
		x[0],y[0],z[0]=(x[0]+x[2])/2,(y[0]+y[2])/2,(z[0]+z[2])/2
		
		print(cr,r2)
		if cr==r2:
			# ïΩçs
			r=(d1[0]*d1[0]+d1[1]*d1[1]+d1[2]*d1[2])**Decimal(0.5)
			
			d1[0]/=r
			d1[1]/=r
			d1[2]/=r
			d2=[x[4]-x[0],y[4]-y[0],z[4]-z[0]]
			
			cr=d1[0]*d2[0]+d1[1]*d2[1]+d1[2]*d2[2]
			dx=x[4]-(x[0]+d1[0]*cr)
			dy=y[4]-(y[0]+d1[1]*cr)
			dz=z[4]-(z[0]+d1[2]*cr)
			
			return float((dx*dx+dy*dy+dz*dz)**Decimal(0.5))
		
		
		cross=[d1[1]*d2[2]-d1[2]*d2[1],d1[2]*d2[0]-d1[0]*d2[2],d1[0]*d2[1]-d1[1]*d2[0]]
		r=(cross[0]*cross[0]+cross[1]*cross[1]+cross[2]*cross[2])**Decimal(0.5)
		cross[0]/=r
		cross[1]/=r
		cross[2]/=r
		d2=[x[4]-x[0],y[4]-y[0],z[4]-z[0]]
		cr=cross[0]*d2[0]+cross[1]*d2[1]+cross[2]*d2[2]
		
		return float(abs(cr))
