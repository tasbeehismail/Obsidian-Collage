## TCP/IP
+ Application, Transport, Internet (Network, Data link), Host-to-network

### Host-to-network layer
+ The host has to connect to the network using some protocol so it can send packets to it.
+ Possible connections:
	– LAN -> router -> Internet
	– Dial-up -> router -> Internet
	– ADSL -> router -> Internet
### Internet layer
+ Its job is to permit hosts to inject packets into any network and have them travel independently to the destination.
+ -> IP Protocol
+ Some issues:
	– Packet routing
	– Avoiding congestion
	– QoS

### Transport layer
+ It is designed to allow peer entities on the source and destination hosts to carry on a conversation.
+ -> TCP (reliable connection oriented protocol)
+ -> UDP (unreliable connectionless protocol)


### Application layer
+ It contains all the higher-level protocols:
	+ HTTP
	+ FTP
	+ TFTP (Trivial File Transfer Protocol)
	+ SMTP
	+ POP
	+ DNS
	+ NNTP (Network News Transfer Protocol)
	+ DHCP


## Differences for the OSI and TCP/IP:
+ TCP/IP model was developed prior to the OSI model.
+ 7 layers / 4 or 5 layers
+ Network & Data link, Transport and Application are common.
+ OSI: Connection-oriented and connectionless communication in network layer connection-oriented in transport layer.
+ TCP: connectionless communication in network layer connection-oriented and connectionless communication in transport layer.

### Why OSI did not take over the world
+ Bad timing: The time at which a standard is established is absolutely critical to its success.
+ Bad technology: Both the model and the protocols are flawed, extraordinarily complex, difficult to implement and inefficient in operation.
+ Bad implementation: The initial implementations were huge, unwieldy, and slow.
+ Bad politics: was thought to be the creature of government bureaucrats.

### Problems of TCP/IP model:
+ Service, interface, and protocol not distinguished.
+ Not a general model.
+ Host-to-network “layer” not really a layer.
+ No mention of physical and data link layers.
+ Minor protocols deeply entrenched, hard to replace.

## The Hybrid Reference Model
![[hybridModel.png]]