# push_swap

An algorithmic sorting project written in **C** for the 42 curriculum.

The challenge is unusual: sort a set of integers using only two stacks and a very small set of allowed operations, while keeping the number of generated instructions as low as possible.

## Allowed operations

`sa` · `sb` · `ss`  
`pa` · `pb`  
`ra` · `rb` · `rr`  
`rra` · `rrb` · `rrr`

## Approach

I initially experimented with a **Turk-style approach**, but eventually moved away from it because I was not satisfied with the operation counts I was getting.

The turning point was changing how I represented the problem.

`push_swap` is still an algorithmic sorting problem, but its main constraint is unusual: values cannot simply be compared and exchanged at arbitrary positions. They have to be **physically moved through two stacks** using a very small vocabulary of operations.

Instead of thinking about the input as an array that needed to be sorted, I started thinking about it as a set of values that had to be **positioned, moved and reorganized** between A and B. Every useful value has a physical cost to reach, every transfer changes the geometry of both stacks, and some movements can be shared through `rr` and `rrr`.

That changed the question from:

> Which value should come next?

to something closer to:

> How can I arrange the values now so that the remaining movements become cheaper later?

That led to the chunk/pivot strategy used in this implementation.

The strategy adapts to the input size:

- fewer than 100 values: one chunk;
- 100–299 values: three chunks;
- 300–599 values: six chunks;
- 600 values and above: one chunk per 100 values.

For multi-chunk inputs, values are progressively distributed from A to B around calculated pivots. Lower values inside the current range can be rotated in B while the remaining values continue to be pushed, creating the characteristic two-sided distribution visible in the visualizer.

When rebuilding stack A, the program calculates rotation costs for candidate values and selects the cheapest move, combining rotations with `rr` or `rrr` when possible.

I originally referred to this approach as my **“papillon”** strategy while developing it independently. I later encountered similar ideas described elsewhere as a *butterfly* approach; the name here refers to my own project history rather than a claim of originating the algorithm.

## Visualizer

The repository includes a small standalone visualizer in [`visualizer/`](visualizer/) that I added after the original 42 project to make the algorithm easier to inspect and present.

It runs the real local `./push_swap` executable, captures the generated instructions and replays them in a browser. The visualizer does **not** implement a separate sorting algorithm: every displayed state comes from the operations produced by this project.

For larger inputs, values are colored by rank/chunk so the distribution phase becomes visible. This makes the “papillon” structure in stack B much easier to read before the second phase rebuilds stack A using the cheapest available rotations.

### Distribution phase

This 500-value run is shown during the A → B distribution phase. At this point, 389 values have already moved to B and the chunk-based butterfly structure is clearly visible.

<p align="center">
  <img src="visualizer/Capture%20d%27%C3%A9cran%202026-09-25%20013533.png" alt="push_swap visualizer showing the chunk-based butterfly distribution in stack B" width="95%">
</p>

### Sorted result

The same run after all **4,237 operations** generated for this particular input: stack B is empty and the 500 values have been rebuilt in ascending order in stack A.

<p align="center">
  <img src="visualizer/Capture%20d%27%C3%A9cran%202026-09-25%20013444.png" alt="push_swap visualizer showing the final sorted 500-value stack" width="95%">
</p>

### Visualizer features

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
python3 visualizer/push_swap_visualizer.py
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

`push_swap` is an algorithm design problem under artificial movement constraints. The difficult part is not merely discovering the final sorted order: it is planning a sequence of legal moves that transforms one physical stack configuration into another while keeping the instruction count low.

For me, the most important lesson was therefore not a particular sorting algorithm. It was learning to **change the representation of the problem** when the first approach was not good enough: moving away from a Turk-style strategy, recognizing the importance of the physical movement model, and designing a solution around the actual constraints of the system.

---

Part of my developer portfolio: **[github.com/Overflow-ADW](https://github.com/Overflow-ADW)**  
Professional work: **[Avenue du Web](https://avenueduweb.be)**
