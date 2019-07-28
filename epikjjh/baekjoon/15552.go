package main

import (
    "fmt"
    "bufio"
    "os"
)

func main(){
    var t, a, b int
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    fmt.Fscanln(reader, &t)
    for i:=0;i<t;i++{
        fmt.Fscanln(reader, &a, &b)
        fmt.Fprintln(writer, a+b)
    }
    writer.Flush()
}