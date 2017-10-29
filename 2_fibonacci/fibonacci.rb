def fib i
	a = 0
	b = 1
	i.times do
		b,a = b+a, b
		print b, "\n"
	end
end

fib 10
