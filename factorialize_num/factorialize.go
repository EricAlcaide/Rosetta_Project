package main 

import "fmt"

func factorialize(num int) int{
	if num <=1{
		return 1
	}else{
		return num*factorialize(num-1)
	}
}

func main() {
	test := 5
	fmt.Println(factorialize(test))
}