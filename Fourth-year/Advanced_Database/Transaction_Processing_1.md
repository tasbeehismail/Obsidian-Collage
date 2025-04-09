## Introduction to Transaction Processing  
- **Transaction**: An executing program (process) that includes <span class="red">one or more database access</span> operations such as:  
    - <span class="blue">Read (SELECT)</span>  
    - <span class="blue">Write (INSERT, UPDATE, DELETE)</span>  
- Transactions are considered a **<span class="red">logical unit of database processing</span>**.  
- Transactions can be:  
    - **<span class="blue">Standalone</span>** (SQL submitted interactively)  
    - **<span class="blue">Embedded</span>** within a program  
- Boundaries of a transaction are defined by **<span class="red">Begin and End transaction</span>**.  
- An application program can contain multiple transactions.  

## Single-User vs. Multiuser Systems  
- **<span class="blue">Single-user DBMS</span>**: Allows only one user at a time (e.g., <span class="blue">Microsoft Access</span>).  
- **<span class="blue">Multiuser DBMS</span>**: Allows multiple users to access the database concurrently (e.g., <span class="blue">airline reservations, banking systems</span>).  
- **<span class="red">Multiprogramming</span>**: The operating system executes multiple programs/processes **interleaved** on a single CPU.  
- **<span class="red">Parallel Processing</span>**: Possible with multiple CPUs.  
- Most **<span class="red">concurrency control theory</span>** is based on **interleaved concurrency**.  

## Transactions, Database Items, Read/Write Operations, and DBMS Buffers  
- Transactions involve:  
    - **<span class="red">Insertion, deletion, modification, and retrieval</span>** operations.  
    - **<span class="red">Begin and End transaction</span>** statements explicitly defining transaction boundaries.  
    - Can be **<span class="blue">read-only</span>** or **<span class="blue">read-write</span>**.  
- **Database structure**:  
    - A database is a **<span class="red">collection of named data items</span>**.  
    - Data item **<span class="red">granularity</span>** varies (record, disk block, field value).  
- **Basic operations**:  
    - **<span class="blue">read_item(X)</span>**: Reads database item **X** into a program variable.  
    - **<span class="blue">write_item(X)</span>**: Writes program variable **X** back into the database.  
- **DBMS Buffers**:  
    - **<span class="red">Database cache</span>** stores data blocks in the main memory.  
    - **<span class="red">Buffer replacement policy</span>** determines which blocks to overwrite when memory is full.  
- **<span class="blue">Read-set</span>**: Items a transaction reads.  
- **<span class="blue">Write-set</span>**: Items a transaction modifies.  

## Why Concurrency Control Is Needed  

### Problems in Multiuser Systems  
1. **<span class="red">Lost Update Problem</span>**: Two transactions update the same item concurrently, causing an update to be lost.  
2. **<span class="red">Temporary Update (Dirty Read) Problem</span>**: A transaction reads a value that is later rolled back by another transaction.  
3. **<span class="red">Incorrect Summary Problem</span>**: A transaction calculates an aggregate while another updates the items, leading to inconsistency.  
4. **<span class="red">Unrepeatable Read Problem</span>**: A transaction reads the same item twice, but another transaction modifies it in between.  

## Why Recovery Is Needed  
- **<span class="red">Transactions must either complete fully (commit) or leave no effect on the database (abort)</span>**.   
- **Transaction Status**:  
    - **<span class="blue">Commit</span>**: Transaction successfully completes.  
    - **<span class="blue">Abort</span>**: Transaction fails and its changes must be undone.  
- **Types of Failures**:  
    1. **<span class="blue">Transaction Failure</span>** (e.g., logical errors, overflow, data not found).   
    2. **<span class="blue">System Failure</span>** (e.g., hardware, software, or network crashes).  
    3. **<span class="blue">Media Failure</span>** (e.g., disk failures, lost data blocks).  
    4. **<span class="blue">Physical Problems & Catastrophes</span>** (e.g., power failure, fire, operator errors).  

## Transaction and System Concepts  
### Key Transaction Operations:  
- **<span class="blue">BEGIN_TRANSACTION</span>**: Starts execution.  
- **<span class="blue">READ/WRITE</span>**: Database access.  
- **<span class="blue">END_TRANSACTION</span>**: Marks execution end (changes may not be permanent yet).  
- **<span class="blue">COMMIT_TRANSACTION</span>**: Signals success and applies changes permanently.  
- **<span class="blue">ROLLBACK (ABORT)</span>**: Signals failure, and all changes must be undone.  

### Transaction States:  
- **<span class="blue">Active</span>** → **<span class="blue">Partially Committed</span>** → **<span class="blue">Committed/Failed</span>** → **<span class="blue">Terminated</span>**  
- **<span class="red">DBMS maintains a system log</span>** (sequential, append-only file) to track all changes.  
- **Log Entries Include**:  
    - <span class="blue">[start_transaction, T]</span>  
    - <span class="blue">[read_item, T, X]</span>  
    - <span class="blue">[write_item, T, X, old_value, new_value]</span>  
    - <span class="blue">[commit, T]</span>  
    - <span class="blue">[abort, T]</span>  
- **Uses of the Log**:  
    - Undo changes of aborted transactions.  
    - Redo committed transactions if a failure occurs before writing changes to disk.  

## Commit Point of a Transaction  
- A transaction reaches **<span class="red">commit point</span>** when all its database operations are successful.  
- A committed transaction writes a <span class="blue">[commit, T]</span> record in the **log**.  
- **During Recovery**:  
    - Transactions without <span class="blue">[commit, T]</span> are **rolled back**.  
    - Committed transactions are **redone** from the log.  

## Desirable Properties of Transactions (ACID)  
1. **<span class="red">Atomicity</span>**: A transaction is an **atomic unit** of processing (all or nothing).  
    - Ensured by **<span class="blue">transaction recovery subsystem</span>**.  
2. **<span class="red">Consistency Preservation</span>**: A transaction moves the database **from one consistent state to another**.  
    - Ensured by **<span class="blue">integrity constraints</span>** and **<span class="blue">database programmers</span>**.  
3. **<span class="red">Isolation</span>**: A transaction executes **as if it is the only one**, even in concurrent environments.  
    - Ensured by **<span class="blue">concurrency control mechanisms</span>**.  
4. **<span class="red">Durability</span>**: Committed transaction changes **persist in the database**.  
    - Ensured by **<span class="blue">recovery mechanisms</span>**.  

--- 
