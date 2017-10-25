fibonacci_to_perform = 10
iter = 2
fibs = {0,1}

function fibonacci()

    while iter<=fibonacci_to_perform do
    	print(fibs[iter])
    	iter = iter + 1
    	fibs[iter] = fibs[iter-1] + fibs[iter-2]
    	
    end
    
end

fibonacci()
