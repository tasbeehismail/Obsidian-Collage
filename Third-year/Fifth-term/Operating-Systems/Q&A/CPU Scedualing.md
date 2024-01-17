## General 
1. Module gives control of CPU by short-term scheduler? -> <span class="green">dispatcher</span>.
2. Processes in main memory ready to execute are on list called? -> <span class="green">ready queue</span>.
3. Time from submission to completion is? -> <span class="green">turnaround time</span>.
4. Algorithm allocate the CPU first? -> <span class="green">first-come, first served scheduling</span>.
5. In priority scheduling algorithm...? -> <span class="green">CPU allocated to process with highest priority</span>.
6. In priority scheduling algorithm, a process in ready queue compared with the priority of...? -> <span class="green">currently running process</span>.
7. algorithm in time quantum? -> <span class="green">round robin</span>.
8. process are classified into different groups...? -> <span class="green">multilevel queue scheduling algorithm</span>.
9. In multilevel feedback scheduling algorithm...? -> <span class="green">a process can move to a different classified ready queue</span>.
10. can't be scheduled by the kernel? -> <span class="green">user level thread</span>.

## Benefits
1. CPU scheduling is the basis of...? -> <span class="green">multiprogramming operating system</span>.
2. With multiprogramming.... is used productively? -> <span class="green">time</span>.
3. Two steps of a process execution? -> <span class="green">CPU & I/O Burst</span>.
4. An I/O bound will have? -> <span class="green">many very short CPU bursts</span>.
5. Process selected from ..... by ....., to be executed? -> <span class="green">ready, short term</span>.
6. Non-preemptive scheduling occurs? -> <span class="green">when process goes from running state to waiting state</span>.
7. the switching .... is called? -> <span class="green">*all*</span>.
8. What is dispatch latency? -> <span class="green">the time to stop and start</span>.
9. Scheduling is done so as to....? -> <span class="green">increase CPU utilization</span>.
10. Scheduling is done so as to....? -> <span class="green">increase throughput</span>.
11. Turnaround time is...? -> <span class="green">from completion till submission</span>.
12. Scheduling is done as to? -> <span class="green">decrease turnaround time</span>.
13. Waiting time is...? -> <span class="green">time in ready queue</span>.
14. Scheduling is done as to? -> <span class="green">decrease waiting time</span>.
15. Response time is...? -> <span class="green">from submission till first response is produced</span>.

## CPU Scheduling Algorithms-1
1. Round robin is under category of...? -> <span class="green">Preemptive scheduling</span>.
2. Round robin -> <span class="green">using very large time slices</span>.
3. The portion... -> <span class="green">is assigned ready process to CPU</span>.
4. Complex algorithms -> <span class="green">are very appropriate for very large computers</span>.
5. FIFO algorithm? <span class="green">first executes the job that came in first in the queue</span>.
6. strategy to making processes runnable to be temporarily suspended is called? -> <span class="green">Preemptive scheduling</span>.
7. What is Scheduling? -> <span class="green">allowing a job to use the processor</span>.
8. 10 processes, 10ms for short runtime? -> <span class="green">tQ = 15ms</span>.
9. Orders are processed if arrives .... rule? -> <span class="green">first come, first served</span>.
10. minimize the process flow time? -> <span class="green">SJF</span>.
11. short jobs is usually ________ and that for long jobs is slightly __ ? -> <span class="green">shortened, lengthened</span>.
12. which true? -> <span class="green">I, II and III</span>.

## CPU Scheduling Algorithms-2
1. most optimal algorithm? -> <span class="green">SJF</span>.
2. difficulty with SJF? -> <span class="green">knowing length of next CPU request</span>.
3. FCFS trouble some for? -> <span class="green">time sharing systems</span>.
4. waiting time for P1 is? -> <span class="green">3ms</span>.
5. Preemptive SJF also called? -> <span class="green">SRTN</span>.
6. priority for SJF algorithm is? -> <span class="green">predicted next CPU burst</span>.
7. disadvantage for priority scheduling algorithm? -> <span class="green">waiting time for low priority process</span>.
8. What is Aging? -> <span class="green">increasing priority of jobs</span>.
9. solution for low priority processes? -> <span class="green">Aging</span>.
10. which true? -> <span class="green">I, II and III</span>.
11. minimum waiting time? -> <span class="green">SJF</span>.