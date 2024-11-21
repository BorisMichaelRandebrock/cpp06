# C++ Module 06 - Scalar Conversion

This module of the **42 C++ curriculum** introduces the concepts of type casting in C++. While the topic is foundational for understanding data transformations and runtime behavior, the exercise 00 in this module is, frankly and in my opinion the most dull, painstaking, and nerve-wracking tasks you may encounter. Each exercise requires meticulous attention to detail and rigorous handling of edge cases. Prepare to be frustrated by the nuances of type conversion as you tackle these challenges!

## Exercises Overview

### Exercise 00: Convert
This exercise is about converting a single input into multiple scalar types: `char`, `int`, `float`, and `double`. Sounds simple? Think again. The task involves handling edge cases such as special floating-point values (`nan`, `inf`), non-displayable characters, and invalid inputs. Each output must be formatted precisely, and you must ensure no undefined behavior occurs. This is a nerve-wracking introduction to the world of scalar conversions and error handling.

### Exercise 01: Static Cast
Here, you’ll dive deeper into type casting by using `static_cast`. Unlike `dynamic_cast`, this conversion does not use runtime type information, meaning it is faster but less safe. You will be tasked with converting between compatible types, all while ensuring that you fully understand the implications of using `static_cast` in both trivial and non-trivial scenarios. Though not as exhaustive as Exercise 00, the monotony here is real.

### Exercise 02: Dynamic Cast
In this final exercise, you’ll explore `dynamic_cast`, which allows for type-safe downcasting of polymorphic classes. You’ll work with inheritance hierarchies and detect invalid casts using the `dynamic_cast` mechanism. Handling pointers and references correctly will be critical, and the exercise emphasizes how type safety can prevent runtime disasters. If you're already tired from the previous exercises, this one might feel like the proverbial straw that breaks the camel’s back.

---

## Examples for Exercise 00: Convert

```./Convert a```       # Expected output:
                  # char: 'a'
                  # int: 97
                  # float: 97.0f
                  # double: 97.0

```./Convert 42```      # Expected output:
                  # char: '*'
                  # int: 42
                  # float: 42.0f
                  # double: 42.0

```./Convert 128```     # Expected output:
                  # char: Non displayable
                  # int: 128
                  # float: 128.0f
                  # double: 128.0

```./Convert -42```     # Expected output:
                  # char: Non displayable
                  # int: -42
                  # float: -42.0f
                  # double: -42.0

```./Convert 2147483647``` # Expected output:
                     # char: Non displayable
                     # int: 2147483647
                     # float: 2147483647.0f
                     # double: 2147483647.0

```./Convert 3.14f```   # Expected output:
                  # char: Non displayable
                  # int: 3
                  # float: 3.14f
                  # double: 3.14

```./Convert 2.718```   # Expected output:
                  # char: Non displayable
                  # int: 2
                  # float: 2.718f
                  # double: 2.718

```./Convert nanf```    # Expected output:
                  # char: imposible
                  # int: imposible
                  # float: nanf
                  # double: nan

```./Convert +inff```   # Expected output:
                  # char: imposible
                  # int: imposible
                  # float: +inff
                  # double: +inf

```./Convert -inf```    # Expected output:
                  # char: imposible
                  # int: imposible
                  # float: -inf
                  # double: -inf

```./Convert z```       # Expected output:
                  # char: 'z'
                  # int: 122
                  # float: 122.0f
                  # double: 122.0

```./Convert 0```       # Expected output:
                  # char: Non displayable
                  # int: 0
                  # float: 0.0f
                  # double: 0.0

```./Convert 7```       # Expected output:
                  # char: Non displayable
                  # int: 7
                  # float: 7.0f
                  # double: 7.0

```./Convert 340282346638528859811704183484516925440.0f``` # Expected output:
                                                    # char: imposible
                                                    # int: imposible
                                                    # float: +inf
                                                    # double: 3.402823466e+38

```./Convert Hello```   # Expected output:
                  # char: imposible
                  # int: imposible
                  # float: imposible
                  # double: imposible

