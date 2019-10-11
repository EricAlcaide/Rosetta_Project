#------------------------------------------------------------------
			#SIMPSON'S RULE
#------------------------------------------------------------------

#Remember that n must be even.

function simp_comp(f,a,b,n)
	h = (b - a) / (n-1)
	x0 = f(a) + f(b)
	x1 = 0
	x2 = 0
	x = 0

	for i = 1 : (n-2)
		x = a + i*h
		if ( (i % 2) == 0 )
			x2 = x2 + f(x)
		else
			x1 = x1 + f(x)
		end
	end

	x1 = (h*(x0+2*x2+4*x1))/3
	
	return x1
end

#------------------------------------------------------------------
			#TRAPEZOID RULE
#------------------------------------------------------------------

function trap_comp(f,a,b,n)
	h = (b - a) / (n-1)
	suma = (f(a) + f(b)) / 2

	for i = 1 : (n-2)
		suma += f(a+i*h)
	end

	suma = suma * h
	
	return suma
end

#------------------------------------------------------------------
			#MIDDLE POINT RULE
#------------------------------------------------------------------

function pm_comp(f,a,b,n)
	suma = 0
	h = (b - a) / (n+2)

	for i = 0 : (n/2)
		suma += f(a + (i + 1) * h) 
	end

	suma *= 2*h

	return suma
end
