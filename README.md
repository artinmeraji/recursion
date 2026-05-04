# C++ RECURSION HOMEWORK 

**Yo, here is my recursion assignment!** I've broken it down by question. All the actual code logic is inside the `solutions.cpp` file if you want to run it.

---

### **Question 1: The Base Case**
The base case is basically just `if (low > high) return;`. 

**Why does it even matter?**
Without this, the function would **never stop**. It would just keep adding 2 to the `low` number and calling itself until the computer gets confused and crashes. This line tells it: **"Hey, once you pass the limit, we're done here."**

---

### **Question 2: The Factorial Disaster**
**My prediction:** This is going to **crash hard**. It'll cause a **stack overflow**.

**The Reason:** 
Because we're doing `n - 2` starting from 10, the numbers go: **10, 8, 6, 4, 2, 0, -2...** Notice something? It **totally skips over 1**. Since the base case is *exactly* `n == 1`, and we never hit 1, the function just keeps going down into negative numbers forever. **Infinite recursion!**

---

### **Question 3: The Sum Fix**
I fixed the code by adding the **base case** `if (low == high)`. 

**How it works:**
The function keeps subtracting 1 from `high` and adding it to the pile until it reaches the `low` number. Then it stops and **unwinds** the stack, adding everything up. 
*Check the `sum` function in `solutions.cpp` for the full C++ version!*

---

### **Question 4: Deeply Nested Arrays**
This one was tricky because C++ is picky about types. I used a **recursive struct with std::variant** to handle it.

**The Strategy:**
1. **Base Case:** If the item is just a regular integer, **print it**.
2. **Recursive Step:** If the item is *another* list, loop through it and call the **exact same function** on every item inside.

This way, it doesn't matter how many brackets are there, the code will **dig all the way down** until it finds the numbers.

---

### **Conclusion**
**Recursion is basically just a loop that is way more fancy (and easier to break if you forget the base case).** Everything is pushed to the repo now. Time for more coffee. 
