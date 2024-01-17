## What is an OS?
+ A program that acts as an <span class="red">intermediary</span> between a **user** of a computer and the computer **hardware**.
## Goals:
+ Execute **user programs**.
+ Make solving user problems **easier**.
+ Make the computer system **convenient** to use.
+ Use the hardware of computer **efficient**.

## Computer System Structure:
1. **Hardware**: provides basic computing resources.  -> (CPU, memory, I/O devices, ...).
2. **Operating system**: controls and coordinates use of hardware among various applications and users. 
3. **Application programs**: define how system resources are used to solve the computing problems of the users. -> (Word processor, web browser, database systems, video games, ...).
4. **Users**: -> (People, machines, other computers).

## What Operating Systems Do:
**-> From User view**: want <span class="blue">convenience</span>, ease of use. and <span class="red">don't</span> care about resources utilization.
**-> How OS provide that for?** 
	- Shared Computers as <span class="green">mainframe</span> or <span class="green">minicomputer</span> must keep all users happy.
	- Dedicate systems as <span class="green">workstations</span> have its resources but also use shared resources from <span class="green">servers</span>. 
	- <span class="green">Handheld</span> computers are resource poor, optimized for usability and battery life.
	- <span class="green">Embedded</span> computers in devices and automobiles don't have user interface.

## Operating System Definition:
+ OS is a <span class="blue">resource allocator</span>:
	+ Manages all resources.
	+ Decides between conflicting requests.
+ OS is <span class="blue">control program</span>:
	+ Controls execution of programs to prevent **errors**.
+ <span class="blue">Kernel</span> is the only program running <span class="red">all times</span> on the computer, and everything else is a <span class="purple">system program</span> (ships with OS) or an <span class="purple">application program</span>.

## Computer Setup:
+ <span class="purple">Bootstrap Program</span>: is loaded at **power-up** or **reboot**.
	+ Stored in **ROM** or **EPROM**, known as <span class="blue">firmware</span>.
	+ Initialize all **aspects** of system.
	+ Loads OS **kernel** and starts execution.

## Computer System Organization: 
+ one or more **CPUs**, **device controllers** connect through common **bus**, and all access to shared **memory**.
![[computer-sys-org.png]]
## Computer System Operation:
+ I/O devices and CPU execute concurrently.
+ Each device **controller** in charge of a device type.
+ Each device **controller** has a **local buffer**.
+ **CPU** moves data from/to main **memory** to/from **local buffers**.
+ **I/O** moves data from **device** to **local buffer** of controller.
+ Devices controller informs CPU if finished his operation by send an <span class="yellow">interrupt</span>.

## Common Functions of Interrupts:
+ <span class="yellow">Interrupt</span> transfers control to the <span class="yellow">interrupt service routine</span>, through <span class="yellow">interrupt vector</span> (contains the addresses of all the service routines).
+ <span class="yellow">Interrupt architecture</span> must **save** the **address** of the interrupted instruction.
+ Incoming interrupts are *disabled* while another interrupt is being processed.
+ A <span class="blue">trap</span> is a software-generated interrupt caused either by an error or a user request.
+ An operating system is <span class="red">interrupt driven</span>.

## I/O Structure:
+ 
