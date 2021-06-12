# LinkedList Library

This library allows you to create and manipulate any linked list.

# Requires
## Commands
* make
* gcc
* gcovr
## Dependencies
* criterion

# Makefile Recipes
* all / liblinkedlist.a
> To compile the program.
* clean
> To delete temporary files.
* fclean
> To delete temporary files and executables.
* re
> Delete temporary files and executables and compile the program.
* tests_run
> Run unit tests
* coverage
> Allows you to see the coverage processed by unit tests.

# Examples
```c
int main(void)
{
    list_t list = 0;
    char *str1 = "Test1";
    char *str2 = "Test2";
    char *str3 = "Test3";
    char *str4 = "Test4";
    char *str5 = "Test5";
    
    list_add(&list, str1);
    list_add(&list, str2);
    list_add(&list, str3);
    list_add(&list, str4);
    list_add(&list, str5);
    
    printf("total: %lu\n", list_count(list));
    LIST_FOREACH(list, element) {
        printf("%s\n", element);
        list_remove(&list, element);
    }
}
```

#### output:
```txt
total: 5
Test1
Test2
Test3
Test4
Test5
```
