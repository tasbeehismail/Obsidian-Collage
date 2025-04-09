### 1. **<span class="red">Schedules of Transactions</span>**  
- A **<span class="blue">transaction schedule (history)</span>** is the order of execution of operations from multiple concurrently executing transactions in an **interleaved manner**.  
- **Order of operations**: From top to bottom (or left to right in compact notation).  
- **Operations included**:  
  - <span class="blue">read (r)</span>, <span class="blue">write (w)</span>, <span class="blue">begin (b)</span>, <span class="blue">end (e)</span>, <span class="blue">commit (c)</span>, <span class="blue">abort (a)</span>, along with transaction IDs and item names.  
- **Formal definition**:  
  > "An ordering of all the operations of the transactions subject to the constraint that, for each transaction *Ti* that participates in *S*, the operations of *Ti* in *S* must appear in the same order in which they occur in *Ti*." (Also a **<span class="red">total ordering</span>**.)  
- **Complete schedule**:  
  - Includes **all operations** of participating transactions.  
  - Ends with a <span class="blue">commit</span> or <span class="blue">abort</span> for each transaction.  
  - Maintains **order within transactions** and orders **<span class="red">conflicting operations</span>**.  

---

### 2. **<span class="red">Characterizing Schedules Based on Recoverability</span>**  
- **<span class="blue">Recoverable schedules</span>**:  
  - Ensure that once a transaction commits, it **never needs to be rolled back** (preserves durability).  
  - **Definition**:  
    > "A schedule *S* is recoverable if no transaction *T* in *S* commits until all transactions *T’* that have written an item that *T* reads have committed."  
  - **Rule**: <span class="blue">"Write first must commit first."</span>  
- **<span class="blue">Non-recoverable schedules</span>**:  
  - A committed transaction might need to be rolled back during recovery (**not allowed** in DBMS).  
- **<span class="blue">Cascading rollback</span>**:  
  - Occurs when an **uncommitted transaction** reads from a **failed transaction** and must be rolled back.  
- **<span class="blue">Cascadeless schedules</span>**:  
  - "Every transaction reads only items written by **committed transactions**." (Prevents cascading rollbacks.)  
- **<span class="blue">Strict schedules</span>**:  
  - "A transaction *T2* can **neither read nor write** an item *X* until the transaction *T1* that last wrote *X* has committed."  
- **Hierarchy**:  
  > "Any **strict schedule** is also **cascadeless**, and any **cascadeless schedule** is also **recoverable**."  
  - **Visualization**:  
    - **Strict** ⊂ **Cascadeless** ⊂ **Recoverable**.  
    - **Serial schedules** ⊂ **Strict schedules**.  

---

### 3. **<span class="red">Characterizing Schedules Based on Serializability</span>**  
- **<span class="blue">Serial schedules</span>**:  
  - Execute all operations of each transaction **consecutively** (no interleaving).  
  - **Correct but impractical** (limit concurrency).  
- **<span class="blue">Nonserial schedules</span>**:  
  - **Interleave operations** from different transactions.  
- **<span class="blue">Serializable schedules</span>**:  
  - "Equivalent to some **serial schedule** of the same *n* transactions."  
- **Equivalence types**:  
  1. **<span class="blue">Result equivalent</span>**:  
     - Produce the **same final database state**.  
     - *Weakness*: Hard to verify (may be coincidental).  
  2. **<span class="blue">Conflict equivalent</span>**:  
     - "The order of any **two conflicting operations** is the same in both schedules."  
     - **Conflicting operations**:  
       - Access the **same data item**,  
       - Are from **different transactions**,  
       - At least one is a **write**.  
- **<span class="blue">Conflict serializable schedule</span>**:  
  - A nonserial schedule **conflict-equivalent** to a serial schedule.  
  - *Example*:  
    - Schedule *A* and *D* are conflict serializable.  
    - Some schedules are **not conflict serializable**.  

---
### 4. **<span class="red">Testing for Serializability</span>**  
- **Algorithm**: Use a **<span class="blue">precedence graph</span>** (serialization graph).  
  - **Nodes**: Transactions.  
  - **Edges**:  
    - *Ti* **writes X** before *Tj* **reads X** → Edge (*Ti* → *Tj*).  
    - *Ti* **reads X** before *Tj* **writes X** → Edge (*Ti* → *Tj*).  
    - *Ti* **writes X** before *Tj* **writes X** → Edge (*Ti* → *Tj*).  
  - **Key rule**:  
    > "The schedule *S* is serializable **if and only if the precedence graph has no cycles**."  
- **Examples**:  
  - **No cycles** → Serializable.  
  - **Cycles present** → Not serializable.  

---
