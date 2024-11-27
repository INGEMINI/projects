package main

import (
	"crypto/rand"
	"fmt"
	"math/big"
)

func generatePassword(length int) string {
	chars := "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"
	result := make([]byte, length)
	for i := range result {
		b, _ := rand.Int(rand.Reader, big.NewInt(int64(len(chars))))
		result[i] = chars[b.Int64()]
	}
	return string(result)
}

func main() {
	fmt.Println("Generated password:", generatePassword(12))
}
