## Process Synchronization
1. can be affected by other processes? -> <span class="green">cooperating process.</span>
2. depends on the order in which the access takes place is called? -> <span class="green">race condition</span>.
3. if a process is executing in its critical section, and others no, the condition called? -> <span class="green">mutual exclusion</span>.
4. A synchronization tool? -> <span class="green">semaphore</span>.
5. A semaphore is a shared integer variable? -> <span class="green">can not drop below zero</span>.
6. Mutual exclusion provided by? -> <span class="green">both mutex locks and binary semaphores</span>.
7. high priority task by medium priority task, the scenario called? -> <span class="green">priority inversion</span>.
8. Process synchronization can be done on? -> <span class="green">both hardware and software level</span>.
9. A monitor is a module that encapsulates? -> <span class="green">(*all*) shared data, procedures and synchronization</span>.
10. To enable a process to wait within the monitor? -> <span class="green">a condition variable must be declared as condition</span>.


## Process Creation
1. Restricting the child process to a subset of the parent's prevents any process from? -> <span class="green">overloading.... a lot of sub-processes</span>.
2. A parent process calling ....... until children processes terminate? -> <span class="green">wait</span>.
3. Cascading termination refers to.....? -> <span class="green">Normally or abnormally</span>.
4. With ....... only one process ......, With ...... more than one process....? -> <span class="green">Uniprogramming, Multiprocessing</span>.
5. In UNIX, each process is identified by its .....? -> <span class="green">Process Identifier</span>.
6. In UNIX, the return value is ..... for child, and ..... for parent? -> <span class="green">Zero, A nonzero integer</span>.
7. The child process can ..... ? -> <span class="green"> be a duplicate of the parent process</span>.
8. The child process when complete execution, but the parent keeps executing, the child is known as? -> <span class="green">Zombie</span>.


## Inter Process Communication
1. What is interprocess communication? -> <span class="green">allows processes to communicate and synchronize their actions</span>.
2. Message passing system allows to? -> <span class="green">communicate with each other without sharing the same address space</span>.
3. Two operations are provided by IPC facility? -> <span class="green">receive & send massage</span>.
4. Messages sent by a process .....? -><span class="green">can be fixed or variable sized.</span>
5. send and receive link between P and Q processes called? -> <span class="green">communication link</span>.
6. TRUE for direct communication? -> <span class="green">is associated with exactly two processes</span>.
7. In indirect communication between P & Q? -> <span class="green"> there is a mailbox to help communication</span>.
8. In the non blocking send? -> <span class="green">send the massage and resumes operation</span>.
9. In the zero capacity queue? -> <span class="green">the sender blocks until the receiver receives the massage</span>.
10. The zero capacity queue ....? -> <span class="green"> is a message system with no buffering</span>.
11. Bounded capacity and Unbounded capacity referred to as ...? -> <span class="green">Automatic buffering</span>. 


