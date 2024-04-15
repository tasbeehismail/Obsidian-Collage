## Data Flow Diagram (DFD)
### Elements of DFD: 
+ Process: activity or function
+ Data flow: single or collection
+ Data store: out or in
+ External entity: person, organization or system
## Relationship among levels of DFDs:
Decomposition is the process of representing the system in a hierarchy of DFD diagrams.
+ Context Diagram: Shows the overall business process as just one process.
+ Level 0: Shows all the major processes that comprise the overall system.
+ Level 1: Shows all the internal processes that comprise a single process on the level 0 diagram.
+ Level 2: Shows all processes that comprise a single process on the level 1 diagram.

**DFDs start with the use cases and requirements definition**

### When to stop decomposing DFDs?
Ideally, a DFD has at least 3 processes and no more than 7 to 9.

## Validating the DFD:
+ Check each process for: unique name(verb), at least one in and out data flow, in data flow names usually different then out.
+ Check each data flow for: unique name(noun), at least one process, one direction, minimum number of crossed lines.
+ Check each data store for: unique name(noun), at least one in and out data flow.
+ Check each external entity for: unique name(noun), at least one in *or* out data flow.
## Across DFDs:
+ Context Diagram: Every set of DFDs must have one Context Diagram.
+ Viewpoint: There is a consistent viewpoint for the entire set of DFDs.
+ Decomposition: Every process is wholly and complete described by the processes on its children DFDs.
+ Balance: Every data flow, data store, and external entity on a higher level DFD is shown on the lower level DFD that decomposes it.
