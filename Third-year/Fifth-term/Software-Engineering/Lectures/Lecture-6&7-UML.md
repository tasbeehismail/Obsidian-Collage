### UML: Unified Modeling Language 
+ Notation: graphical symbols
+ Not method، is a basis for different methods
+ Diagrams:
	- Views:
		1. Use Case View: use case
		2. Structural View: class, object, composite structure, package 
		3. Implementation View: component
		4. Behavioral View: sequence, state, activity, communication, interaction, timing, collaboration
		5. Environment View: deployment


	- Definition:
		- Use case Diagram: .. from the "**user's**" point of view.
			- Components:
				- Actor: external model entities, plays a role in interactions with system. <mark style="background-color: #FFFF00">-> Default Notation Stickman, or icon for non-humans</mark>.
				- Use case: sequence of related actions, functionality that is complete from beginning to end. <mark>-> horizontal ellipsis, the name inside or underneath oval</mark>.
				- System boundary(optional): <mark>> rectangle</mark>
				- Associations: <mark>-> solid line</mark>
					- Use cases' relationships:
						- << extend >>: a generalization relationship, for additional action to continues the behavior of a base use case.
						- << include >>: a generalization relationship, the inclusion of all behavior in base use case.  <mark>---></mark>
						- inheritance: offering a third opportunity to indicate potential reuse. <mark>---></mark>
					- Actors' relationships: generalization/specialization, aggregations or compositions. <mark>-></mark>
			- Description:
				- provide the details of sequence with each use case.
				- a narrative description of the sequence of steps is needed.
				- in natural language.
				- show who is carrying out the step.
				- show the intent of the actor not the mechanics of what actor does.
				
		- Class Diagram:  .. "**static structure**" in terms of classes and relationships.
			- Components:
				- topmost: name of the class (bold, singular, first char is capital).
				- middle: a list of attributes (member variables).
				- bottom: list of operations (member functions).
			- Relationships:
				- Association: semantic connection among classes <mark>━━━━</mark>(name) - **bi-directional**
				- Aggregation: whole and parts <mark><>━━━━ </mark> - **bi-directional**
				- Composition: <mark>◄►━━━━</mark>(name) - **bi-directional**
				- Multiplicity and Navigation: how many objects participate -  the navigation is in **one direction** <mark>━━━━></mark>

				| ![multiplicity-arrows.png](https://github.com/tasbeehismail/Obsidian-Collage/blob/main/Third-year/Fifth-term/Software-Engineering/images/multiplicity-arrows.png?raw=true) | 
				|:--:| 
				| *Multiplicity Arrows Types* |
	
				- Dependency: change in one is may cause a change in other - "using". <mark>------></mark>
				- Generalization: hierarchy - subclasses(descendent - child) and superclass(ancestor - parent) <mark>━━━━></mark> "is-a-kind-of" 
					- Inheritance:
						- Overriding: replacing a method by a more specific implementation of that method in a subclass.
			- Abstract class: the basis of further subclasses can have instances.
			- Concrete class: the class can be instantiated.
   
		- Object Diagram: "**objects and their relationships**", simplified diagrams that don't represent massage broadcast.
		
		- Sequence Diagram : are temporal representation of "**objects and their interactions ordered by time**", represent flow of each use case.
			- Users:
				- Users: see the specifics of their <mark>business preocessing</mark>.
				- Analysts: see the <mark>flow</mark> of the sequences.
				- Developers: see <mark>objects</mark> that need to be developed and <mark>perations</mark> foe those objects.
				- Quality assurance engineers: see the <mark>details of the process</mark> and develop <mark>test cases</mark> based on the processing.
			- Diagram:
				- objects and actors listed along the top of digram.
				- interactions indicated by annotated arrows (........).
				- the dotted lines meaning the lifeline of object over time.
				- activations: when an object is do action.
				- messages: the communication between objects.
					- synchronous message symbol: a sender must wait for a response  before it continues. <mark>━━━━►</mark>
					- asynchronous message symbol: doesn't wait for the receiver and return before sending other messages... <mark >━━━━></mark>
					- alternative: conditions indicated in square brackets.
					- loop
		- Collaboration: are spatial representation of **"object, links, and interactions"**.
		
		- State chart: **"dynamic behavior of the system in response to external and internal events"** in terms of states.
			- finite number of states.
			- modeling real-time system.
			- nodes and events as arcs, from one state to another.
			- describe the temporal evolution.
			- consists of:
				- a finite, non-empty set of states. ▭
				- a finite, non-empty set of events.
				- state transition. ━━━━►
				- an initial state (start). ⬤
				- a set of final states (end). ◯
			- not useful to do state diagrams for every class. (large, complex).

		- Activity: the **parallel behavior** of an operation as a set of actions.
		
		- Component: **logical** components of an application.
		
		- Deployment: components in particular **pieces of hardware**.
		
- Data Processing models:
	- Data Flow Diagrams (DFDs): <mark>graphical</mark> representation of the <mark>movement</mark> of data between <mark>external entities</mark>, <mark>processes</mark> and <mark>data stores</mark> within a system.
		- show steps as data flows through a system.
		- can be used in showing the data exchange between a system and other systems.
		- help to understand the overall of the system.
		- simple notation so the customer can understand it.
		- how the data moves through an information system.
		- **in other words**, how data is processed in terms of inputs and outputs.
		- Components:-
			- Process: the work or action so they are transformed, stored or distributed. *(in verb phrases)* ▭▭
			- Data Flow: a path for data to move from one part to another. *(no verbs)* ━━━━►
			- Data Store: data the system store it. *(noun - no verbs)* ▯▭
			- External Entity:  the origin or destination of data -> things outside the system. *(noun - no verb)*
				- source: supplies..
				- sink: receives..
			- Rules:
				- For process:
					- process have minimum one data flow into and out of it.
					- must be linked to either another process and data store.
					- process can't exist by itself...
					- bidirectional flow between data store and process is represented by two separate arrows.
				- For data store:
					- have at least one data flow from it and to it.
					- must be used, must be updated.
				- For external entities:
					- no data moves directly between entities without going through a process.
			- decomposed into additional diagrams (multiple levels of detail).
			- DFD Levels:
				- Context: overview...
					- Show the system boundaries.
					- Identify the main system in one process.
					- Identify the external entities
					- what data will enter to system
					- what data receive output from system.
					- <mark>NO DATA STORES HERE</mark>.
				- Level-0: major processes pf high level of abstraction.
					- break the processes int 2 or more sub-processes.
					- what data flows between processes and external entities.
					- what data stores.
					- <mark>No New External Entities</mark>.
				- Level-1: result form decomposition of level-0.
				- Level-2:  result form decomposition of level-1.
			- The number of levels depends on the complexity of the system to Level-n DFD.
			- DFD Balancing:
				- number of inputs and outputs to *lower level DFD* equals to inputs and output of *higher level DFD*. 

			| ![balanced-DFD.png](https://github.com/tasbeehismail/Obsidian-Collage/blob/main/Third-year/Fifth-term/Software-Engineering/images/balanced-DFD.png?raw=true) | 
			|:--:| 
			| *Balanced DFD* |
			
			| ![unbalanced-DFD.png](https://github.com/tasbeehismail/Obsidian-Collage/blob/main/Third-year/Fifth-term/Software-Engineering/images/unbalanced-DFD.png?raw=true) | 
			|:--:| 
			| *Unbalanced DFD* |
