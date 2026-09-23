# push_swap

An algorithmic sorting project written in **C** for the 42 curriculum.

The challenge is unusual: sort a set of integers using only two stacks and a very small set of allowed operations, while keeping the number of generated instructions as low as possible.

## Allowed operations

`sa` · `sb` · `ss`  
`pa` · `pb`  
`ra` · `rb` · `rr`  
`rra` · `rrb` · `rrr`

## Approach

My implementation uses a chunk/pivot strategy to progressively move values from stack A to stack B.

Values inside each chunk are distributed in a way that reduces the work required later. When rebuilding stack A, the program calculates rotation costs for candidate values and selects the cheapest move, combining rotations with `rr` or `rrr` when possible.

I originally referred to this approach as my **“papillon”** strategy while developing it independently. I later encountered similar ideas described elsewhere as a *butterfly* approach; the name here refers to my own project history rather than a claim of originating the algorithm.

## Build

```bash
make
```

Example:

```bash
./push_swap 5 2 8 1 3
```

The program prints the operations needed to sort the input.

Build the bonus checker with:

```bash
make bonus
```

Then verify a sequence:

```bash
ARG="5 2 8 1 3"
./push_swap $ARG | ./checker $ARG
```

## Input validation

The program rejects invalid integer input, duplicates and values outside the `int` range.

## What this project demonstrates

push_swap is mainly about algorithm design under artificial constraints. The interesting part is not simply producing a sorted result, but deciding how to represent the problem, estimate move costs and trade implementation complexity against operation count.

---

Part of my developer portfolio: **[github.com/Overflow-ADW](https://github.com/Overflow-ADW)**  
Professional work: **[Avenue du Web](https://avenueduweb.be)**
