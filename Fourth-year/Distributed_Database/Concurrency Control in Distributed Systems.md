### 1. **Distributed Two-Phase Locking (2PL) Algorithm**
   - **Basic Principle**: Similar to the basic 2PL protocol, but in a distributed system, there are **<span class="red">lock managers</span>** at different sites.
   - **Lock Managers**: Control ==lock acquisition requests== from transaction monitors.
   - **Coordination**: At least one site is given the authority to detect **<span class="red">lock conflicts</span>** across all transactions.
##### **Types**:
1. **Centralized Two-Phase Locking**:
   - **<span class="red">One central lock manager</span>** is designated.
   - All sites request locks from this central manager.
   - **<span class="blue">Example</span>**: If Site A needs a lock, it contacts the central lock manager at Site C.
2. **Primary Copy Two-Phase Locking**:
   - Multiple **<span class="red">lock control centers</span>** are designated.
   - Each center manages a specific set of locks.
   - **<span class="blue">Example</span>**: Site X manages locks for Table 1, while Site Y manages locks for Table 2.
3. **Distributed Two-Phase Locking**:
   - Each site has its own **<span class="red">lock manager</span>**.
   - Lock managers control locks for data items stored locally.
   - **<span class="blue">Example</span>**: Site A manages locks for its local data, and Site B does the same for its data.
### 2. **Distributed Timestamp Concurrency Control**
   - **Timestamps**: In a distributed system, timestamps are a combination of **<span class="red">site ID</span>** and **<span class="red">local clock reading</span>**.
   - **Scheduler**: Each site has a scheduler that maintains queues for transaction managers.
   - **Processing**: Requests are processed in **<span class="red">timestamp order</span>** (==oldest first==).
   - **<span class="blue">Example</span>**: If Transaction T1 has a timestamp of (Site 1, 10) and T2 has (Site 2, 5), T2 is processed first.
### 3. **Conflict Graphs**
   - **Transaction Classes**: Defined by **<span class="red">read sets</span>** and **<span class="red">write sets</span>**.
   - **Conflict Graph**: A graph with:
     - **Vertical Edges**: Conflicts within the same class.
     - **Horizontal Edges**: **<span class="blue">Write-Write conflicts</span>** across classes.
     - **Diagonal Edges**: **<span class="blue">Write-Read or Read-Write conflicts</span>** across classes.
   - **<span class="blue">Example</span>**: If Transaction T1 writes to Data X and T2 reads from Data X, a diagonal edge is created.
### 4. **Distributed Optimistic Concurrency Control**
   - **Rule 1**: Transactions must be **<span class="red">validated locally</span>** at all sites. If invalid, the transaction is aborted.
   - **Rule 2**: After local validation, transactions must be **<span class="red">globally validated</span>**.
   - **<span class="blue">Example</span>**: If Transaction T1 and T2 conflict at multiple sites, they must commit in the same order globally.
----
## **Deadlock Handling in Distributed Systems**
- **Deadlock**: a state in a database system where **<span class="red">two or more transactions are waiting</span>** for each other to release locks on data items. This creates a ==cycle of dependencies==, and none of the transactions can proceed.
- **Wait-for-Graph**: A directed graph used to detect deadlocks.
	- **Vertices**: Represent transactions.
	- **Edges**: Represent waits for data items.
- **<span class="blue">Example</span>**: 
     - T1 waits for X (locked by T3).
     - T3 waits for Y (locked by T2).
     - T2 waits for Z (locked by T1).
	This forms a cycle, causing a deadlock.
#### **Approaches:**
 1. **Deadlock Prevention**
   - **Goal**: Prevent deadlocks by ensuring that transactions **<span class="red">cannot acquire locks</span> that would lead to a deadlock.
   - **Method**: Only ==one transaction is allowed== to lock a data item at a time.
   - **Pre-acquisition of Locks**:
     - A transaction acquires all required locks **before** starting execution.
     - If another transaction needs any of these locks, it must wait until all locks are available.
     - **Advantage**: Prevents deadlocks since no transaction holds locks while waiting.
     - **<span class="blue">Example</span>**: T1 locks X, Y, and Z before starting execution.
 2. **Deadlock Avoidance**
   - **Goal**: Handle deadlocks **before they occur** by analyzing transactions and locks.
   - **Method**: ==The lock manager checks== if granting a lock request could lead to a deadlock.
   - **<span class="blue">Algorithms</span>**:
     1. **Wait-Die**:
        - If T1 is **older** than T2, T1 is allowed to **wait**.
        - If T1 is **younger** than T2, T1 is **aborted** and restarted later.
     2. **Wound-Wait**:
        - If T1 is **older** than T2, T2 is **aborted** and restarted later.
        - If T1 is **younger** than T2, T1 is allowed to **wait**.
 3. **Deadlock Detection and Removal**
   - **Goal**: Allow deadlocks to occur but detect and remove them **<span class="red">periodically</span>.
   - **Method**: ==The system periodically checks== the **wait-for-graph** for cycles.
     - If a cycle is found, a **victim transaction** is selected and aborted to break the deadlock.
   - **Victim Selection Criteria**:
     - Choose the **youngest transaction**.
     - Choose the transaction with the **fewest data items**.
     - Choose the transaction with the **least number of updates**.
     - Choose the transaction with the **least restart overhead**.
     - Choose the transaction common to **two or more cycles**.
   - **<span class="blue">Example</span>**: 
     - T1, T2, and T3 are deadlocked.
     - T3 (youngest) is aborted to resolve the deadlock.
---
---
## **Deadlock Handling in Distributed Systems** (Again)
   - **<span class="red">Challenge</span>**: Transactions in distributed systems may be active at multiple sites, leading to additional ==complexities== like:
	 1. **Transaction Location**
	   - **<span class="red">Issue</span>**: Transactions may be **active at some sites** and **inactive at others**.
	   - ==**Solution**==: **Daisy Chain Model**.
	     - A transaction carries details (e.g., acquired locks, visited sites) as it moves between sites.
	     - After a transaction terminates (commit or abort), the information is sent to all concerned sites.
	   - **<span class="blue">Example</span>**: T1 moves from Site A to Site B, carrying its lock information.
	 2. **Transaction Control**
	   - **<span class="red">Issue</span>**: Designating and controlling the sites required for processing a transaction.
	   - ==**Options**==:
	     1. **One server** as the center of control.
	     2. **Traveling center of control** (moves between servers).
	     3. **Shared control** among multiple servers.
##### 1. **Distributed Deadlock Prevention**
   - **Method**: Transactions acquire all locks **<span class="red">before starting execution</span>**.
   - **Process**:
     - The **<span class="red">controlling site</span>** sends messages to lock data items at other sites.
     - The transaction starts only after all sites confirm that locks are acquired.
   - **Drawbacks**:
     - Long communication delays.
     - Blocking if a site or link fails.
   - **<span class="blue">Example</span>**: T1 locks X, Y, and Z at Sites A, B, and C before starting.
##### 2. **Distributed Deadlock Avoidance**
   - **Method**: Handles deadlocks **<span class="red">before they occur</span>** by addressing **transaction location** and **control**.
   - **Algorithms**:
     1. **Distributed Wait-Die**:
        - If T1 is ==**older**== than T2, T1 waits.
        - If T1 is ==**younger**== than T2, T1 is aborted.
     2. **Distributed Wound-Wait**:
        - If T1 is ==**older**== than T2, T2 is aborted.
        - If T1 is ==**younger**== than T2, T1 waits.
   - **<span class="blue">Example</span>**: 
     - T1 at Site P tries to lock X (locked by T2 at Site Q).
     - In **Distributed Wait-Die**, T1 waits.
     - In **Distributed Wound-Wait**, T2 is aborted.
##### 3. **Distributed Deadlock Detection**
   - **Method**: Deadlocks are allowed to occur and are detected using **<span class="red">global wait-for-graphs</span>** or **<span class="red">timers</span>**.
   - **Global Wait-for-Graph**:
     - Detects cycles across multiple sites.
     - **<span class="red">Challenge</span>**: Difficult to spot deadlocks due to network delays.
   - **Timers**:
     - Each transaction has a timer. If the transaction doesn’t finish in time, it’s considered deadlocked.
   - **Deadlock Detectors**:
     1. **Centralized Deadlock Detector**: One site detects deadlocks for all sites.
     2. **Hierarchical Deadlock Detector**: Multiple detectors arranged in a hierarchy.
     3. **Distributed Deadlock Detector**: All sites participate in detecting deadlocks.
   - **<span class="blue">Example</span>**: 
     - T1, T2, and T3 are deadlocked across Sites A, B, and C.
     - The **<span class="red">centralized detector</span>** at Site D detects the cycle and resolves it.