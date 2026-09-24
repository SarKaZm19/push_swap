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

The strategy adapts to the input size:

- fewer than 100 values: one chunk;
- 100–299 values: three chunks;
- 300–599 values: six chunks;
- 600 values and above: one chunk per 100 values.

For multi-chunk inputs, values are progressively distributed from A to B around calculated pivots. Lower values inside the current range can be rotated in B while the remaining values continue to be pushed, which creates the characteristic two-sided distribution visible in the visualizer.

When rebuilding stack A, the program calculates rotation costs for candidate values and selects the cheapest move, combining rotations with `rr` or `rrr` when possible.

I originally referred to this approach as my **“papillon”** strategy while developing it independently. I later encountered similar ideas described elsewhere as a *butterfly* approach; the name here refers to my own project history rather than a claim of originating the algorithm.

## Visualizer

The repository also includes a small standalone visualizer built after the original 42 project to make the algorithm easier to inspect and present.

It runs the real local `./push_swap` executable, captures the generated instructions and replays them in a browser. The visualizer does not implement a separate sorting algorithm: every displayed state comes from the operations produced by this project.

For larger inputs, values are colored by rank/chunk so the distribution phase becomes visible. This makes it possible to see the chunk-based “papillon” structure forming in stack B before the second phase rebuilds stack A using the cheapest available rotations.

The visualizer includes:

- stack A / stack B replay;
- play, pause and operation-by-operation navigation;
- a complete timeline;
- deterministic random permutations using a seed;
- inputs from 2 up to 1000 values;
- chunk-aware coloring based on the strategy used by the project;
- quick access to the middle of the distribution and the peak size of stack B;
- a capture mode designed for clean screenshots.

Run it from the repository root after building `push_swap`:

```bash
make
python3 push_swap_visualizer.py
```

Then open:

```text
http://localhost:8765
```

> The visualizer is an additional analysis and presentation tool. It was not part of the original 42 subject.

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
