## 什么是shell？
> 你必须要『输入』一个命令之后， 『硬件』才会透过你下达的命令来工作！那么硬件如何知道你下达的命令呢？那就是 kernel (核心) 的控制工作了！也就是说，我们必须要透过『 Shell 』将我们输入的命令与 Kernel 沟通，好让 Kernel 可以控制硬件来正确无误的工作

## 目前有多少可以用的shell？
> /etc/shells这个文件保存着可以用的shell
* /bin/sh (已经被 /bin/bash 所取代)
* /bin/bash (就是 Linux 默认的 shell) <重点学习>
* /bin/ksh (Kornshell 由 AT&T Bell lab. 发展出来的，兼容于 bash)
* /bin/tcsh (整合 C Shell ，提供更多的功能)
* /bin/csh (已经被 /bin/tcsh 所取代)
* /bin/zsh (基于 ksh 发展出来的，功能更强大的 shell)
