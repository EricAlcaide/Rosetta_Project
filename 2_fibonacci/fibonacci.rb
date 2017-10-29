def fib i
	a = 0
	b = 1
	i.times do
		c = a + b
		a = b
		b = c
		puts c
	end
end

fib 10
