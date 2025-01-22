# Code Optimization  
Making code <span class="red">faster</span>, more <span class="red">efficient</span>, and easier to maintain. The benefits of code optimization are broadly outlined as follows:  
- **<span class="blue">Improved Performance</span>**: Optimized code runs <span class="red">faster</span>, leading to quicker response times and a smoother experience.  
- **<span class="blue">Resource Savings</span>**: Optimization reduces the <span class="red">computational power</span> and <span class="red">memory usage</span> required by making code more efficient.  
- **<span class="blue">Reduced Costs</span>**: Lower resource consumption translates directly into reduced <span class="red">operational costs</span>.  
- **<span class="blue">Enhanced User Experience</span>**: Faster and more responsive applications lead to improved overall user satisfaction.  
##### Techniques  
1. **Inlining Small Functions**:  
   This involves ==replacing function calls with the actual function code==, which can reduce the overhead associated with function calls.  
2. **Code Hoisting**:  
   This involves identifying constants that are computed multiple times and ==pre-calculating them once==, saving processing time.  
3. **Dead Store Elimination**:  
   This technique ==removes== assignments to variables that are ==not used== again, thus reducing memory operations.  
4. **Eliminating Common Sub-expressions**:  
   This involves ==avoiding recalculating the same sub-expression== within a piece of code.  
5. **Loop Unrolling**:  
   This involves reducing the overhead associated with loops, in small loops, by ==expanding the loop body== so that each iteration is replaced by multiple copies.  
6. **Code Motion**:  
   Refers to moving code, specifically code within a condition that involves constants, ==out of the conditional statement==.  
---
# Semantic Analysis  
Defined as the <span class="red">"meaning checker"</span> of code. The role of a semantic analyzer is to verify that code makes logical sense, complies with the language rules, and behaves as intended. The importance of semantic analysis is highlighted through its ability to:  
- **<span class="blue">Catch Logical Errors</span>**:  
   The analyzer flags errors that are syntactically correct but logically unsound.  
- **<span class="blue">Ensure Code Correctness</span>**:  
   By identifying and preventing logical errors, semantic analysis ensures the code behaves correctly.  
- **<span class="blue">Improve Reliability</span>**:  
   This leads to software that is more dependable and robust.  