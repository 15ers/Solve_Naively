package main

import "fmt"

var n int
var time, price []int

func max(x, y int) int{
    if x < y {
        return y
    }
    return x
}
func findMax(cur_day, cur_price int) int{
    if cur_day >= n{
        return cur_price
    }
    if cur_day+time[cur_day] > n{
        return findMax(cur_day+1,cur_price)
    }else{
        return max(findMax(cur_day+1,cur_price), findMax(cur_day+time[cur_day],cur_price+price[cur_day]))
    }
}
func main(){
    fmt.Scan(&n)
    time = make([]int,0,n)
    price = make([]int,0,n)
    for i:=1;i<=n;i++{
        var time_elem, price_elem int
        fmt.Scanln(&time_elem, &price_elem)
        time = append(time, time_elem)
        price = append(price, price_elem)
    }
    fmt.Println(findMax(0,0))
}