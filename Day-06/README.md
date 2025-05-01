# Shell scripts 

# 🐧 How to Execute a `.sh` File in Linux

## 📁 1. Create a Shell Script

Create a file with `.sh` extension, e.g. `myscript.sh`:

```
echo "Hello, World!"
chmod +x myscript.sh
./myscript.sh

```
##### ❗ Common Errors
Permission denied?
Make sure you ran chmod +x.

Command not found?
Check the path or file name.

## Questions - related commands, syntax

## 🔢 Arithmetic Operations

### ➕ Addition
```bash
a=5
b=3
sum=$((a + b))
echo "Sum: $sum"

diff=$((a - b))
echo "Difference: $diff"

product=$((a * b))
echo "Product: $product"

quotient=$((a / b))
echo "Quotient: $quotient"

remainder=$((a % b))
echo "Remainder: $remainder"

```

## Conditional Statements

### ✅ if - elif - else

```
num=10

if [ $num -gt 0 ]; then
    echo "Positive"
elif [ $num -eq 0 ]; then
    echo "Zero"
else
    echo "Negative"
fi
```

* Use `-gt`, `-lt`, `-eq`, `-ne`, `-ge`, `-le` for comparisons.

### 🔀 case Statement (switch-case equivalent)

```
read -p "Enter a number (1-3): " choice

case $choice in
    1)
        echo "You chose One"
        ;;
    2)
        echo "You chose Two"
        ;;
    3)
        echo "You chose Three"
        ;;
    *)
        echo "Invalid choice"
        ;;
esac

```