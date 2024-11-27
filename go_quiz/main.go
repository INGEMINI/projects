package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type Question struct {
	question string
	answer   string
}

func main() {
	fmt.Println("Welcome to the Quiz Game!")

	// Check if questions file exists, and create it if not
	filename := "questions.txt"
	if _, err := os.Stat(filename); os.IsNotExist(err) {
		fmt.Println("No questions file found. Let's create one!")
		createQuestionsFile(filename)
	}

	fmt.Println("Loading questions...\n")
	questions, err := loadQuestions(filename)
	if err != nil {
		fmt.Printf("Error loading questions: %v\n", err)
		return
	}

	score := 0
	reader := bufio.NewReader(os.Stdin)

	// Quiz loop
	for i, q := range questions {
		fmt.Printf("Question %d: %s\n", i+1, q.question)
		fmt.Print("Your answer: ")
		userAnswer, _ := reader.ReadString('\n')
		userAnswer = strings.TrimSpace(strings.ToLower(userAnswer))

		if userAnswer == strings.ToLower(q.answer) {
			fmt.Println("Correct!")
			score++
		} else {
			fmt.Printf("Wrong! The correct answer was: %s\n", q.answer)
		}
		fmt.Println()
	}

	// Display final score
	fmt.Printf("Quiz Over! Your final score: %d/%d\n", score, len(questions))
}

// createQuestionsFile writes a default set of questions to the file
func createQuestionsFile(filename string) {
	defaultQuestions := []Question{
		{"What is the capital of France?", "Paris"},
		{"What is 5 + 7?", "12"},
		{"Who wrote 'Hamlet'?", "Shakespeare"},
		{"What is the square root of 64?", "8"},
		{"Which planet is known as the Red Planet?", "Mars"},
	}

	file, err := os.Create(filename)
	if err != nil {
		fmt.Printf("Error creating file: %v\n", err)
		return
	}
	defer file.Close()

	writer := bufio.NewWriter(file)
	for _, q := range defaultQuestions {
		_, err := writer.WriteString(fmt.Sprintf("%s,%s\n", q.question, q.answer))
		if err != nil {
			fmt.Printf("Error writing to file: %v\n", err)
			return
		}
	}
	writer.Flush()
	fmt.Printf("File '%s' created with default questions.\n\n", filename)
}

// loadQuestions reads questions and answers from a file
func loadQuestions(filename string) ([]Question, error) {
	file, err := os.Open(filename)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	var questions []Question
	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Split(line, ",")
		if len(parts) == 2 {
			questions = append(questions, Question{
				question: strings.TrimSpace(parts[0]),
				answer:   strings.TrimSpace(parts[1]),
			})
		}
	}

	if err := scanner.Err(); err != nil {
		return nil, err
	}

	return questions, nil
}
