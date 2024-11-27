package main

import (
	"fmt"
	"net/http"
)

func main() {
	var url string
	fmt.Print("Enter a URL: ")
	fmt.Scan(&url)

	resp, err := http.Get(url)
	if err != nil {
		fmt.Println("Error:", err)
		return
	}
	fmt.Printf("HTTP Status for %s: %s\n", url, resp.Status)
}
