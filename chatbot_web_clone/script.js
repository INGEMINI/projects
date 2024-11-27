// DOM Elements
const userInput = document.getElementById('user-input');
const sendBtn = document.getElementById('send-btn');
const chatMessages = document.getElementById('chat-messages');

// Mock ChatGPT-like bot logic
async function getBotResponse(userMessage) {
    // Simulate a delay for a realistic typing effect
    return new Promise((resolve) => {
        setTimeout(() => {
            const responses = [
                "Hi! How can I help you today?",
                "That's an interesting question!",
                "I'm still learning, but I'll try my best to help.",
                "Could you clarify that for me?",
                "It sounds like you're onto something great!"
            ];

            // Choose a random response for simplicity
            const randomResponse =
                responses[Math.floor(Math.random() * responses.length)];
            resolve(randomResponse);
        }, 1000);
    });
}

// Function to create and add a message to the chat window
function addMessage(content, sender) {
    const message = document.createElement('div');
    message.classList.add('message', sender);
    message.textContent = content;

    // Add the message to the chat
    chatMessages.appendChild(message);

    // Auto-scroll to the latest message
    chatMessages.scrollTop = chatMessages.scrollHeight;
}

// Handle sending user input
async function handleUserInput() {
    const userMessage = userInput.value.trim();

    if (userMessage === "") {
        return; // Don't send empty messages
    }

    // Add user's message to chat
    addMessage(userMessage, 'user');

    // Clear the input field
    userInput.value = "";

    // Display a "typing" indicator
    const typingIndicator = document.createElement('div');
    typingIndicator.classList.add('message', 'bot');
    typingIndicator.textContent = "ChatGPT is typing...";
    chatMessages.appendChild(typingIndicator);

    // Fetch the bot's response
    const botMessage = await getBotResponse(userMessage);

    // Remove the "typing" indicator and add bot's response
    chatMessages.removeChild(typingIndicator);
    addMessage(botMessage, 'bot');
}

// Event listeners
sendBtn.addEventListener('click', handleUserInput);
userInput.addEventListener('keydown', (e) => {
    if (e.key === 'Enter' && !e.shiftKey) {
        e.preventDefault();
        handleUserInput();
    }
});
