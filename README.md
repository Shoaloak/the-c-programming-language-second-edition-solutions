# Solutions for "The C Programming Language, second edition"
Also known by the authors initials, K&R.

All solutions will be compiled with --ansi and written in K&R style.

first.c is my first attempt, so those sources can probably be improved.

## Debugging
To debug C programs, try GDB: The GNU Project Debugger.
start with quit option to disable GPL disclaimer.
```
alias gdb="gdb -q"
```

```
GDB commands:
----------------------------------------------------------------------
stop gdb:                       quit (or q)
run program with break @ main:  start
(re)run program:                run (or r)
set breakpoint:                 break (or b) [file:] function
set temp breakpoint:            tbreak function
remove breakpoints:             disable
next instruction:               next (or n)
show source code                list [file:] function (or line number)
<enter>:                        execute previous gdb command
continue after breakpoint:      continue (or c)
print (and set) var:            print variable name [= value] 
print inscope vars:             info locals
print breakpoints:              info breakpoints
run make                        make
```

### Try TUI (Text User Interface) mode in GDB:
```
inside GDB, hit Ctrl+x a
if e.g. printf messes up screen, hit Ctrl-l to repaint.

ctrl+x 2 to create extra window with asm
ctrl+x 1 to cycle back, ctrl+x2 to cycle forward
ctrl+n or ctrl+p to cycle through previous commands
```

### GDB (>= 7) has Python!
```
(gdb) python
>import os
>print('my pid is {}'.format(os.getpid()))
>end
```
