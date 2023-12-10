---
id: 55f1blkl0vhldexzjhsmvj6
title: basics
desc: ''
updated: 1702195838829
created: 1702189885423
---
## Reference Links

### Websites

1. [Makefile Tutorial](https://makefiletutorial.com/)
2. [Make Manual](https://www.gnu.org/software/make/manual/make.html)

## Makefile Syntax

```make
targets: prerequisites
    command
    command
    command
```

- The targets are file names, separated by spaces. Typically, there is only one per rule.
- The commands are a series of steps typically used to make the target(s). These need to start with a tab character, not spaces.
- The prerequisites are also file names, separated by spaces. These files need to exist before the commands for the target are run. These are also called dependencies

## Basic Makefile

```make
hello:
    echo "Hello, World"

```

### Make Clean

clean is often used as a target that removes the output of other targets, but it is not a special word in Make. You can run make and make clean on this to create and delete some_file.

> Note that clean is doing two new things here:
>
> - It's a target that is not first (the default), and not a prerequisite. That means it'll never run unless you explicitly call `make clean`
> - It's not intended to be a filename. If you happen to have a file named clean, this target won't run, which is not what we want. See `.PHONY` later in this tutorial on how to fix this

```make
some_file: 
    touch some_file

clean:
    rm -f some_file
```

### Variables

Variables can only be strings. You'll typically want to use :=, but = also works.

```make
files := file1 file2
some_file: $(files)
 echo "Look at this variable: " $(files)
 touch some_file

file1:
 touch file1
file2:
 touch file2

clean:
 rm -f file1 file2 some_file
```

Reference variables using either ${} or $()

```make
x := dude

all:
    echo $(x)
    echo ${x}

    # Bad practice, but works
    echo $x 
```

### Quotes

Single or double quotes have no meaning to Make. They are simply characters that are assigned to the variable. Quotes are useful to shell/bash, though, and you need them in commands like printf. In this example, the two commands behave the same:

```make
a := one two # a is set to the string "one two"
b := 'one two' # Not recommended. b is set to the string "'one two'"
all:
 printf '$a'
 printf $b
```

### Make All

Making multiple targets and you want all of them to run? Make an all target. Since this is the first rule listed, it will run by default if make is called without specifying a target.

```make
all: one two three

one:
    touch one
two:
    touch two
three:
    touch three

clean:
    rm -f one two three
```

### Multiple Targets

When there are multiple targets for a rule, the commands will be run for each target. `$@` is an automatic variable that contains the target name

```make
all: f1.o f2.o

f1.o f2.o:
    echo $@
# Equivalent to:
# f1.o:
#   echo f1.o
# f2.o:
#   echo f2.o
```
