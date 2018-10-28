
# Author: Felipe Pfeifer Rubin
# Contact: felipe.rubin@acad.pucrs.br
import sys

def karatsuba(x,y):
	x = str(x)
	y = str(y)
	if len(x) == 1 and len(y) == 1:
		return int(x) * int(y)

	maxlength = len(x) if len(x) > len(y) else len(y)
	maxlength = maxlength if maxlength%2 == 0 else maxlength+1
	x = '0' * abs(len(x) - maxlength) + x
	y = '0' * abs(len(y) - maxlength) + y

	xhi = x[0:len(x)/2]
	xlo = x[len(x)/2:len(x)]
	yhi = y[0:len(y)/2]
	ylo = y[len(y)/2:len(y)]

	# print "a = karatsuba(%d,%d)",xhi,yhi
	a = karatsuba(xhi,yhi)
	b = karatsuba(xlo,ylo)

	e = karatsuba(int(xhi) + int(xlo), int(yhi)+int(ylo)) - a - b

	#return a * pow(10,maxlength) + e * pow(10,maxlength/2) + b
    return int(str(a) + '0'*maxlength) + int(str(e)+ '0'*(maxlength/2)) + b



print karatsuba(sys.argv[1],sys.argv[2])
