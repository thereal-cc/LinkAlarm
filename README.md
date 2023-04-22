# LinkAlarm

A simple alarm for opening URL's for the command line written in C.

## Installation/Usage  

Here's the general usage:  

``` bash
    ./LinkAlarm --link <URL> --hour <HOUR> --minute <MINUTE> --pm
```

Lets say that I wanted to open [Youtube](https://www.youtube.com) at 5.24 PM.  
Download the source code and navigate to it in your terminal.
From there, run the following commands:  

``` bash
    make
    cd bin
    ./LinkAlarm --link https://www.youtube.com --hour 5 --minute 24 --pm
```

From there, don't close any running instances of LinkAlarm, and the program will wait to open the URL at the specified time.

## TODO  

- [ ] Compile natively for Windows & Linux
- [ ] Easier User Interface
- [ ] Integrate other forms of Time (i.e. Seconds, Days, etc.)

## Bugs/Contributing  

If you find any bugs or have any suggestions, please open an issue or pull request.

## Thank you
