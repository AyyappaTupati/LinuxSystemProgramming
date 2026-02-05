# LinuxSystemProgrammin
This Repo is having the Basic understanding of the linux system programming concepts.
D: Feb 5 26
- created a static library and taken a smaple fuctions like sum,sub,mul,mod,div each functio is like a file.make them as a static library objec files using the gcc compilation
- gcc -c sum.c -o sum.o like this all the files are created.
- for generation the static library we have to make them as a archive file or .a files.
- ar -rcsv libAirth.a sum.o sub.o mul.o mod.o div.o
- to get compile we use the **gcc program.c libAirth.a**

coming to dynamic library we have two types 
- Dynamic Load time linking and another one is dynamic runtime linking i love this one.
- to creat dynamic loadt time linking lib file we use below command.
- gcc -c -fpic sum.c this will creat exacutable sum.o not a object file, why because the dynamic load time linikng is not copy the reference it loads the object files into ram during execution.
- Correction: sum.o is still an object file, not an executable. You cannot run ./sum.o.
  Without -fpic: The compiler assumes the code will be loaded at a specific address (absolute addressing).
  With -fpic (Position Independent Code): The compiler generates code that accesses data via "offsets" (relative addressing) using the Global Offset Table (GOT).     This allows the OS to load the library anywhere in the RAM, which is mandatory for shared libraries.
  
- to creat a library use gcc -shared -o libAirth.so sum.o mul.o sub.o mod.o div.o
- this will creat the dynamic load time linkable library file.
- to generat a.out use gcc program.c ./libAirth.so

- And in dynamic run time linking the calling library file is loaded into ram when it is called and unload from the ram when the job is completed.
- Here no wastage of the RAM space and it spped up the execution.
- for this we need a dynamic library and below kernel subroutines.
- dlopen();
- dlclose();
- dlsym();
- dlerror();
- these are used to call the specific function in a dynamic library.These uses function pointers to handle the situation.
gcc main.c -ldl -o dynamic_loader

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h> // Required for dlopen, dlsym, etc.

int main() {
    void *handle;
    int (*add_func)(int, int); // Function Pointer declaration
    char *error;

    // 1. Load the library into RAM
    handle = dlopen("./libAirth.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    // 2. Clear any existing errors
    dlerror();

    // 3. Find the address of the "sum" function and assign it to our pointer
    // dlsym returns a void*, so we cast it to our function pointer type
    *(void **) (&add_func) = dlsym(handle, "sum");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    // 4. Call the function using the pointer
    printf("Sum: %d\n", (*add_func)(10, 20));

    // 5. Unload the library from RAM (freed memory!)
    dlclose(handle);

    return 0;
}
