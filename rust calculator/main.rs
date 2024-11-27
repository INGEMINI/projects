use std::io;

fn main() {
    println!("Welcome to the Rust Calculator!");

    // Get the first number from the user
    println!("Enter the first number:");
    let mut num1 = String::new();
    io::stdin().read_line(&mut num1).expect("Failed to read line");
    let num1: f64 = num1.trim().parse().expect("Please type a valid number!");

    // Get the second number from the user
    println!("Enter the second number:");
    let mut num2 = String::new();
    io::stdin().read_line(&mut num2).expect("Failed to read line");
    let num2: f64 = num2.trim().parse().expect("Please type a valid number!");

    // Get the operation choice from the user
    println!("Choose an operation: (+, -, *, /)");
    let mut operation = String::new();
    io::stdin().read_line(&mut operation).expect("Failed to read line");
    let operation = operation.trim();

    // Perform the operation
    let result = match operation {
        "+" => num1 + num2,
        "-" => num1 - num2,
        "*" => num1 * num2,
        "/" => {
            if num2 == 0.0 {
                println!("Error! Division by zero is not allowed.");
                return;
            } else {
                num1 / num2
            }
        }
        _ => {
            println!("Invalid operation! Please use +, -, *, or /.");
            return;
        }
    };

    // Output the result
    println!("The result of {} {} {} is: {}", num1, operation, num2, result);
}
