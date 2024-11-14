# passgen
A simple utility to generate password.

# Features
- **Only 4 flags**. You can use them to select which characters to include in the password or select number of characters.
- **Default generation**. You can use utility without flags and it will generate a default password of 8-12 characters. 

# Usage
`passgen [OPTIONS] <pass-length>`

<pass-length> is a number specifying the length. It can be left unspecified, then a random length between 8 and 12 will be selected.

`[OPTIONS]`:
- `-n`: include numbers in password
- `-u`: include upper case Latin letters in password
- `-l`: include lower case Latin letters in password
- `-s`: include specials in password

# Examples
Generate a password simply:
```
$ passgen
&PcW#L84d%
```

Generate 15 character password:
```
$ passgen 15
BYT3$PNyp3m3x,0
```

Generate password only with numbers and specials:
```
$ passgen -ns
9158037.6%)@
```
