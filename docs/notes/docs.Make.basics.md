---
id: 55f1blkl0vhldexzjhsmvj6
title: basics
desc: ''
updated: 1702221184780
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

#### Part 2

##### Flavors and Modification

There are two flavors of variables:

- recursive (use `=`) - only looks for the variables when the command is used, not when it's defined.
- simply expanded (use `:=`) - like normal imperative programming -- only those defined so far get expanded

```make
# Recursive variable. This will print "later" below
one = one ${later_variable}
# Simply expanded variable. This will not print "later" below
two := two ${later_variable}

later_variable = later

all: 
    echo $(one)
    echo $(two)
```

Simply expanded (using `:=`) allows you to append to a variable. Recursive definitions will give an infinite loop error.

```make
one = hello
# one gets defined as a simply expanded variable (:=) and thus can handle appending
one := ${one} there

all: 
    echo $(one)
```

`?=` only sets variables if they have not yet been set

```make
one = hello
one ?= will not be set
two ?= will be set

all: 
    echo $(one)
    echo $(two)
```

Spaces at the end of a line are not stripped, but those at the start are. To make a variable with a single space, use `$(nullstring)`

```make
with_spaces = hello   # with_spaces has many spaces after "hello"
after = $(with_spaces)there

nullstring =
space = $(nullstring) # Make a variable with a single space.

all: 
    echo "$(after)"
    echo start"$(space)"end
```

Use `+=` to append

```make
foo := start
foo += more

all:
    echo $(foo)
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

### * Wildcards

Both `*` and `%` are called wildcards in Make, but they mean entirely different things. `*` searches your filesystem for matching filenames. I suggest that you always wrap it in the wildcard function, because otherwise you may fall into a common pitfall described below.

```make
# Print out file information about every .c file
print: $(wildcard *.c)
    ls -la  $?
```

`*` may be used in the target, prerequisites, or in the wildcard function.
Danger: `*` may not be directly used in a variable definitions
Danger: When `*` matches no files, it is left as it is (unless run in the wildcard function)

```make
thing_wrong := *.o # Don't do this! '*' will not get expanded
thing_right := $(wildcard *.o)

all: one two three four

# Fails, because $(thing_wrong) is the string "*.o"
one: $(thing_wrong)

# Stays as *.o if there are no files that match this pattern :(
two: *.o 

# Works as you would expect! In this case, it does nothing.
three: $(thing_right)

# Same as rule three
four: $(wildcard *.o)
```

### % Wildcard

`%` is really useful, but is somewhat confusing because of the variety of situations it can be used in.

- When used in "matching" mode, it matches one or more characters in a string. This match is called the stem.
- When used in "replacing" mode, it takes the stem that was matched and replaces that in a string.
- `%` is most often used in rule definitions and in some specific functions.

### Automatic Variables

```make
hey: one two
    # Outputs "hey", since this is the target name
    echo $@

    # Outputs all prerequisites newer than the target
    echo $?

    # Outputs all prerequisites
    echo $^

    touch hey

one:
    touch one

two:
    touch two

clean:
    rm -f hey one two
```

### Implicit Rules

Make loves c compilation. And every time it expresses its love, things get confusing. Perhaps the most confusing part of Make is the magic/automatic rules that are made. Make calls these "implicit" rules. I don't personally agree with this design decision, and I don't recommend using them, but they're often used and are thus useful to know. Here's a list of implicit rules:

- Compiling a C program: n.o is made automatically from n.c with a command of the form $(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@
- Compiling a C++ program: n.o is made automatically from n.cc or n.cpp with a command of the form $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
- Linking a single object file: n is made automatically from n.o by running the command $(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

The important variables used by implicit rules are:

- CC: Program for compiling C programs; default cc
- CXX: Program for compiling C++ programs; default g++
- CFLAGS: Extra flags to give to the C compiler
- CXXFLAGS: Extra flags to give to the C++ compiler
- CPPFLAGS: Extra flags to give to the C preprocessor
- LDFLAGS: Extra flags to give to compilers when they are supposed to invoke the linker

Let's see how we can now build a C program without ever explicitly telling Make how to do the compililation:

```make
CC = gcc # Flag for implicit rules
CFLAGS = -g # Flag for implicit rules. Turn on debug info

# Implicit rule #1: blah is built via the C linker implicit rule
# Implicit rule #2: blah.o is built via the C compilation implicit rule, because blah.c exists
blah: blah.o

blah.c:
    echo "int main() { return 0; }" > blah.c

clean:
    rm -f blah*
```

### Static Pattern Rules

Static pattern rules are another way to write less in a Makefile, but I'd say are more useful and a bit less "magic".

```make
targets...: target-pattern: prereq-patterns ...
    commands
```

The essence is that the given target is matched by the target-pattern (via a % wildcard). Whatever was matched is called the stem. The stem is then substituted into the prereq-pattern, to generate the target's prereqs.

A typical use case is to compile .c files into .o files. Here's the manual way:

```make
objects = foo.o bar.o all.o
all: $(objects)

# These files compile via implicit rules
foo.o: foo.c
bar.o: bar.c
all.o: all.c

all.c:
    echo "int main() { return 0; }" > all.c

%.c:
    touch $@

clean:
    rm -f *.c *.o all
```

Here's the more efficient way, using a static pattern rule:

```make
objects = foo.o bar.o all.o
all: $(objects)

# These files compile via implicit rules
# Syntax - targets ...: target-pattern: prereq-patterns ...
# In the case of the first target, foo.o, the target-pattern matches foo.o and sets the "stem" to be "foo".
# It then replaces the '%' in prereq-patterns with that stem
$(objects): %.o: %.c

all.c:
    echo "int main() { return 0; }" > all.c

%.c:
    touch $@

clean:
    rm -f *.c *.o all
```

### Static Pattern Rules and Filter

The filter function can be used in Static pattern rules to match the correct files. In this example, I made up the .raw and .result extensions.

```make
obj_files = foo.result bar.o lose.o
src_files = foo.raw bar.c lose.c

all: $(obj_files)
# Note: PHONY is important here. Without it, implicit rules will try to build the executable "all", since the prereqs are ".o" files.
.PHONY: all 

# Ex 1: .o files depend on .c files. Though we don't actually make the .o file.
$(filter %.o,$(obj_files)): %.o: %.c
    echo "target: $@ prereq: $<"

# Ex 2: .result files depend on .raw files. Though we don't actually make the .result file.
$(filter %.result,$(obj_files)): %.result: %.raw
    echo "target: $@ prereq: $<" 

%.c %.raw:
    touch $@

clean:
    rm -f $(src_files)
```

### Pattern Rules

Pattern rules are often used but quite confusing. You can look at them as two ways:

- A way to define your own implicit rules
- A simpler form of static pattern rules

```make
# Define a pattern rule that compiles every .c file into a .o file
%.o : %.c
    $(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
```

Pattern rules contain a '%' in the target. This '%' matches any nonempty string, and the other characters match themselves. ‘%’ in a prerequisite of a pattern rule stands for the same stem that was matched by the ‘%’ in the target.

```make
# Define a pattern rule that has no pattern in the prerequisites.
# This just creates empty .c files when needed.
%.c:
   touch $@
```

### Double-Colon Rules

Double-Colon Rules are rarely used, but allow multiple rules to be defined for the same target. If these were single colons, a warning would be printed and only the second set of commands would run.

```make
all: blah

blah::
    echo "hello"

blah::
    echo "hello again"
```

### Commands and Execution

Add an `@` before a command to stop it from being printed
You can also run make with `-s` to add an `@` before each line

```make
all: 
    @echo "This make line will not be printed"
    echo "But this will"
```

### Command Execution

Each command is run in a new shell (or at least the effect is as such)

```make
all: 
    cd ..
    # The cd above does not affect this line, because each command is effectively run in a new shell
    echo `pwd`

    # This cd command affects the next because they are on the same line
    cd ..;echo `pwd`

    # Same as above
    cd ..; \
    echo `pwd`
```

### Default Shell

The default shell is /bin/sh. You can change this by changing the variable SHELL:

```make
SHELL=/bin/bash

cool:
    echo "Hello from bash"
```

### Double Dollar Sign

If you want a string to have a dollar sign, you can use `$$`. This is how to use a shell variable in bash or `sh`.

Note the differences between Makefile variables and Shell variables in this next example.

```make
make_var = I am a make variable
all:
    # Same as running "sh_var='I am a shell variable'; echo $sh_var" in the shell
    sh_var='I am a shell variable'; echo $$sh_var

    # Same as running "echo I am a make variable" in the shell
    echo $(make_var)
```

### Error Handling with `-k`, `-i` and `-`

Add `-k` when running make to continue running even in the face of errors. Helpful if you want to see all the errors of Make at once.
Add a `-` before a command to suppress the error
Add `-i` to make to have this happen for every command.

```make
one:
    # This error will be printed but ignored, and make will continue to run
    -false
    touch one
```

### Recursive use of make

To recursively call a makefile, use the special $(MAKE) instead of make because it will pass the make flags for you and won't itself be affected by them.

```make
new_contents = "hello:\n\ttouch inside_file"
all:
    mkdir -p subdir
    printf $(new_contents) | sed -e 's/^ //' > subdir/makefile
    cd subdir && $(MAKE)

clean:
    rm -rf subdir
```

### Export, environments, and recursive make

When Make starts, it automatically creates Make variables out of all the environment variables that are set when it's executed.

```make
# Run this with "export shell_env_var='I am an environment variable'; make"
all:
    # Print out the Shell variable
    echo $$shell_env_var

    # Print out the Make variable
    echo $(shell_env_var)
```

The export directive takes a variable and sets it the environment for all shell commands in all the recipes:

```make
shell_env_var=Shell env var, created inside of Make
export shell_env_var
all:
    echo $(shell_env_var)
    echo $$shell_env_var
```

As such, when you run the `make` command inside of make, you can use the `export` directive to make it accessible to sub-make commands. In this example, `cooly` is exported such that the makefile in subdir can use it.

```make
new_contents = "hello:\n\techo \$$(cooly)"

all:
    mkdir -p subdir
    printf $(new_contents) | sed -e 's/^ //' > subdir/makefile
    @echo "---MAKEFILE CONTENTS---"
    @cd subdir && cat makefile
    @echo "---END MAKEFILE CONTENTS---"
    cd subdir && $(MAKE)

# Note that variables and exports. They are set/affected globally.
cooly = "The subdirectory can see me!"
export cooly
# This would nullify the line above: unexport cooly

clean:
    rm -rf subdir
```

You need to export variables to have them run in the shell as well.

```make
one=this will only work locally
export two=we can run subcommands with this

all: 
    @echo $(one)
    @echo $$one
    @echo $(two)
    @echo $$two
```

`.EXPORT_ALL_VARIABLES` exports all variables for you.

```make
.EXPORT_ALL_VARIABLES:
new_contents = "hello:\n\techo \$$(cooly)"

cooly = "The subdirectory can see me!"
# This would nullify the line above: unexport cooly

all:
    mkdir -p subdir
    printf $(new_contents) | sed -e 's/^ //' > subdir/makefile
    @echo "---MAKEFILE CONTENTS---"
    @cd subdir && cat makefile
    @echo "---END MAKEFILE CONTENTS---"
    cd subdir && $(MAKE)

clean:
    rm -rf subdir
```

### Arguments to make

There's a nice list of options that can be run from make. Check out `--dry-run`, `--touch`, `--old-file`.

You can have multiple targets to make, i.e. make clean run test runs the clean goal, then run, and then test.
