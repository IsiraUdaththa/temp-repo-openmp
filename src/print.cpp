#include <print>
#include <string>

int main() {
    int age = 25;
    std::string name = "Alice";

    // Using format specifiers %s for string and %d for integer
    // printf("Name: %s, Age: %d\n", name.c_str(), age);
    std::print("Hello, {}! The answer is {}.\n", "world", 42);
    
    return 0;
}