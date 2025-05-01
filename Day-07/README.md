# Loops and Pattern Printing in Linux Shell Scripts

## 🔂 for Loop, while loop in Bash

### 🔸 Basic Syntax
```bash
for (( i=1; i<=5; i++ ))
do
  echo "Number: $i"
done

i=1
while [ $i -le 5 ]
do
  echo "Count: $i"
  ((i++))
done

```

**Use `((i++))` or `i=$((i + 1))` to increment.**

### 🧠 Tips for Pattern Printing in Bash
* No built-in graphics; only character-based patterns.

* Use nested loops for shapes like triangles, pyramids, diamonds.

* `echo -n` and `printf` are your best friends.

* Spacing is crucial for alignment in pyramid shapes.

* You can mix arithmetic and loops creatively!

🎉 Happy Scripting & Keep Exploring!
