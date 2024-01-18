## The OSI reference model
+ Design principles:
	1. A layer should be created where a **different abstraction** is needed.
	2. Each layer should perform a **well-defined function**.
	3. The function of each layer should be chosen with an eye toward **defining internationally standardized protocols**.
	4. **The layer boundaries** should be chosen to minimize the information flow across the interfaces.
	5. **The number of layers** should be:-
		+ large enough that distinct functions need not be thrown together in the same layer out of necessity.
		+ small enough that the architecture does not become unwieldy.


### Physical layer: (bits)
+ The designed issues deal with mechanical, electrical, and timing interfaces.

### Data link layer: (frame)
+ This layer is to take a raw transmission facility and transform it into a line.

### Network layer: (packets)
+ This layer is concerned with controlling the operation of the subnet.

### Transport layer: (segment)
+ To accept data from the session layer, split it up info smaller units if need be, pass these to the network layer, and ensure that the pieces all arrive correctly at the other end.

### Session layer: (message)
+ To allow users on different machines to establish sessions between them.

### Presentation layer: (message)
+ The presentation layer is concerned with the syntax and semantics of the information transmitted.

-> Big-endian: is an order in which the "big end" (most significant value in the sequence) is stored first, at the lowest storage address.
-> Little-endian: is an order in which the "little end" (least significant value in the sequence) is stored first.

### Application layer: 
+ This layer contains a variety of protocols that are commonly needed.
+ Protocols:
	+ HTTP (WWW)
	+ telnet (network virtual terminal)
	+ FTP (File Transfer Protocol)
	+ DNS (Domain Name System)
	+ DHCP (Dynamic Host Configuration Protocol)
	+ SMTP (Simple Mail Transfer Protocol)
	+ POP

*****
