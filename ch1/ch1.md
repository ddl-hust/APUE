- 登入操作系统时候， 会去检查 /etc/passwd 口令，其中最后一项指定了登入操作系统之后，执行哪一个shell 

- 标准IO函数为那些不带缓冲的IO函数提供了一个带缓冲的接口， 比如putc() getc()

- getpid() 返回类型为标准pid_t 我们不知道大小，但是知道标准保证了它能够存在一个长整型中。 因此在printf() 输出时候 会看到如下的类型转化
`printf("the current process ID: %ld\n",(long)getpid())`


- execlp 参数
函数原型如下
int execlp(const char *file, const char *arg, ... /* (char  *) NULL */);

有几个注意点
1. 参数必须以null 结尾

2. argv[0] 默认为文件名，因此常见的一个execlp格式可能是这样的 `execlp("ls","ls",(char*)o)` 其中第一个ls 指明了文件名， 第二个指明了函数参数列表的第一个参数（即文件名）

**错误处理**

1. errno value is never cleared by a routine if an error does not occur. Therefore, we should examine its value
only when the return value from a function indicates that an error occurre
2. the value of errno is never set to 0 by any of the functions, and none of the constants defined in <errno.h> has a value of 0.

```c
int main(int argc, char*argv[]){
    fprintf(stderr, "EACESS :%s \n",strerror(EACCES));
    errno=ENOENT;
    perror(argv[0]); //设置了errno 之后perror解释了当前errno的含义
    exit(0);

}
```

其中perror传入参数为程序名，这么做的是一种约定俗成做法，比如在shell 管道调用中`prog1 < inputfile | prog2 | prog3 > outputfile` 可以知道是哪一个程序除了问题，便于故障排查。

---


- 用户id ,组id使用整型原因
    - 省空间
    - 方便做权限比较

系统调用和标准库函数区别
> system calls usually provide a minimal interface, whereas library functions often provide more elaborate functionality.



### 课后习题

1.2 重复运行同一个程序， 当前pid号不一样，并且pid分配不连续

1.3 strerror() 参数带了const, perror()参数没有const 属性

strerror传入参数为指针，如果不加const限定，可能在函数内部修改字符串， perror传入参数为整型，按照值传递方式，即使函数内部修改errno也不会影响传入参数的值。