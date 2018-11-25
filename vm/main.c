#include "executable.h"
#include "heap.h"
#include "opcode.h"
#include "vm.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const* argv[])
{
    // char exe[] = {
    //     39, 0, 0, 0, // PROGRAM START POS
    //     49, 0, 0, 0,
    //     // CONSTANTS
    //     6, 0, // LEN
    //     72, 101, 108, 108, 111, 32, // STR VAL
    //     6, 0, // LEN
    //     119, 111, 114, 108, 100, 33, // STR VAL
    //     0, 0, // NEW LEN
    //     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // FUTURE STR VAL
    //     // PROGRAM START
    //     OP_I_PUSH, 0, 0,
    //     OP_I_PUSH, 8, 0,
    //     OP_S_CAT, 16, 0,
    //     OP_S_PRINT, 16, 0,
    //     OP_HALT
    // };

    char exe[] = {
        54, 0, 0, 0, 0, 0, 0, 0, // EXE LEN
        8, 0, 0, 0, 0, 0, 0, 0, // CONSTS LEN
        // CONSTANTS
        1, 0, 2, 0,
        3, 0, 4, 0,
        // PROGRAM START
        OP_I_PUSH, 0, 5, 0, // PUSH
        OP_CALL, 0,
        18, 0, 0, 0, // FUN ADDR
        1, 0, // NUM ARGS
        OP_PRINT, 0,
        OP_HALT, 0, 3, 0,
        OP_LOADARG, 0, 0, 0,
        OP_I_PUSH, 0, 2, 0,
        OP_I_ADD, 0,
        OP_RETURN, 0
    };

    EXECUTABLE executable = executable_from(&exe);
    HEAP       heap       = heap_from(executable.constants, 10);
    heap_dump(heap);
    // VM vm = vm_create(executable);

    // int16_t exit_code = vm_run(&vm);
    // vm_free(vm);

    // return exit_code;
    return 0;
}
