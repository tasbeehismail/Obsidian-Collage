   - Query processing in distributed systems involves **two levels of optimization**:
     1. **<span class="red">Global Optimization</span>**: Done at the controlling site (client) where the query is validated, translated, and optimized globally.
     2. **<span class="red">Local Optimization</span>**: Done by local database servers to optimize queries at the fragment level.
   - The goal is to **minimize data transfer** and **maximize resource utilization** across distributed sites.
#### 1. Mapping Global Queries to Local Queries
   - **Local databases** only store information about **local data fragments**.
   - The **global optimizer** uses the **global data dictionary** to:
     - Reconstruct the **global view** from distributed fragments.
     - Decide where to execute local queries based on:
       - **<span class="red">Data replication</span>**: If data is replicated, the optimizer selects the best site based on:
         - <span class="blue">Communication cost</span>.
         - <span class="blue">Workload</span>.
         - <span class="blue">Server speed</span>.
       - If no replication, queries are executed at the site where the data is stored.
   - The global optimizer generates a **distributed execution plan** that specifies:
     - **Location of fragments**.
     - **Order of query steps**.
     - **Processes for transferring intermediate results**.
   - **Local query results** are merged using:
     - **Union operation** for **horizontal fragments**.
     - **Join operation** for **vertical fragments**.
#### 2. **Key Issues in Distributed Query Optimization**
   - **<span class="red">Optimal Resource Utilization</span>**:
     - Efficiently use resources across distributed sites.
     - Approaches include:
       1. **Operation Shipping**: Run operations at the site where the data is stored.
          - Example: **<span class="blue">Select</span>** and **<span class="blue">Project</span>** operations.
       2. **Data Shipping**: Transfer data fragments to the server where the operation is executed.
          - Used when operands are distributed across sites.
       3. **Hybrid Shipping**: Combines operation and data shipping.
          - Data is transferred to high-speed processors for execution, and results are sent back to the client.
   -  **<span class="red">Query Trading</span>**:
     - The controlling site (**buyer**) assigns sub-queries to local sites (**sellers**).
     - The buyer selects the optimal plan based on:
       - Local optimized query plans from sellers.
       - Communication costs for reconstructing the final result.
   - **<span class="red">Reduction of Solution Space</span>**:
     - Use heuristic rules to reduce query and data transfer costs:
       1. Perform **<span class="blue">selection</span>** and **<span class="blue">projection</span>** operations as early as possible.
       2. Simplify operations on **horizontal fragments** by eliminating irrelevant selection conditions.
       3. For **join** and **union** operations, transfer fragmented data to the site with the most data.
       4. Use **semi-join** operations to reduce data transfer.
       5. Merge common leaves and sub-trees in distributed query trees.
---
# Transaction Processing Systems
   - A **<span class="red">transaction</span>** is a logical unit of work that includes one or more database operations (e.g., **insert**, **delete**, **update**, **retrieve**).
   - Transactions ensure that the database remains **<span class="red">consistent</span>** and **<span class="red">reliable</span>**.
   - **<span class="red">Atomicity</span>**: A transaction is either **fully completed** or **not executed at all** (no partial updates).
   - **<span class="blue">Read-Only Transaction</span>**: A transaction that only retrieves data without modifying it.
#### 1. **Transaction Operations**
   - Transactions consist of **<span class="red">low-level operations</span>**:
     1. **begin transaction**: Marks the start of a transaction.
     2. **read_item()**: Reads a data item from storage to main memory.
     3. **modify_item()**: Changes the value of an item in main memory.
     4. **write_item()**: Writes the modified value from main memory back to storage.
     5. **end transaction**: Marks the end of a transaction.
     6. **commit**: Signals that the transaction has been successfully completed and changes are permanent.
     7. **rollback**: Signals that the transaction has failed, and all temporary changes are undone.
#### 2. **Transaction States**
   - A transaction goes through a series of **<span class="red">states</span>** during its lifecycle:
     1. **Active**: The transaction is executing read/write operations.
     2. **Partially Committed**: The last statement of the transaction has been executed.
     3. **Committed**: Changes are made permanent in the database, and the transaction is complete.
     4. **Failed**: An error occurs, and normal execution cannot proceed.
     5. **Aborted**: The transaction is rolled back, and the database is restored to its state before the transaction begins.
     6. **Terminated**: The transaction is either committed or aborted and is no longer active.
#### 3. ACID Properties of Transactions
 1. **<span class="red">Atomicity</span>**: The transaction is treated as a single, indivisible unit.
 2. **<span class="red">Consistency</span>**: The transaction brings the database from one valid state to another.
 3. **<span class="red">Isolation</span>**: Concurrent transactions do not interfere with each other.
 4. **<span class="red">Durability</span>**: Once a transaction is committed, its changes are permanent, even in case of system failure.
#### 4. **Schedules and Conflicts**
   - A **<span class="red">schedule</span>** is the order in which operations from multiple transactions are executed. **<span class="blue">Types of Schedules</span>**:
     1. **Serial Schedule**: Only one transaction is active at any time.
     2. **Parallel Schedule**: Multiple transactions are active simultaneously.
   - **<span class="red">Conflicts</span>** occur when two transactions perform incompatible operations on the same data item:
     - Both operations are part of different transactions.
     - Both access the same data item.
     - At least one operation is a **<span class="blue">write_item()</span>**.
#### 5. **Serializability**
   - A schedule is **<span class="red">serializable</span>** if it is equivalent to a serial schedule (i.e., it produces the same result as if transactions were executed one after another).
   - **<span class="blue">Types of Equivalence</span>**:
     1. **Result Equivalence**: Two schedules produce identical results.
     2. **View Equivalence**: Two schedules perform similar actions in a similar manner.
     3. **Conflict Equivalence**: Two schedules have the same order of conflicting operations.
#### 6. **Concurrency Control Techniques**
   - Concurrency control ensures that multiple transactions execute simultaneously while maintaining **<span class="red">ACID properties</span>** and **<span class="red">serializability</span>**.
   - **Lock-Based Protocols**:
     1. **One-Phase Locking**: A transaction locks an item before use and releases it immediately after.
        - Does not guarantee serializability.
     2. **Two-Phase Locking (2PL)**:
        - **<span class="blue">Growing Phase</span>**: A transaction acquires all locks it needs.
        - **<span class="blue">Shrinking Phase</span>**: A transaction releases locks and cannot request new ones.
        - Guarantees serializability but reduces parallelism.
   - **Timestamp-Based Protocols**:
     - Each transaction is assigned a unique timestamp. **<span class="blue">Rules</span>**:
       1. **Access Rule**: Older transactions have priority over younger ones.
       2. **Late Transaction Rule**: Older transactions cannot read/write data items written by younger transactions.
       3. **Younger Transaction Rule**: Younger transactions can read/write data items written by older transactions.
   - **Optimistic Concurrency Control**:
     - Used in systems with low conflict rates. **<span class="blue">Phases</span>**:
       1. **Execution Phase**: Fetch data and perform operations.
       2. **Validation Phase**: Check for serializability.
       3. **Commit Phase**: Write changes to the database.