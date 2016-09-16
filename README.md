#Facile Interpreter

Qt in which the user can interact with the graphical debugger. The user
starts off with a load window in which he/she is asked to input in a input
file. When inputted correctly, the user is going to see a facile debugger in
which there would be buttons: breakpoint, continue, step, next, inspect, and
quit. The debugger window is also going to show a scrolling box in which it
shows all the contents of the file.

Breakpoint: adds a breakpoint to the selected line; the line would be highlighted.
To delete that breakpoint, click on the line with the breakpoint, and press breakpoint again.

Continue: causes program to intrepret until reach a breakpoint; waits for further user input

Step: interpreter advances one line of code and waits for further user input

Next: works like the step button, but on a GOSUB line, it interprets until it returns from the
GOSUB call or reaches a breakpoint

Inspect: a values window opens, inspect is explained below

Quit: program ends

When the user presses the inspect button, it would open another window:
values window. This window would display the current values of the variables.
There would be two buttons: one that hides and one that would update the values window.
There are also four radio buttons in which that would allow the user to see the different
sorting options. The MergeSort function is implemented here.

To compile and run:
qmake
make
./debugger(executable)
