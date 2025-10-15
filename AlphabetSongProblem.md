Gabe is practicing for a contest where he must recite the alphabet backwards as fast as possible from a given starting letter. Because he is bad with the alphabet, every time he moves backwards one letter, he must recite the entire alphabet song up to the next letter he says. For example, if Gabe wants to recite backwards from `e`, he will first say `e`, then `a, b, c, d`, then `a, b, c`, then `a, b`, and finally `a`. This will result in a final string ***S*** of: `e, a, b, c, d, a, b, c, a, b, a`.

He wants you to watch him practice and tell him how helpful it would be to memorize a specific section instead of figuring out that section by singing the song. In order to do this, you must find how many times a certain substring of the final string ***S*** appears in the total string. For example, he could ask you how many times he says `a, b, c` in the above example, and you would reply: twice, once when singing the song up to `d`, and another time when singing up to `c`.

*Given a starting lowercase Latin letter in stdin and a string of lowercase letters without delimiters, output the number of times the string of letters appears in the total string **S** generated from the above procedure. It is guaranteed that the string of letters will appear at least once in the total string **S**.*

**Hint:** you do not need to construct the total string ***S*** in order to solve the problem, it is possible to solve in linear time with respect to the length of the string of letters and constant auxiliary space (even if the alphabet had any number of letters).

**Sample Inputs:**

`e abc`\
`z a`\
`z ba`\
`z abcdefghijklmnop`

**Sample Outputs:**

`2`\
`25`\
`1`\
`10`

For a bit harder of a challenge (without extra points because this is still really easy), instead of using letters, take in a starting 32-bit number, the length of the list of numbers, and on the next line, a list of space separated 32-bit numbers. The same rules apply for generating the sequence: every time that the number decreases, the sequence must count up from one to the new number. The list of numbers is guaranteed to appear at least once. Only constant auxiliary space is needed, and the time complexity is the same as the time complexity of reading in the inputs (linear with respect to the length of the list of numbers). For example, an input of: 
```
999000 3 
1 2 3
```
Would result in a response of `998997`.