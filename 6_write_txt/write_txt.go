package main 

import (
	"fmt"
	"io/ioutil"
	"strings"
	"os"
)

func read_txt(name string) (string,string){ // 
	b, err := ioutil.ReadFile(name) // just pass the file name
    if err != nil {
        fmt.Print(err)
    }
    str := string(b) // convert content to a 'string'
    chunks := strings.Split(str, "\n")

    first,last := chunks[0], chunks[len(chunks)-1]

    return first,last
}

func write_txt(first string, second string) bool{
	file, err := os.Create("write_go.txt")
    if err != nil {
        fmt.Print(err)
    }
    defer file.Close()

    fmt.Fprintln(file, first)
    fmt.Fprintf(file, "\n")
    fmt.Fprintf(file, second)

    return true
}

func main() {
	first,second := read_txt("data.txt")
	write_txt(first,second)
	fmt.Println("Success.")
}
