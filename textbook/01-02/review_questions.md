# Review Questions

1. Strings are a sequence of characters used to represent text in a program. Many operations can be applied to strings, such as length, concatenation, comparison, reversal, uppercasing, etc.
2. In memory, strings are stored as an array of ASCII bytes ending with a null byte
3. Strings can be read from stdin using the `fgets` function with the arguments: `fgets(buffer, buffer_size, stdin)`. You can also use `scanf` with the `%s` format specifier, but this will stop at the first space character. You could also repeatedly call `getch`.
4. Strings can be displayed to the screen using the `printf` function with the `%s` format specifier. You can also repeatedly call `putch`.
5. The syntax of `printf` and `scanf` is: `printf(format_string, arg1, arg2, ...)` and `scanf(format_string, arg1, arg2, ...)`. The first argument, the format string, will contain placeholders starting with a `%` character that will be replaced with the arguments, according to the placeholder type. For example, `%d` is a placeholder for an integer and `%s` is a placeholder for a string.
    - To left pad a string, you can use the `%Ns` format specifier, where `N` is the number of characters to pad to. To right pad it, add a `-` before the `N`.
    - To only output a certain number of characters, you can use the `%.Ns` format specifier, where `N` is the number of characters to output.
    - These can be combined, e.g. `%4.2s` will output a string left padded to 4 characters and right truncated to 2 characters.

---

13. The difference between `fgets` and `scanf` is that `fgets` will read a full line of text from stdin (including newlines), while `scanf` will only read a single word from stdin.

---

18. The difference between a character array and a string is that a string **must** end with a null byte (`\0`).
