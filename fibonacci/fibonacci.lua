fibonacci_to_perform = 11
iter = 2
fibs = {0,1}

function fibonacci()

    while iter<=fibonacci_to_perform do
    	iter = iter + 1
    	fibs[iter] = fibs[iter-1] + fibs[iter-2]
        print(fibs[iter])
    	
    end
    
end

fibonacci()
