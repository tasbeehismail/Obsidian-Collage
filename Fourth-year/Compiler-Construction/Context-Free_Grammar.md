#### **1. Position in Compilation**
- ==Syntax analysis==, or parsing, is the **second phase** of a compiler, following lexical analysis (tokenization).
- **Input**: The parser receives a ==stream of tokens== from the lexical analyzer.
- **Function**: It checks the ==grammatical correctness== of the input token stream based on defined production rules and detects syntax errors.
  - <span class="blue">Example</span>: The parser analyzes the source code (token stream) against the production rules to detect errors.
- **Error Handling**: When a syntax error is detected, the compiler should "put out an informative message for the user."
- **Output**: The output of syntax analysis, when no errors are present, can be a stream of ==atoms==, ==syntax trees==, or ==parse trees==.
  - <span class="blue">Example</span>: A parse tree is "a data structure in which the interior nodes represent operations, and the leaves represent operands."
#### **2. Syntax vs Semantics**
- **Syntax**: Refers to ==grammatical correctness==.
  - <span class="blue">Example</span>:
    - `x = (2+3) * 9);` (==mismatched parentheses==)
    - `if x > y x = 2;` (==missing parentheses==)
    - `while (x==3) do f1();` (==invalid keyword `do`==)
- **Semantics**: Refers to the ==meaning== of expressions, statements, and program units.
  - <span class="blue">Example</span>:
    - `if(a=5)` (==assignment in conditional==)
    - `for(int i=0;i<10;i++);` (==empty loop==)
#### **3. Why Context-Free Grammars?**
- **Limitations of Regular Expressions**: Regular expressions cannot handle ==balancing tokens== like parentheses.
  - <span class="blue">Example</span>: Regular expressions cannot check balancing tokens, such as parentheses.
- **CFGs and Push-Down Automata**: CFGs are recognized by ==push-down automata==, making them suitable for handling the more complex syntax of programming languages.
- **Expressiveness**: CFGs are more expressive than finite automata.
  - <span class="blue">Example</span>: "Context-free languages are a larger class of languages that encompasses all regular languages and many others."
- **Non-Regular Languages**: Simple languages like `{a^n b^n : n = 0, 1, 2, …}` and `{w : w is a palindrome}` are not regular.
#### **4. Components of a Context-Free Grammar**
A CFG is defined as a 4-tuple `G = (V, T, S, P)`:
- **V (Variables/Non-terminals)**: Represent constructs in the language.
- **T (Terminal Symbols)**: The elementary symbols (tokens) of the language.
- **S (Start Symbol)**: The non-terminal where the derivation process begins.
- **P (Productions)**: Rewriting rules of the form `nonterminal -> sequence of terminals and/or nonterminals`.
#### **5. Grammar Conventions**
- **Terminals**: Lowercase letters and numbers.
- **Non-terminals**: Uppercase letters or words starting with an uppercase letter.
---
#### **6. Derivations**
- **Process**: Starting with the start symbol, production rules are repeatedly applied to produce a ==sentential form==.
- **Sentential Form**: A mix of terminals and non-terminals.
- **Language Membership**: A string is in the language when it contains only terminals.
- **Leftmost Derivation**: Replace the ==leftmost non-terminal== first.
- **Rightmost Derivation**: Replace the ==rightmost non-terminal== first.
#### **7. Derivation Trees (Parse Trees)**
- **Graphical Representation**: Depicts how a string is derived from the start symbol.
- **Components**:
  - Root: Start symbol.
  - Leaves: Terminals.
  - Interior nodes: Non-terminals.
- **Yield**: The leaves, read left to right, form the derived string.
#### **8. Ambiguity**
- **Definition**: A grammar is ==ambiguous== if there is more than one derivation tree for a single string.
- **Consequences**: Different parse trees can lead to different interpretations of the input.
- **Examples**:
  - Arithmetic Expressions: `Expr -> Expr + Expr | Expr * Expr | (Expr) | var | const` is ambiguous.
    - <span class="blue">Example</span>: `var + var * var` has two distinct derivation trees.
  - Dangling Else: `IF_STMT -> if EXPR then STMT | if EXPR then STMT else STMT`.
- **Resolution**: Use unambiguous grammars.
  - <span class="blue">Example</span>: `E -> E + T | T`, `T -> T * F | F`, `F -> (E) | a`.

