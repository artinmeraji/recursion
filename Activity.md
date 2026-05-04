# C++ Recursion Assignment

**Objective:** Get these C++ recursions working and explain how they're actually doing their thing.

### Question 1
**What's the base case?**
The base case in this function is `return if low > high`. 

**Why does it stop?**
Basically, it's the "kill switch." Without it, the function would just keep adding 2 to `low` and calling itself forever. Once `low` finally gets bigger than `high` (like if it hits 12 when the limit was 10), the function hits that `return` and stops everything so we don't get stuck in an infinite loop.

---

### Question 2
**Prediction for factorial(10):**
Honestly? It's going to crash. Specifically, it'll cause **infinite recursion** and then a **stack overflow**.

**Why?**
Because the function is doing `n - 2` and the base case is only checking for `n == 1`. Since we're starting at 10 (an even number), the sequence goes 10, 8, 6, 4, 2, 0, -2... and so on. It totally "jumps over" the 1. Since it never hits exactly 1, it never triggers the base case and just keeps going until the computer runs out of memory.

---

### Question 3
**Fixing the sum function:**
I added a check to see if `low == high`. That way, when we've worked our way all the way down to the first number, we stop and start adding everything back up.

```cpp
#include <iostream>

int sum(int low, int high) {
    // Base case: stop when we reach the bottom of the range
    if (low == high) {
        return low;
    }
    // Recursive step: add the current high number and call sum again with high-1
    return high + sum(low, high - 1);
}

int main() {
    std::cout << "The sum from 1 to 10 is: " << sum(1, 10) << std::endl; 
    return 0;
}
```
**How it works:**
It's like a stack of plates. `sum(1, 10)` waits for `sum(1, 9)`, which waits for `sum(1, 8)`, and so on. When it finally hits `sum(1, 1)`, it returns 1, and then all those waiting functions finally finish their math and add the numbers together to get 55.

---

### Question 4
**Printing nested numbers:**
C++ doesn't really let you throw ints and arrays into the same list easily like Python does, so I used `std::variant`. It's a bit more work but it's super clean for recursion.

```cpp
#include <iostream>
#include <vector>
#include <variant>

// This struct lets us nest vectors inside vectors
struct Node;
using Element = std::variant<int, std::vector<Node>>;

struct Node {
    Element value;
};

// This is the recursive magic
void printNumbers(const Node& node) {
    // Base Case: If it's just an int, print it!
    if (std::holds_alternative<int>(node.value)) {
        std::cout << std::get<int>(node.value) << std::endl;
    } 
    // Recursive Step: If it's a vector, loop through it and call this function again
    else {
        const auto& subArray = std::get<std::vector<Node>>(node.value);
        for (const auto& item : subArray) {
            printNumbers(item);
        }
    }
}

int main() {
    // Setting up the nested structure from the prompt
    // [1, 2, 3, [4, 5, 6], 7, ...]
    Node n1{1}, n2{2}, n3{3}, n7{7};
    std::vector<Node> inner1 = {Node{4}, Node{5}, Node{6}};
    Node sub1{inner1};
    
    // I won't build the WHOLE thing here because it's huge, 
    // but the logic works for any depth!
    std::vector<Node> rootList = {n1, n2, n3, sub1, n7};
    Node root{rootList};

    printNumbers(root); 

    return 0;
}
```
**The logic:**
The function checks: "Are you a number?" If yes, print it. If no, it assumes you're a list, so it goes *into* that list and runs the same check on everything inside. It doesn't matter how many layers deep the numbers are; it'll keep digging until it finds them all.

---

**Conclusion:**
Recursion is pretty cool once you get the base cases right. It's basically just a way to make a function solve a smaller version of itself until it hits a simple answer. Coffee helps too.
