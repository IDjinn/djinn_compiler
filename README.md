# Djinn Compiler

A general purpose compiler for the djinn language. Write a high-level language in djinn and compile it to a c++ code.

##### Code Examples

This is some short code examples what will have in near future.

```c++
    import { print } from "system";

    public f void main(string[] args) {
        print("Hello world!");
    }
```

```c++
    public static Math {
        uint32 add(uint32 a, uint32 b) => a + b;
    }
```

```c++
    import {net} from "system";

    // type inference
    urls = [
        "https://www.google.com",
        "https://www.youtube.com",
        "https://www.facebook.com",
    ];
    
   [async] void fetchParallelAsync() parallel(urls) => net.get(this);
   
   void fetchParallelSync(){
       // this will await for all the requests to finish
       parallel await fetchParallelAsync();
   }
   
   void doStuffAsync(){
       // spawn a new thread to do each stuff
       // this will not wait for the thread to finish
       run parallel async {
           db.save(data);
           db.update(otherData);
           db.delete(someData);
       };
       
       // same as above but will await all until finished (without parallel keywork, this run sequential)
       await run {
           db.save(data);
           db.update(otherData);
           db.delete(someData);
       };
   }
```

```c++
    void someMethod() try { // method scoped try catch
this.throwException();
} or {
print("This is a catch block");
};

void throwException(){
throw 'This is a throwable';
}

void cPlusPlusCode() cpp {
// your c++ code here
}
```

```c++
    // variables lifetime
void someMethod() {
var a = 1;
var b = 2;
var c = a + b;

// stack-based var is destroyed as expected
}


void someMethod() {
object someObject = new object();
object secondObject = new object();

doSomething(secondObject); // secondObject now is part of doSomething's scope
// free(secondObject);
// free(someObject);
}
```