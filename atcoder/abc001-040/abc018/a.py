import sys
import math

A=input()
B=input()
C=input()

if C<A and C<B and B<A:
	print "1\n2\n3"
if C<A and C<B and B>A:
	print "2\n1\n3"
if A<B and A<C and B<C:
	print "3\n2\n1"
if A<B and A<C and B>C:
	print "3\n1\n2"
if B<A and B<C and A<C:
	print "2\n3\n1"
if B<A and B<C and A>C:
	print "1\n3\n2"
