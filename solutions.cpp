#include <iostream>
#include <vector>
#include <variant>

// --- QUESTION 3: The Sum Function ---
int sum(int low, int high) {
    // Base case: stop when we reach the bottom of the range
    if (low == high) {
        return low;
    }
    // Recursive step: add current high and move down
    return high + sum(low, high - 1);
}

// --- QUESTION 4: Nested Array Printing ---
struct Node;
using Element = std::variant<int, std::vector<Node>>;

struct Node {
    Element value;
};

void printNumbers(const Node& node) {
    if (std::holds_alternative<int>(node.value)) {
        std::cout << std::get<int>(node.value) << std::endl;
    } else {
        const auto& subArray = std::get<std::vector<Node>>(node.value);
        for (const auto& item : subArray) {
            printNumbers(item);
        }
    }
}

int main() {
    // Testing Question 3
    std::cout << "--- Q3: Sum Result ---" << std::endl;
    std::cout << "Sum (1 to 10): " << sum(1, 10) << std::endl;

    // Testing Question 4 (Small sample of the nested structure)
    std::cout << "\n--- Q4: Nested Numbers ---" << std::endl;
    Node n1{1}, n2{2}, n3{3};
    std::vector<Node> inner = {Node{4}, Node{5}};
    Node sub{inner};
    std::vector<Node> rootList = {n1, n2, n3, sub};
    Node root{rootList};

    printNumbers(root);

    return 0;
}
