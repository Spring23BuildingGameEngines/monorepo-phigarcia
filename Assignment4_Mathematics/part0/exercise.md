1. In C++ what are two instances where you would use the keyword const?

*You use const when you know a variable should not be changed. You can use const for something like an array of directions a character can walk (up, left, down, right) or for an object that has a set size.*

2. What does 'inline' do? Why might a programmer use it? Why might a programmer choose not to use inline?

*Inline tells the compiler to substitute the code for every instance of a function call. A programmer may use it to improve the speed of their code and execution time. A programmer may not choose to use it when a function is large, because in that case it may reduce the efficiency of the code; The inline function duplicates the code at every call site. You also cannot step into the function with a debugger if it is inline.*

3. Why do you think [TinyMath.hpp](./TinyMath.hpp) is implemented as a header only library? 

*There are a lot of functions that are inline in that header, so TinyMath.hpp is implemented as a header-only library because the compiler needs to have the code in order to inline it.*

4. What is the difference between a shared_ptr and a unique_ptr?

*Both of these are smart pointers, but shared_ptr is used when you want multiple pointers to point to the same resource and unique_ptr is used when you want a single pointer to an object that can be reclaimed when the single pointer is destroyed.*

5. Do you think you should ever use absolute file paths in a project you distribute to others? 

*No, because others will not have the exact same directory structure and naming schemes as you do.*

6. What is the difference between static and dynamic linking?

*Static linking happens during compilation, and dynamic linking happens when the program runs. Static linking means you only receive one .exe and need to recompile your entire program for a single change to relink the whole program.*

7. If I get an 'undefined reference' or 'unresolved external symbol', do you think that is a compiler error (something wrong in your code) or a linker error (some missing external dependency)? 

*This is a linker error, it happens when the linker cannot find those functions or globals.*
