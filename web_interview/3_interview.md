# JAVASCRIPT

# How many different types of js..?
```
  1. Primitive-data type:- [boolean, string, bigInt, NULL, undefined, number, symbol].

  2. Non-Primitive:- [Object:- Used to store collection of data].
```

# Explain hoisting in js.?
```
  => This is default behaviour of js in which declaration of function and its variable are moved to top. [function and var only]

  How can Avoid this default behaviour.?
    :- We can avoid using "use strict"
```

# Why we use word "debugger" in js.?
```
  :- The word debugger allows developer to pinpoint to stop execution after this pinpoint and run step by step to debug your code for finding error or runtime error this make easier to find bug in code.
```

# What is NaN property in JavaScript?
```
  :- NaN stands for not-a-number value it indicates that it is not a legal number, but typeof NaN is a number to check is NaN is the number we use isNaN() function.
  Note- isNaN() function converts the given value to a Number type, and then equates to NaN.
  
  Working of NaN:- when we pass a number in the form of string and a number it will return false but when we pass a anything which is not a number then it will return true.

  Ex: let a = isNaN("hello");
      console.log(a); // it return true
      let b = isNaN("123");
      console.log(b); // it return false
```

# Explain passed by value and passed by reference.
```
  :- When we pass a variable inside the function it will pass by value no matter what you doing or fliping the value of that variable inside the func it will not affect the value of that variable outside the function,
  OR
  but when we pass a object inside the function it pass by reference whatever you change inside the function it will affect your original value of object outside the function.
```

# Immediate invoked function in javascript?
```
  Those function which can execute immediately after the declaration of function.
  There are two types to parenthesis
  1. Ex:
    let a = (function print() {
        console.log("hello world");
    }) ();
  This function doesn't return anything 'a' will be undefined.
  The above function execute immediately and not return its declaration.
  
  2. Ex:
    let a= (function(){
        console.log("hello");
    });
  It returns a declaration of function it not execute immediately this invoked function.
```

# Strict mode in js?
```
  A new js feature is javascript strict mode allow us to write code in strict environment in which a small error is not negligible even if you use javascript keyword anywhere like declare a variable with js keyword it show error and create a function with the name of js keyword then it also show error but this is a good practice to write code in strict environment it helps in debugging.

  It helps to write clean code.
  It helps in debugging.
  It also catch silent error.
  You can't use variable before the declaration.
  It also enhanced performance.

  Ex:
    function arguments() {
        console.log("hello");
    }
    arguments();
    // Not show error but arguments is a reserved keyword.

    "use strict";
    function arguments() {
        console.log("hello");
    }
    arguments();
    // It show error we can declare a function name with javascript reserved keyword.
```

# What are high order function.?
```
  High order fn is a special type of function which can take a another fn as an arguement stores the reference of another function.
  Ex:
    function fn(f){
      f();
    }
    function f(){
      console.log("Hello World!");
    }
```