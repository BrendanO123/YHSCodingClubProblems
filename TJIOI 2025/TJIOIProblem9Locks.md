# Context
This was the ninth problem out of thirteen at the TJIOI high school coding competition that I participated in with the YHS Coding Club. The YHS Coding Club entered two teams of three into the competition. My team placed in the middle of the pack, and the other team placed slightly below us. I sunk a decent bit of time into this problem at the competition, and I got most of the way through a solution that could have worked. However, my algorithm would not have been fast enough to finish within the time constraint, and I got stuck on the last step in the solution. The reason I got stuck was because I overlooked the fact that, for all variables that I could not constrain to a value, I could simply assert to be $0$ because all I needed to find was just one solution to a system of equations that had many. 

# Input:
$n$ $m$\
$a_0,$ $a_1,$ $a_2,$ $\ldots,$ $a_{n-1}$

# Sample Cases:
```math
\begin{array} {l | l | l}
    & \large{\text{Input:}} & \large{\text{Output:}}
    \\\hline
    &&\\
    \text{Case One:} & 6\ 3 & \text{YES}\\
    & 1\ 1\ 1\ 1\ 2\ 2\ & 0\ 0\ 1\ 0\ 1\ 0\\
    \\\hline
    &&\\
    \text{Case Two:} &  6\ 3 & \text{NO}\\
    & 1\ 1\ 1\ 2\ 2\ 2\ &\\
    &&\\
\end{array}
```

# Problem:
For this problem you are given a list of numbers, $a$, that is $n$ elements long, order dependent, and may contain duplicates, such that $n \in \mathbb{N},\ n \leq 2 \cdot 10^5$, and $a \subset \mathbb{N}_0$. This list represents the code of a combination lock that you are trying to open. Your goal is to determine whether it is possible to open the lock by starting with all numbers at $0$ and transforming the string of numbers into the given combination by turning/incrementing the numbers one at a time. However, this problem has an annoying trick. Whenever a number on the lock is incremented, the next $m$ numbers are also increment at the same time, where $m$ is given at the start of the problem. Additionally, it is guaranteed that $0 \leq m<n$ and $m \in \mathbb{N}_0$. For example, in the first sample case, $n=6$ and $m=3$. This means that, the lock starts at $\left[0,\ 0,\ 0,\ 0,\ 0,\ 0\right]$, and when the first digit is incremented by one, the lock becomes $\left[1,\ 1,\ 1,\ 1,\ 0,\ 0\right]$ instead of $\left[1,\ 0,\ 0,\ 0,\ 0,\ 0\right]$. This effect also wraps around the end of the sequence, so incrementing the last digit will also affect the first $m$ digits. As a quick side note, all numbers in the combination lock are within the range $\left[0,\ 998244353 \right)$, so, whenever a number in the lock is at $998244352$ and is incremented, it overflows back down to $0$. We will call the exclusive upper bound of this range $M$, such that $M=998244353$ and $a \subseteq \lbrace{x\ :\ 0 \leq x < M\ \cap\ x \in \mathbb{N}_0 \rbrace}$. As mentioned above, your program must output whether it is possible to open the lock in this way. Additionally, if it is possible to open the lock, your program must also output a list of numbers $t$, where $t_i$ represents how many times to increment the number at position $i$ in order to create the given combination. There is no preferred solution for $t$, so any solution will be marked correct if it actually produces the combination. Finally, the program must finish within two seconds for each test case and must not exceed $256$ megabytes of memory usage per test case. This means that the program will likely be required to run in O($n$) time complexity and O($n$) auxiliary space to prevent the program from taking too much time or memory.

# Solution:

## Indexing
For this problem, all indexes $i$ are assumed to be whole numbers that exist in the range including $0$ and up to but excluding $n$ unless otherwise specified, $i \in [0, n)$ and $i \in \mathbb{N}_0$. Therefore, any negative indexes or indexes greater than $n$ are assumed to be transformed by: $\displaystyle{i=(i+n) \bmod n}$, where $i$ becomes the remainder of $i+n$ when divided by $n$.

## Initial Equations
What we want to do is to set up an equation for the number of times that the dial in the combination lock at index $i$ should be incremented/turned, which we will call $t_i$, based off of $a$, $n$, $m$, and constants as necessary. Therefore, the first equation we will create is as follows: $a_i \equiv t_i + \ldots + t_{i-m} \pmod{M}$. This equation says that the value of the dial at index $i$ in the final combination, $a_i$, is equal to the sum of the number of times each dial in the indexes from $i-m$ to $i$ (inclusively) is incremented/turned plus or minus some multiple of $M$ because of the overflow property of the lock. This equation is easy to come up with from the stated problem because each time a dial is incremented it affects all of the next $m$ dials. 

The next important idea is to compare the equations for $a_i$ to the equation for $a_{i-1}$. What you might notice is that both equations have mostly the same variables. Therefore, when we subtract the equation for $a_{i-1}$ from the equation for $a_i$, most of the variables will cancel out, and we will be left with only two variables in the equation: $a_i-a_{i-1} \equiv t_{i}-t_{i-m-1} \pmod{M}$. This is a very important step as it reduces the number of variables we have to work with from $n(m+1)$ to $2n$, a speed-up by a factor of $n$ in the time complexity of the algorithm. 

## Free Variable Problem
It is also important to note that the left side of the equation now only stores the difference between $a_i$ and $a_{i-1}$, when before the values for both were explicitly stored in two separate equations. This means we lost information about the full system of equations when subtracting the two equations because there are now many values for $a_i$ and $a_{i-1}$ that satisfy the system. For now, we should just remember that we have one to many free variables (loosely-constrained variables that we cannot get to drop out of the equations) because all of these equations can't solve for $a$ until a value for $a_i$ is given for some index $i$. We will address this extra free variable later on once we have worked out more of the problem.

## Recursive Formula
We can now take our previous equation and transform it to use it as a recursive formula for $t$. First we can turn the equation into $a_{i+m+1}-a_{i+m} \equiv t_{i+m+1}-t_{i} \pmod{M}$ by offsetting the value of $i$. Then we can rearrange this equation to solve for $t_{i+m+1}$ from $t_{i}$: $\ t_{i+m+1} \equiv  a_{i+m+1}-a_{i+m} + t_{i} \pmod{M}$. This is very useful as it gives us a way to solve for select values of $t_i$ by using this equation as a recursive formula. However, we still need to decide on the initial conditions for this recursive formula. 

## Explicit Formula
We will let the number of initial conditions needed to solve for all values of $t$ to be the number $g$. We will solve for this later. We can now show that $t$ can be solved by looping through each of the indexes from $0$ to $g-1$ (inclusively) and setting $t_i$ to zero, which means we are assuming the initial conditions are all zero until we need to set them to something else. Then, within the loop, we will walk through the entire rest of the cycle containing the starting index $i$ and set $t_{i+m+1}$ using the recursive formula: $\ t_{i+m+1} = \displaystyle{(a_{i+m+1}-a_{i+m} + t_{i} +M)\ \bmod{M}}$. To speed this up, we will also keep track of the cumulative sum of the offset $a_{i+m+1}-a_{i+m}$ from $t_i$ to $t_k$ in a new variable $CS$, such that $CS_k$, for all indexes $k$, is equal to the cumulative sum of $a_{k_2+m+1}-a_{k_2+m}$ for all indexes $k_2$ on the same cycle between the starting index $i$ and the ending index $k$. This allows us to write the equation $t_i = CS_i + \text{( the initial condition for the recursive formula) } t_{(FV_i)}$. With this declaration aside, we can get back to solving for the initial conditions and finish our explicit formula later. 

## Free Variable Solution

### Creating $FV$
The next step is to determine the initial conditions for the recursive formulas. For this, we will define a new list $FV$ where $FV_j=i$ where $i$ is the least positive index where $\exists k \in \mathbb{Z},\ i+k(m+1) \equiv j \pmod{n}$. In other words, we will start at some index $i$ and traverse the list to each index $k$ until we cycle back around to $i$. At each of these indexes, we will set $FV_k=i$. We will then repeat this for each subsequent index $i+1$ until all indexes in the list have been initialized. 

We now have the list $FV$ which defines the index in $t$ such that $t_{(FV_i)}$ will hold the initial condition for the recursive formula for $t_i$. The question now becomes to solve for $FV$ and the count of unique initial conditions in $FV$, which we will call $g$. From the definition of $FV$, we can show that $FV_i = FV_{i+m+1}$. This allows us to show that $FV$ has translational symmetry because the formula for $FV$ holds for any value of $i$. This means that if $\exists i \in \mathbb{N},\ 0 \leq i < n,\ FV_i = FV_{i+1}$ ($FV_i$ is equal to $FV_{i+1}$ for some index $i$), then $FV$ must be the same value at all indexes because of the translational symmetry. Additionally, because $FV$ is the same for all values, there is only one unique index in $FV$, so $g=1$. 

This allows us to create a list of possible configurations for $FV$ and the corresponding values of $g$. If $\exists i \in \mathbb{N},\ FV_i=FV_{i+1}$, then $FV = [0,\ 0,\ \ldots,\ 0]$ and $g=1$. If not, and $\exists i \in \mathbb{N},\ FV_i=FV_{i+2}$, then $FV = [0,\ 1,\ 0,\ 1,\ \ldots,\ 1]$ and $g=2$ because every other index in $FV$ contains the same value, but the adjacent indexes do not. Else if $\exists i \in \mathbb{N},\ FV_i=FV_{i+3}$, then $FV = [0,\ 1,\ 2,\ 0,\ 1,\ 2,\ \ldots,\ 2]$ and $g=3$, and the same logic applies all the way up to $\exists i \in \mathbb{N},\ FV_i=FV_{i+m+1}$. This means that either:
```math
\begin{array}{llllll}
    FV&=&\begin{bmatrix}0,&0,&\ldots,&0\end{bmatrix}&\text{and}&g=1,&\text{or}\\
    FV&=&\begin{bmatrix}0,&1,&0,&1,&\ldots,&1\end{bmatrix}&\text{and}&g=2,&\text{or}\\
    &\ \vdots&&&&\text{or}\\
    FV&=&\begin{bmatrix}0,&\ldots,&\hat{g},&0,&\ldots,&\hat{g},&\ldots,&\hat{g}\end{bmatrix}&\text{and}&g=\hat{g},&\text{or}\\
    &\ \vdots&&&&\text{or}\\
    FV&=&\begin{bmatrix}0,&\ldots,&m,&0,&\ldots,&m,&\ldots,&m\end{bmatrix}&\text{and}&g=m+1
    \end{array}
```

We know that exactly one of these must be true for two reasons. First, the fact that these claims are constructed with else if statements makes them exclusive (if A, else if B, else if C all the way down). Second, either $\exists i \in \mathbb{N},\ FV_i=FV_{i+k}$ for some $k$ less than $m+1$ and one of the early statements are true, or it does not and the last statement is true because none of the previous are true and $FV_i$ will always equal $FV_{i+m+1}$. This shows us that $1 \leq g \leq m$. It also shows that $\frac{m+1}{g} \in \mathbb{N}$ because $m+1$ must be a multiple of $g$ so that the formulas of $FV_i = FV_{i+m+1}$, and $FV_i=FV_{i+g}$ line up. Finally, this situation shows that $\frac{n}{g} \in \mathbb{N}$ because $n$ must be a multiple of $g$ otherwise we the cycle would not cleanly loop around the end of the list, and we would be able to disprove the assumed value of $g$.

### Finding $g$
We now know that $FV = \left[0,\ 1,\ 2,\ \ldots,\ g,\ 0,\ \ldots,\ g\right]$ and $\frac{m+1}{g},\ \frac{n}{g} \in \mathbb{N}$. We will now also set up two more equations:
```math
\begin{array}{llll} g \cdot j&=&n,&j \in \mathbb{N} \\
j\cdot (m+1)&=&l \cdot n&j \in \mathbb{N},\ l \in \mathbb{N} \end{array}
```
This says that the number of disjoint cycles when moving around the list by jumps of $m+1$, which is $g$ because this is the same method we used to initialize $FV$, times the number of indexes/jumps in each disjoint cycle, $j$, is equal to the length of the list, $n$. This is because each index in the list needs to be in exactly one disjoint cycle by definition. Additionally, the number of jumps in each cycle, $j$, times the length of each jump, $m+1$, must equal some multiple, $l$, of the length of the list, $n$. This is because, in order to cycle around back to the same index in the list, the jumps must line back up with the same index within the list; in other words, the same remainder when divided by the length of the list, $n$. This means that the distance from the starting location, the left side of the equation, must be a multiple of $n$.

These equations allow us to show that $g$ is maximal and, therefore, finally conclude that $g = \gcd(m+1, n)$. We can set an upper bound for $j+l$ of $n+m+1$ by the second equation because it will always hold for $j=n$ and $l=m+1$. However, we can also show that $j \leq n$ by the first equation because that equations shows that $j=\frac{n}{g}$. We can now show that $j$ is minimal because the cycle is complete at the lowest number of jumps that reach the same point. This means that $\frac{n}{g} \leq n$ and $\frac{n}{g}$ is minimal. Additionally, $\frac{m+1}{g} \in \mathbb{N}$, and $\frac{n}{g} \in \mathbb{N}$. This allows us to see that $g$ is the largest value that divides both $n$ and $m+1$, so $g = \gcd(m+1, n)$.

### Solving for $F$
The final step in solving for the initial conditions is to solve for one free variable F. The number of variables that we can change and still satisfy our current system of equations is $g$ because each free variable will only affect its cycle and the recursive formula will keep the rest of the cycle valid. However, in the <i>Initial Equations</i> section, when subtracting the equations for $a_i$ and $a_{i-1}$, we created one more free variable because our equations could no longer solve for $a$ unless one of the values was fixed (because they only contain the offset between values of $a$ not the initial conditions). This means that we actually have one too many free variables in our equations. For all of the true free variables, we can simply set them to zero to get a solution and have easy to work with numbers. However, for one of them, we will need to solve for the actual value of the free variable, which we will call $F$. 

To do this, we will add back in one of the initial equations in the form of $a_i \equiv t_i + \ldots + t_{i-m} \pmod{M}$. I am going to choose to use the equation for $a_m$ because it has the nice property of keeping all of its variables in the indexes from $0$ to $m$ (inclusively), and it does not wrap around the list or skip any of the lowest values of $t$:
```math
\begin{array}{ll}
a_m \equiv \displaystyle{\sum_{i=0}^{m}(t_i) \pmod{M}}&\Rightarrow \\
t_m = (a_m - \displaystyle{\sum_{i=0}^{m-1}(t_i) + M)\ \bmod{M}}\end{array}
```

Additionally, we know from our explicit formula that:
```math
\begin{array}{ll}
\displaystyle{t_m = (CS_m + t_{(FV_m)} + M)\ \bmod{M}} \\
\displaystyle{\therefore\ \ a_m - \sum_{i=0}^{m-1}(t_i)} = CS_m + t_{(FV_m)}
\end{array}
```

We will declare that the initial condition/free variable we want to solve for is the one at $m$, so we can replace $t_{(FV_m)}$ with $F$. Then we will clean up some variables:
```math
\begin{array}{ll}
a_m - \displaystyle{\sum_{i=0}^{m-1}(t_i)} = CS_m + F&\Rightarrow \\
a_m - \displaystyle{\sum_{i=0}^{m-1}(CS_i + t_{(FV_i)})} = CS_m + F &\Rightarrow \\
F = a_m - \displaystyle{\sum_{i=0}^{m-1}(CS_i)\ -\sum_{i=0}^{m-1} (t_{(FV_i)})} - CS_m&\Rightarrow \\
F = a_m - \displaystyle{\sum_{i=0}^{m}(CS_i)\ -\sum_{i=0}^{m-1} (t_{(FV_i)})}
\end{array}
```

We have already declared that each free variable, $t_{(FV_i)}$, is either zero or $F$, so this becomes $F$ multiplied by the number of times that the free variable at $i$ is equal to the free variable at $m$ over a distance of $m$ cells. We will call this count $C_0$. Therefore:\
$F(C_0+1) = a_m - \displaystyle{\sum_{i=0}^{m}(CS_i)}\ \Rightarrow\ F = \frac{\left(a_m - \displaystyle{\sum_{i=0}^{m}(CS_i)}\right)}{C_0+1}$.\
We know that if we extend the range for $C_0$ to include $m$, the count of times the free variable will increase by one because the free variable we added will be $F$ by definition. Therefore, we will replace $C_0+1$ with the count over this new range, which we will call $C$. The question now becomes how many times does the free variable complete a full cycle over a distance of $m+1$. This is the same as the floor of $m+1$ divided by the length of one cycle, which is $g$ from the above work. This means that $C= \lfloor(\frac{m+1}{g})\rfloor$. However, by definition, $g$ divides $m+1$, so we can ignore the floor operation and simple replace $C_0+1$ with $\frac{m+1}{g}$:\
$\displaystyle{\therefore\ \ F} = \left(\frac{g}{m+1}\right)\left(\displaystyle{a_m - \sum_{i=0}^{m}(CS_i)}\right)$.

## Cleaning Up
We now have a formula for the number of initial conditions that we need to set, $g = \gcd(m+1,n )$, we know that they will be over the range from index $0$ to index $g-1$ (inclusively), and we know that all but one of them will be zero. We also know that the last initial condition, $t_{(FV_m)}$, is equal to:\
$\left(\frac{g}{m+1}\right)\left(\displaystyle{a_m - \sum_{i=0}^{m}(CS_i)}\right)$.\
Finally, we know that $t_i = \displaystyle{(CS_i + t_{(FV_i)} + M)\ (\bmod{\ M})}$. This allows us to create a program to solve for $t$. We will first input $n$, $m$, and $a$ and define the lists $FV$, $CS$, and $t$ to be of length $n$. We will also calculate $g$ to be $\gcd(m+1,n )$. Then we will loop through all of the indexes $i$ from $0$ to $g-1$ (inclusively) and set $CS_i=0$ and $FV_i=i$. Then, we will jump through the list of $CS$ with jumps of length $m+1$ and set $CS_{j+m+1} = (a_{i+m+1}-a_{i+m} + CS_{i} + M)\ (\bmod{\ M})$ and $FV_j = i$ for each index $j$. When done with each cycle, we will test if it cleanly wraps back around to the start. If it does not and has a cumulative sum unequal to a multiple of $M$, then we will abort the algorithm and return that the solution does not exist. We will then set $t_i=0$ for all indexes $i$ between $0$ and $g-1$ inclusively. Note that our earlier exploration of $FV$ shows that this will set the free variable for every cycle exactly once, avoiding over-defining the system. Then we will set:\
$t_{(FV_m)} = \displaystyle{\left((\frac{g}{m+1})\Bigl(\displaystyle{a_m - \sum_{i=0}^{m}\left(CS_i \right)}\Bigr)+M \right) \ \bmod{M}}$.\
Finally, we will loop through $t$ from $g$ to $n-1$ inclusively and set $t_i = CS_i + t_{(FV_i)}$. One possible speed up is to notice that $\displaystyle{FV_i = i\ \bmod{g}}$ and skip the $FV$ list entirely. Other than that our algorithm is complete, and we can output our solution stored in $t$. To see an implementation of this algorithm check out <i>LocksV2.cpp</i> in this directory.