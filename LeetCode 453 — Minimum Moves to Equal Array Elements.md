# LeetCode 453 — Minimum Moves to Equal Array Elements

> **Pattern:** Greedy + Mathematical Transformation  
> **Difficulty:** Easy 🟢  
> **Core Idea:** Incrementing $n - 1$ elements is mathematically identical to decrementing the remaining single element!

---

## 🎬 1. The Hook: What's the Catch?

Imagine you're playing a puzzle game. You have an array of numbers, and your goal is to make every single number completely identical. 

The rule sounds innocent enough:
> *"Pick $n - 1$ elements and add $+1$ to each of them in a single move."*

Let’s try it out on `nums = [1, 2, 3]` ($n = 3$):
```text
[1, 2, 3] 
   ⬇️ (Increment 2nd and 3rd elements by 1)
[1, 3, 4]
   ⬇️ (Increment 2nd and 3rd elements by 1)
[1, 4, 5]
   ⬇️ (Increment 2nd and 3rd elements by 1)
[1, 5, 6] ❌ (Wait, these aren't equal yet!)
```

If you try to brute-force this by blindly simulating every move, you’ll quickly realize numbers are growing out of control, and it's super inefficient. There has to be a smarter way. **Let's flip the perspective! 💡**

---

## 🧠 2. The Mind-Blowing Intuition (The "Aha!" Moment)

Look closely at what happens when we increment $n - 1$ elements. 

Let's take `[1, 2, 3]` again. Suppose we increment the last two elements (`2` and `3`):
```text
[1, 2, 3]  ──►  [1, 3, 4]
```

Now, ask yourself: **What if we had incremented *all* three elements instead?**
```text
[1, 2, 3]  ──►  [2, 3, 4]
```
That would give us `[2, 3, 4]`. But we only wanted to increment *two* of them. How do we turn `[2, 3, 4]` back into `[1, 3, 4]`? 
Simple! Just **subtract $1$ from the first element** (the one we left untouched).

Boom! Look at that:
```text
Incrementing (n - 1) elements = Incrementing ALL elements AND decrementing 1 element
```
And since adding the exact same value to *every* element in the array shifts everything uniformly (preserving their relative distances), adding to all elements doesn't change how far apart they are. 

Therefore, our complex operation simplifies down to this:

> 🛠️ **The Master Key:**  
> **Incrementing $n - 1$ elements by $1$** $\equiv$ **Decrementing $1$ element by $1$**

---

## 🎯 3. The Greedy Strategy: Bringing Everyone Down

Once we unlock that transformation, the problem completely transforms:
* **Old problem:** Bump up $n-1$ numbers until they match the highest number.
* **New problem:** Pull elements down by $1$ until they match the **minimum element** in the array.

> ❓ **Why the minimum?**  
> Because the lowest number in your array is your baseline floor. You can't decrement elements *below* the minimum without adding extra, unnecessary moves. Bringing every element down to the minimum value gives us the absolute fewest operations possible!

---

## 🧪 4. Step-by-Step Dry Run

Let’s trace `nums = [1, 2, 3]` using our new decrement strategy:

1. **Find the Minimum:**  
   $$\text{minimum} = 1$$

2. **Calculate How Far Each Element is From the Minimum:**
   * Element `1`: needs $1 - 1 = 0$ decrements
   * Element `2`: needs $2 - 1 = 1$ decrement
   * Element `3`: needs $3 - 1 = 2$ decrements

3. **Sum Them Up:**  
   $$\text{Total Moves} = 0 + 1 + 2 = \mathbf{3}$$

✨ **Alternative Mathematical Formula:**  
Notice that summing all differences `(num - minimum)` is the exact same thing as:  
$$\text{Ans} = \text{Sum of all elements} - (n \times \text{minimum})$$

---

## 💻 5. Clean & Optimal Code

Here is how we write it cleanly in **C++**, **Python**, and **JavaScript**:

### C++
```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Step 1: Find the smallest element in the array
        int mini = *min_element(nums.begin(), nums.end());
        int ans = 0;

        // Step 2: Accumulate the difference for each element
        for (int num : nums) {
            ans += num - mini;
        }

        return ans;
    }
};
```

### Python
```python
class Solution:
    def minMoves(self, nums: list[int]) -> int:
        # Step 1: Find the minimum value
        mini = min(nums)
        
        # Step 2: Sum up the distance of each element from the minimum
        return sum(num - mini for num in nums)
```

### JavaScript
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
    // Step 1: Find the minimum value
    const mini = Math.min(...nums);
    
    // Step 2: Accumulate differences
    let ans = 0;
    for (const num of nums) {
        ans += num - mini;
    }
    
    return ans;
};
```

---

## ⏱️ 6. Complexity Analysis

* 🕒 **Time Complexity:** $\mathcal{O}(n)$ — We iterate through the array once to find the minimum element, and a second time (or combined) to calculate the differences. Super fast!
* 📦 **Space Complexity:** $\mathcal{O}(1)$ — We only use a couple of variables (`mini`, `ans`), meaning constant extra memory.

---

## ⚠️ Pro-Tip / Watch Out!
Don't confuse this problem with **LeetCode 462 (Minimum Moves to Equal Array Elements II)**, where you can increment or decrement *any single element by 1* per move. 
* *LeetCode 453 (This problem):* Group operation $\rightarrow$ Solved using the **Minimum**.
* *LeetCode 462:* Individual operations $\rightarrow$ Solved using the **Median**.
