## H02: Hashing
### Fernando Gonzalez
### Description: 


## Part A: Conceptual Questions


### 1. What is a Hash Table and Why is Collision Resolution Necessary?
A hash table is a data structure that maps keys to values using a hash function, which computes an index (hash code) for each key. This allows for quick data retrieval. 
However, since different keys may produce the same hash code, collisions occur. Collision resolution techniques are necessary to ensure all keys are stored and retrieved efficiently.


### 2. Differences Between Open Hashing and Closed Hashing
Open Hashing- (Separate Chaining): Uses linked lists (or other structures) in each bucket to handle multiple keys with the same hash value.
Closed Hashing- (Open Addressing): Stores all keys within the hash table itself, resolving collisions through probing.


### 3. Collision Resolution Techniques
Linear Probing: Places the key in the next available slot if a collision occurs.

Pros: Simple to implement.

Cons: Causes primary clustering, where consecutive occupied slots slow down insertions.

Quadratic Probing: Uses a quadratic function to find the next available slot.

Pros: Reduces clustering compared to linear probing.

Cons: Might not use all available slots and can still suffer from secondary clustering.

Double Hashing: Uses a second hash function to determine probe intervals.

Pros: Distributes keys more uniformly.

Cons: Requires careful choice of hash functions.

#### 4. Which collision resolution technique can handle more values than table slots? 
Open Hashing (Chaining) can handle more values than table slots, as each slot can hold multiple values using a linked list or other data structure. 
Capacity Handling of Collision Resolution Techniques
Chaining can handle more elements than table slots by expanding linked lists.

Open Addressing techniques are limited by the table size.


### 5. Worst-Case Performance Analysis
Chaining:  if all keys land in the same bucket.

Linear Probing:  in case of severe clustering.

Quadratic Probing & Double Hashing:  in worst case, but often closer to  in practice.

#### 6. How does the choice of table size affect the distribution of keys? 
A good table size (typically a prime number) ensures that keys are spread more evenly across the table, reducing collisions. A poor table size leads to clustering and poor distribution.

#### 7. Pitfalls of using a poor table size (e.g., round number or power of 2)?
Round Numbers: These often lead to bad key distributions as hash functions tend to align poorly with these numbers.
Powers of 2: Can cause patterns in the hash function, leading to clustering and inefficient storage.

## Part B: Simulation and Diagram Exercises

Exercise 1: Open Hashing (Separate Chaining)

Given Keys: {5, 22, 17, 18, 35, 101, 16, 0, 8}

Index

Bucket Contents


Collisions occur in buckets 5 and 8, requiring chaining.







Exercise 2: Closed Hashing (Linear Probing)

Given Keys: {5, 22, 17, 18, 35, 101, 16, 0, 8}

Index

Stored Key


Clustering is visible, particularly around index 5.







Exercise 3: Impact of Poor Table Sizes
Given Keys: {5, 10, 15, 20, 25, 30, 35, 40}

Table Size = 10

All keys map to the same bucket (0) in chaining or create long probes in open addressing.

Table Size = 11 (Prime Number)

Hashes distribute more evenly, reducing collisions.


Extra Credit: Experiment with Quadratic Probing

Using keys: {12, 23, 34, 45, 56, 67, 78, 89}

Quadratic probing reduces clustering but may fail if load factor is high.

Some slots may remain unused.


## Part C: Reflection & Short-Answer Questions

### Real-World Impact
Poor hash table sizing increases collisions, degrading performance in applications like databases and caching.


### High-Load Collision Handling
Chaining: Efficient for growing datasets.

Open Addressing: More cache-friendly but struggles at high load factors.


### High-Frequency Trading Consideration
Double hashing minimizes clustering and is ideal for high-speed operations.


### Hybrid Hash Table Design
Combining chaining and open addressing, e.g., using a small open addressing scheme before falling back on chaining, balances speed and storage efficiency.
