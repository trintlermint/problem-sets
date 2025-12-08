# Robot Javelin | [Jane Street Puzzles](https://www.janestreet.com/puzzles/) 

This repository contains my solution code that analyzes a two-throw head‑to‑head “Robot Javelin” game with a protocol leak:

Two robots each draw a first throw uniformly on \[0,1]. Then, each can keep that distance or erase and take a mandatory second throw (also uniform on \[0,1]). The higher final distance wins. Well, so, in the original (leak‑free) game both players use the "Nash cutoff" like the smartasses they are,
- c =  (sqrt(5)−1)/2 =~ 0.6180339887: keep the first throw if it is ≥ c, otherwise redraw.
- The leak: Spears Robot learns one bit about Java‑lin’s first throw: whether it is above or below a threshold \(d\) of Spears’ choosing. Spears chooses \(d\) to maximize its own win chance, assuming Java‑lin plays Nash. Java‑lin, knowing the leak exists, can best‑respond.

`robot-javelin.cpp` numerically confirms the resulting equilibrium behavior under this one‑bit leak.

## [Problem Statement](https://www.janestreet.com/puzzles/current-puzzle/)

It’s coming to the end of the year, which can only mean one thing: time for this year’s Robot Javelin finals! Whoa wait, you’ve never heard of Robot Javelin? Well then! Allow me to explain the rules:

    - It’s head-to-head. Each of two robots makes their first throw, whose distance is a real number drawn uniformly from [0, 1].
    - Then, without knowledge of their competitor’s result, each robot decides whether to keep their current distance or erase it and go for a second throw, whose distance they must keep (it is also drawn uniformly from [0, 1]).
    - The robot with the larger final distance wins.

This year’s finals pits your robot, Java-lin, against the challenger, Spears Robot. Now, robots have been competing honorably for years and have settled into the Nash equilibrium for this game. However, you have just learned that Spears Robot has found and exploited a leak in the protocol of the game. They can receive a single bit of information telling them whether their opponent’s first throw (distance) was above or below some threshold d of their choosing before deciding whether to go for a second throw. Spears has presumably chosen d to maximize their chance of winning — no wonder they made it to the finals!

Spears Robot isn’t aware that you’ve learned this fact; they are assuming Java-lin is using the Nash equilibrium. If you were to adjust Java-lin’s strategy to maximize its odds of winning given this, what would be Java-lin’s updated probability of winning? Please give the answer in exact terms, or as a decimal rounded to 10 places.

## What the program computes

1. Confirms the Nash cutoff \(c\).
2. Searches for the Spears threshold \(d\) that maximizes Spears’ win rate against arbitrary Nash‑playing Java‑lin, and computes Spears’ induced keep/redraw cutoffs \(t_H\) (when the bit says Java‑lin’s first throw > d) and \(t_L\) (otherwise).
3. Computes Java‑lin’s best response to that fixed Spears policy and reports Java‑lin’s resulting win probability.

## Key results (representative run)

- Nash cutoff: `c = 0.6180339887`
- Spears optimal threshold (v/s Nash): `d =~ 0.618`–`0.63` (objective is very flat in this region)
- Spears induced cutoffs: `t_H =~ 0.691`, `t_L =~ 0.50`
- Spears win vs Nash: about `0.507`–`0.508` (Java‑lin win about `0.493`–`0.4935`)
- Java‑lin best response vs Spear: win probability about **0.4935**–**0.494**

Win surface is flat near the optimum => small search‑grid changes moves \(d\) slightly, keep probabilities essentially unchanged.

## Building and running

```bash
g++ -O2 -std=c++17 -o robot-javelin robot-javelin.cpp
./robot-javelin
```

My program prints the cutoffs and win probability with 10 decimal places as requested by Jane Street.

## Workflow

- Models “keep if first throw ≥ threshold, else redraw” as a CDF \(G_t(y)\) and then uses closed integrals for expected win probabilities against uniform draws. From that it computes Spears’ best responses to the Nash cutoff for \(t_H, t_L\) given some chosen \(d\). Then it searches over \(d \in [c, 1]\) (fine grid) to maximize Spears’ win vs Nash.
- Computes Java‑lin’s best single‑cutoff response to the fixed Spears policy.

## Interpreting the output

If your run reports values in the bands above (e.g., Java‑lin win ≈ 0.4935–0.494), it matches the expected analysis. Minor differences at the 4th–5th decimal place are due to the flat optimum and grid resolution. To tighten, increase the grid density or use a 1‑D optimizer for \(d\).
